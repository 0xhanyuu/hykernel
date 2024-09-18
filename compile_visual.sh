#!/bin/bash

pwd > $HOME/hykernel_directory
hykd=$(cat $HOME/hykernel_directory)

gcc $hykd/hcvtslib/src/hcvtslib.c $hykd/src/hykernel.c $hykd/src/main.c -o $hykd/bin/main
