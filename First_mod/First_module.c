#include<linux/module.h>
#include<linux/version.h>
#include<linux/kernel.h>


static int __init firstentry()
{
    printk(KERN_INFO "just a hello World: Registration");
return 0;

}

static void __exit firstexit()
{
printk(KERN_INFO "Good Bye Hello World : Unregistered");

}

module_init(firstentry);
module_exit(firstexit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MALLI FROM L4u");
MODULE_DESCRIPTION("JUST A HELLO_WORLD MODULE");









