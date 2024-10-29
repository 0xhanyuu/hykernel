#include "hyk_enums.h"

#pragma once

void print_hykernel();
void e_print_hykernel();

void output_help();

void run_command(e_command current_command);
e_command get_command(char **argv);
