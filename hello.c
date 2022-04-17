#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");

static int year = 2022;

int hello_init(void)
{
    printk(KERN_WARNING "Hello kernel, it's %d!\n", year);
    return 0;
}

void hello_exit(void)
{
    printk("Bye, kernel!\n");
}

module_init(hello_init);
module_exit(hello_exit);
