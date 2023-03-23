#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "my_object.h"


//-----------------------------------------------------------
bool my_object_init(my_object *self, size_t len)
{
    self->len = len;

    self->str = malloc(self->len);
    
    return (bool)(self->str);
}

//-----------------------------------------------------------
void my_object_deinit(my_object *self)
{
    self->len = 0;

    free(self->str);
    self->str = NULL;
}

//-----------------------------------------------------------
bool my_object_write(my_object *self, const char *str, size_t len)
{
    if (len >= self->len || !str || !len)
        return false;
    
    return (bool)(snprintf(self->str, len, "%s", str));
}

//-----------------------------------------------------------
const char* my_object_read(my_object *self)
{
    return self->str;
}