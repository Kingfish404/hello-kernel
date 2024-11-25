#include <stdint.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/syscall.h>

#define IOCTL_DEVICE_NAME "ioctl"
#define IOCTL_DEVICE_PATH "/dev/" IOCTL_DEVICE_NAME

#define IOCTL_MAGIC_NUMBER (long)0xbeef

static int kernel_cc_fd;

int main(int argc, char const *argv[])
{
    kernel_cc_fd = open(IOCTL_DEVICE_PATH, O_RDONLY);
    if (kernel_cc_fd < 0)
    {
        printf("Failed to open %s\n", IOCTL_DEVICE_PATH);
        return -1;
    }

    int ret = 0;

    for (size_t i = 0; i < 5; i++)
    {
        size_t request = _IOR(IOCTL_MAGIC_NUMBER, i, size_t);
        ret = ioctl(kernel_cc_fd, _IOR(IOCTL_MAGIC_NUMBER, request, size_t), 0);
#ifdef __x86_64__
        // https://gpages.juszkiewicz.com.pl/syscalls-table/syscalls.html
        ret = syscall(16, kernel_cc_fd, request, 0);
#elif defined(__aarch64__) || defined(__riscv)
        ret = syscall(29, kernel_cc_fd, request, 0);
#endif
        printf("ioctl(%lx) (raw: %lx) = %d\n", request, i, ret);
    }

    if (kernel_cc_fd >= 0)
    {
        close(kernel_cc_fd);
    }
    return 0;
}
