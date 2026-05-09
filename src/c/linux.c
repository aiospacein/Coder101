#include <linux/module.h>
#include <linux/kernel.h>
#define MODULE

int init_module()
{
    printk("<1> Module Init");
    return 0;
}

int cleanup_module()
{
    printk("<1> Module Exit");
    return 0;
}