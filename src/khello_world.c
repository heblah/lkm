/*
 * Experimenting a simple loadable kernel module
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("BSD");
MODULE_AUTHOR("halvarez");
MODULE_DESCRIPTION("kernel hello world");
MODULE_VERSION("0");

static char *name = "world";
module_param(name, charp, S_IRUGO);

static int __init helloKern_init(void)
{
	printk(KERN_INFO "Kernel: Hello %s from a ft_lkm\n", name);
	return 0;
}

static void __exit helloKern_exit(void)
{
	printk(KERN_INFO "Kernel: good bye ft_lkm\n");
	return 0;
}

module_init(helloKern_init);
module_exit(helloKern_exit);
