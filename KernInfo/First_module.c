#include<linux/module.h>
#include<linux/version.h>
#include<linux/kernel.h>


static int __init firstentry()
{
   //Just picked up the sysinfo struct from linux/kernel.h
   struct sysinfo sys;

   printk(KERN_INFO "Total Ram:%lu",sys.totalram);
   printk(KERN_INFO "Free Ram:%lu",sys.freeram);
   printk(KERN_INFO "Shared Ram:%lu",sys.sharedram);
   printk(KERN_INFO "BUffer Ram:%lu",sys.bufferram);
   printk(KERN_INFO "Total Swap:%lu",sys.totalswap);
   printk(KERN_INFO "Free Swap:%lu",sys.freeswap);
   printk(KERN_INFO "Total high:%lu",sys.totalhigh);
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









