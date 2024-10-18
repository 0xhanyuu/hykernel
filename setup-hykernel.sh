#!/bin/bash

DEFAULT="\e[0m"
BOLD="\e[1m"

echo -e "creating hykernel_directory file ..."
pwd > $HOME/hykernel_directory
hykd=$(cat $HOME/hykernel_directory)
cp $HOME/hykernel_directory ./hykernel_directory

echo -e "compiling hykernel ..."
make

echo -e -n "creating symbolic link to ${BOLD}/bin/hykernel${DEFAULT} "
echo -e    "from ${BOLD}$hykd/bin/hykernel${DEFAULT} ..."

sudo ln -s $hykd/bin/hykernel /bin/hykernel

echo -e "done!\n"
