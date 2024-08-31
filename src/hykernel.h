#pragma once

int file_error();

void print_hykernel();

int check_validity(char * input_string);

int file_handling(int argc, char **argv);

enum command get_command(int argc, char **argv);

void run_command(enum command current_command);
