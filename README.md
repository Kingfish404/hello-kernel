# Hello Kernel Driver

2022年最简规范的Linux Kernel Driver构建样例。

## Use

```shell
make all        # 编译驱动
make insmod     # 插入驱动
make rmmod      # 移除驱动
make kern_log   # 查看内核日志
# [DATE] [COMPUTER_NAME] kernel: [90704.319340] Hello kernel, it's [year]!
# [DATE] [COMPUTER_NAME] kernel: [90724.191131] Bye, kernel!
```

## Reference

- [Ubuntu12.10 内核源码外编译 linux模块--编译驱动模块的基本方法](https://www.cnblogs.com/QuLory/archive/2012/10/23/2736339.html)
- [Linux Kernel Makefiles — The Linux Kernel  documentation](https://docs.kernel.org/kbuild/makefiles.html)
- [Linux 内核驱动接口 — The Linux Kernel  documentation](https://docs.kernel.org/translations/zh_CN/process/stable-api-nonsense.html)
