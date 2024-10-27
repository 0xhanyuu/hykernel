#!/bin/bash

DEFAULT="\e[0m"
BOLD="\e[1m"

hykd=$(pwd)

print_hykernel() {
    echo -e -n "${BOLD}[hykernel]:${DEFAULT} "
}

custom_kd='/etc/opt/hykernel/kernel_list'
user_input='\x00'

print_hykernel && echo -n "Creating config directory in "
                  echo -e "${BOLD}/etc/opt/hykernel/config${DEFAULT}..."
sudo mkdir -p /etc/opt/hykernel/config/

print_hykernel && echo "Creating config file..."

if [[ ! -e /etc/opt/hykernel/config/config ]]; then
	sudo touch /etc/opt/hykernel/config/config
else
	print_hykernel && echo -e -n "${BOLD}/etc/opt/hykernel/config/config${DEFAULT} " 
                            echo "file exists! Skipping ..."
fi

print_hykernel && echo "Use custom kernel directory? (Default = 'n') [y/n]"
read -p "> " user_input

if [[ $user_input =~ ^[Yy]([Ee][Ss]?)?$ ]]; then
	print_hykernel && echo "Input custom kernel directory: "
	read -p "> " custom_kd
elif
	[[ $user_input =~ ^[Nn][Oo]?$ || $user_input == "" ]]; then
	print_hykernel && echo -n "Creating default hykernel directory in "
	                  echo -e "${BOLD}/etc/opt/hykernel${DEFAULT}..."
	sudo mkdir -p /etc/opt/hykernel/kernel_list
fi

print_hykernel && echo -e "Compiling hykernel ..."
make

if [[ ! -e /bin/hykernel ]]; then
    print_hykernel && echo -e -n "Creating symbolic link to ${BOLD}/bin/hykernel${DEFAULT} "
                      echo -e    "from ${BOLD}$hykd/hykernel${DEFAULT}..."
    sudo ln -s "$hykd/main" /bin/hykernel
else
    print_hykernel && echo -e "Symbolic link ${BOLD}/bin/hykernel${DEFAULT} already exists, skipping ..."
fi

echo "Appending information to config file..."

echo "hykernel_directory=$hykd" | sudo tee /etc/opt/hykernel/config/config > /dev/null
echo "kernel_directory=$custom_kd" | sudo tee -a /etc/opt/hykernel/config/config > /dev/null

print_hykernel && echo -e "Installation finished."
print_hykernel && echo -n "Your configuration file can be found at "
                  echo -e "${BOLD}/etc/opt/hykernel/config/config${DEFAULT}."
print_hykernel && echo -n "Your kernel directory can be found at "
                  echo -e "${BOLD}$custom_kd${DEFAULT}."

