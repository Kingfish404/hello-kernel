#include <linux/kernel.h>
#include <linux/miscdevice.h>
#include <linux/version.h>

#define CC_DEVICE_NAME "ioctl"
#define IOCTL_MAGIC_NUMBER (long)0xbeef

MODULE_LICENSE("GPL");

int ioctl_init(void);
void ioctl_exit(void);

static bool device_busy = false;

static int device_open(struct inode *inode, struct file *file)
{
    /* Check if device is busy */
    if (device_busy == true)
    {
        return -EBUSY;
    }

    device_busy = true;

    return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
    /* Unlock module */
    device_busy = false;

    return 0;
}

static long device_ioctl(struct file *file, unsigned int ioctl_num, unsigned long ioctl_param)
{
    switch ((size_t)ioctl_num)
    {
    case _IOR(IOCTL_MAGIC_NUMBER, 0, size_t):
        printk(KERN_WARNING "Hello ioctl 0!\n");
        break;
    case _IOR(IOCTL_MAGIC_NUMBER, 1, size_t):
        printk(KERN_WARNING "Hello ioctl 1!\n");
        break;
    default:
        printk(KERN_WARNING "Unknown ioctl %lx\n", ioctl_num);
        break;
    }
    return 0;
}

static struct file_operations f_ops = {.owner = THIS_MODULE,
                                       .unlocked_ioctl = device_ioctl,
                                       .open = device_open,
                                       .release = device_release};

static struct miscdevice misc_dev = {
    .minor = MISC_DYNAMIC_MINOR,
    .name = CC_DEVICE_NAME,
    .fops = &f_ops,
    .mode = S_IRWXUGO,
};

int ioctl_init(void)
{
    int r;
    /* Register device */
    r = misc_register(&misc_dev);
    if (r != 0)
    {
        pr_alert("Failed registering device with %d\n", r);
        return -ENXIO;
    }

    return 0;
}

void ioctl_exit(void)
{
    misc_deregister(&misc_dev);
}

module_init(ioctl_init);
module_exit(ioctl_exit);
