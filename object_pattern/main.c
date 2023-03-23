#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_object.h"


int main()
{
    my_object obj1;

    if (!my_object_init(&obj1, 80))
    {
        printf("%s\n", "memory allocation error");
        exit(1);
    }

    bool test = my_object_write(&obj1, "hello world", strlen("hello world"));
    if (!test)
    {
        printf("%s\n", "cannot write to an object");
        exit(1);
    }


    
    printf("%s\n", my_object_read(&obj1));

    my_object_deinit(&obj1);


    return 0;
}