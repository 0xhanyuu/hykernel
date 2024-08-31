#!/bin/bash

DEFAULT="\e[0m"
BOLD="\e[1m"

# Change this to true to install the visual hykernel interface
VISUAL_HYKERNEL=false

echo -e "creating hykernel_directory file ..."

pwd > $HOME/hykernel_directory
hykd=$(cat $HOME/hykernel_directory)

echo -e "compiling hykernel ..."

./$hykd/compile.sh

if [[ VISUAL_HYKERNEL == true ]]
then
	echo -e "compiling visual hykernel ..."
	gcc $hykd/src/hykernel.visual.c -o $hykd/bin/hykernel
fi

echo -e -n "creating symbolic link to ${BOLD}/bin/hykernel${DEFAULT} "
echo -e    "from ${BOLD}$hykd/bin/hykernel${DEFAULT} ..."

sudo ln -s $hykd/bin/hykernel /bin/hykernel

echo -e "done!\n"

echo -e -n "${BOLD}[hykernel]${DEFAULT} "
cat $hykd/info/hykernel.version
