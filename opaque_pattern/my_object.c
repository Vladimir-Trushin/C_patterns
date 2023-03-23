#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "my_object.h"


typedef struct my_object
{
    size_t len;
    char *str;

} my_object;

//-----------------------------------------------------------
my_object *my_object_init(size_t len)
{
    my_object *obj = malloc(sizeof(my_object));
    if (!obj)
        return NULL;

    obj->str = malloc(len * sizeof(char));
    if (!obj->str)
    {
        free(obj);
        return NULL;
    }

    obj->len = len;


    return obj;
}

//-----------------------------------------------------------
void my_object_deinit(my_object **self)
{
    free((*self)->str);
    free(*self);
    *self = NULL;
}

//-----------------------------------------------------------
bool my_object_write(my_object *self, const char *str, size_t len)
{
    if (len >= self->len || !str || !len)
        return false;

    return (bool)(snprintf(self->str, len, "%s", str));
}

//-----------------------------------------------------------
const char *my_object_read(my_object *self)
{
    return self->str;
}