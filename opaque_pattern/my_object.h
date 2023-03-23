#ifndef MY_OBJECT
#define MY_OBJECT

#include <stddef.h>
#include <stdbool.h>


typedef struct my_object my_object;


my_object *my_object_init(size_t len);
void my_object_deinit(my_object **self);
bool my_object_write(my_object *self, const char *str, size_t len);
const char* my_object_read(my_object *self);

#endif