#!/bin/bash

DEFAULT="\e[0m"
BOLD="\e[1m"

hykd=$(cat $HOME/hykernel_directory)

echo -e    "removing ${BOLD}$hykd/bin/hykernel${DEFAULT} ..."
sudo rm $hykd/bin/hykernel

# If VISUAL_HYKERNEL=true, remove it
if [[ $(cat setup-hykernel.sh | grep VISUAL | head -n 1 | cut -c17-) == true ]]
then
	echo -e "removing ${BOLD}$hykd/bin/hykernel_visual${DEFAULT} ..."
	sudo rm $hykd/bin/hykernel_visual
fi

echo -e    "removing ${BOLD}$home/hykernel_directory${DEFAULT} ... \n"
rm $HOME/hykernel_directory

echo -e    "removing symlink to ${BOLD}/usr/src/linux${DEFAULT} ... \n"
rmdir /usr/src/linux
