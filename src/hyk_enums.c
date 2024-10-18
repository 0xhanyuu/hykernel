#include <stdio.h>
#include <stdlib.h>

enum command
{
    nop = 0,

    list,
    set,
    show,
    sanity_check,
    version,
    help,
};
