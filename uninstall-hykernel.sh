#!/bin/bash

DEFAULT="\e[0m"
BOLD="\e[1m"

echo -e    "removing ${BOLD}/bin/hykernel${DEFAULT} ..."

sudo rm /bin/hykernel

echo -e    "removing ${BOLD}$home/hykernel_directory${DEFAULT} ... \n"

rm $HOME/hykernel_directory

echo -e    "removing symlink to ${BOLD}/usr/src/linux${DEFAULT} ... \n"

rmdir /usr/src/linux
