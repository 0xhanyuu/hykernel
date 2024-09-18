#!/bin/bash

DEFAULT="\e[0m"
BOLD="\e[1m"

# Change this to true to install the visual hykernel interface
VISUAL_HYKERNEL=false

echo -e "creating hykernel_directory file ..."

pwd > $HOME/hykernel_directory
hykd=$(cat $HOME/hykernel_directory)

if [[ VISUAL_HYKERNEL == false ]]
then
	echo -e "compiling hykernel ..."
	./$hykd/compile.sh
fi

if [[ VISUAL_HYKERNEL == true ]]
then
	echo -e "compiling visual hykernel ..."
	./$hykd/compile_visual.sh

	echo -e "cloning hcvtslib ..."
	git clone https://github.com/0xhanyuu/hcvtslib.git


fi

echo -e -n "creating symbolic link to ${BOLD}/bin/hykernel${DEFAULT} "
echo -e    "from ${BOLD}$hykd/bin/hykernel${DEFAULT} ..."

sudo ln -s $hykd/bin/hykernel /bin/hykernel

echo -e "done!\n"

echo -e -n "${BOLD}[hykernel]${DEFAULT} "
cat $hykd/info/hykernel.version
