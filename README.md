# Hello Kernel Module

The simplest kernel module following the specification of the Linux Kernel documentation.

## Use

```shell
sudo apt-get install linux-headers-$(uname -r)  # install kernel headers for debian based system

sudo yum install kernel-headers-`uname -r`      # install kernel headers for centos based system
sudo yum install kernel-devel-$(uname -r)       # install kernel headers for centos based system

make                    # compile
sudo insmod ./hello.ko  # install module
sudo rmmod hello        # remove module
tail /var/log/kern.log  # check log
# or
dmesg | tail            # check log
# [DATE] [COMPUTER_NAME] kernel: [90704.319340] Hello kernel, it's [year]!
# [DATE] [COMPUTER_NAME] kernel: [90724.191131] Bye, kernel!

make clean
```

## Submodule

- [ioctl](./ioctl) - ioctl system call: for communication between user space and kernel space

## Reference

- [Linux Kernel Makefiles — The Linux Kernel documentation](https://docs.kernel.org/kbuild/makefiles.html)
- [The Linux Kernel Module Programming Guide](https://sysprog21.github.io/lkmpg/)
- [misc0110/PTEditor: A small library to modify all page-table levels of all processes from user space for x86_64 and ARMv8.](https://github.com/misc0110/PTEditor)
