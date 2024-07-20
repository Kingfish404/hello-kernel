# Hello Kernel Module

2024 年最简规范的 Linux Kernel Module 构建样例

## Use

```shell
sudo apt-get install linux-headers-$(uname -r) # 安装内核头文件 (debian 系)

make all        # 编译驱动
sudo insmod ./hello.ko  # 插入驱动
sudo rmmod hello        # 移除驱动
tail /var/log/kern.log  # 查看内核日志
# [DATE] [COMPUTER_NAME] kernel: [90704.319340] Hello kernel, it's [year]!
# [DATE] [COMPUTER_NAME] kernel: [90724.191131] Bye, kernel!
make clean      # 清理编译文件
```

## Reference

- [Linux Kernel Makefiles — The Linux Kernel  documentation](https://docs.kernel.org/kbuild/makefiles.html)
- [The Linux Kernel Module Programming Guide](https://sysprog21.github.io/lkmpg/)
- [Ubuntu12.10 内核源码外编译 linux模块--编译驱动模块的基本方法](https://www.cnblogs.com/QuLory/archive/2012/10/23/2736339.html)
- [Linux 内核驱动接口 — The Linux Kernel  documentation](https://docs.kernel.org/translations/zh_CN/process/stable-api-nonsense.html)
