#!/bin/bash

DEFAULT="\e[0m"
BOLD="\e[1m"

hykd=$(pwd)

custom_kd='/etc/opt/hykernel/kernel_list'
user_input='\x00'

echo -n "creating config directory in "
echo -e "${BOLD}/etc/opt/hykernel/config${DEFAULT} ..."
sudo mkdir -p /etc/opt/hykernel/config/

echo "creating config file ..."

if [[ ! -e /etc/opt/hykernel/config/config ]]; then
	sudo touch /etc/opt/hykernel/config/config
else
	echo -e -n "${BOLD}/etc/opt/hykernel/config/config${DEFAULT} " 
	echo 	   "file exists , skipping ..."
fi

echo "use custom kernel directory ? default = n [y/n]"
read -p "> " user_input

if [[ $user_input =~ ^[Yy]([Ee][Ss]?)?$ ]]; then
	echo "input custom kernel directory: "
	read -p "> " custom_kd
elif
	[[ $user_input =~ ^[Nn][Oo]?$ || $user_input == "" ]]; then
	echo -n "creating default hykernel directory in "
	echo -e "${BOLD}/etc/opt/hykernel${DEFAULT} ..."
	sudo mkdir -p /etc/opt/hykernel/kernel_list
fi

echo -e "compiling hykernel ..."
make

if [[ ! -e /bin/hykernel ]]; then
    echo -e -n "creating symbolic link to ${BOLD}/bin/hykernel${DEFAULT} "
    echo -e    "from ${BOLD}$hykd/hykernel${DEFAULT} ..."
    sudo ln -s "$hykd/main" /bin/hykernel
else
    echo -e "symbolic link ${BOLD}/bin/hykernel${DEFAULT} already exists , skipping ..."
fi

echo "appending information to config file ..."

echo "hykernel_directory=$hykd" | sudo tee /etc/opt/hykernel/config/config > /dev/null
echo "kernel_directory=$custom_kd" | sudo tee -a /etc/opt/hykernel/config/config > /dev/null

echo -e "done !\n"
