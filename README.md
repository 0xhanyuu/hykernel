# hykernel

Utility to make kernel configuration and setup easier on Arch-based distributions.

Inspired by `eselect kernel` found in Gentoo Linux.

## **Setup:**

Run `setup-hykernel.sh`.

This will create a directory in `/etc/opt` called `hykernel`, and will store your installed and configured kernels (`kernel_list/*`) and configuration files (`config/*`), unless specified otherwise.

A symbolic link will be made from your hykernel directory's compiled binary to `/bin/hykernel`.

## **Uninstall:**

Run `uninstall-hykernel.sh`.

This will remove all objects and binaries but will keep your kernel_list directory and your configuration files, unless specified otherwise with the flag `--purge-all`.

**This command will remove everything in `/etc/opt/hykernel`, including the directory itself. Ensure that you have moved your files and backed up what you need before running this command.**

## **Dependencies:**

GNU Coreutils, i.e. `touch`, `mkdir`, `read`, `echo`, `tee`, etc. See commands used in `setup-hykernel.sh`.

Compiler: `gcc`, should be able to be substituted with any other compiler, and can be configured in the Makefile.

## **Notes:**

This project is a work in progress. Some commands still lack functionality.

The default compiler used for this project is `gcc` and may be substituted with any other compiler, as well as other compiler information found in the `Makefile`.
