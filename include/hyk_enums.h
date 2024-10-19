#include <stdio.h>
#include <stdlib.h>

#pragma once

typedef enum
{
    nop = 0,
    list,
    set,
    show,
    sanity_check,
    version,
    help
} e_command;
