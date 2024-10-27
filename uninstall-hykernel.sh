#!/bin/bash

DEFAULT="\e[0m"
BOLD="\e[1m"

hykd=$(pwd)

print_hykernel() {
    echo -e -n "${BOLD}[hykernel]:${DEFAULT} "
}

config_directory="/etc/opt/hykernel/config/"
config_file="/etc/opt/hykernel/config/config"

hykernel_directory=$(cat "$config_file" | head -n 1 | cut -d'=' -f2)
kernel_directory=$(cat "$config_file" | tail -n 1 | cut -d'=' -f2)

user_input="n"

if [[ "$1" == "--purge-all" ]]; then
    print_hykernel && echo "The following configuration files will be removed:"
    ls "$config_directory"
    print_hykernel && echo "The following kernel files will be removed:"
    ls "$kernel_directory"
    print_hykernel && echo -n "The binaries and objects will be removed in "
                      echo -e "${BOLD}$hykernel_directory${DEFAULT}."
    print_hykernel && echo -n "Are you sure you want to "
                      echo -e "${BOLD}delete${DEFAULT} all of these files? (Default: 'n') [y/n]"
    read -p "> " user_input
    if [[ $user_input =~ ^[Yy]([Ee][Ss]?)?$ ]]; then
        print_hykernel && echo "Removing all configuration directory files..."
        sudo rm -rfv "$config_directory"/*
        print_hykernel && echo "Removing all kernel directory files..."
        sudo rm -rfv "$kernel_directory"/*
        print_hykernel && echo "Removing all binary and object files..."
        make clean
        print_hykernel && echo "Removing all symlinks..."
        sudo rm -rfv /bin/hykernel
        print_hykernel && echo "Purge complete."
        exit 0
    elif [[ $user_input =~ ^[Nn][Oo]?$ || $user_input == "" ]]; then
        print_hykernel && echo "Stopping purge..."
        exit 0
    fi
fi

cd $hykernel_directory

print_hykernel && echo "Removing binaries and objects ..."
make clean
print_hykernel && echo "Removing all symlinks..."
sudo rm -rf /bin/hykernel
