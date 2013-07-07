#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/types.h>
#include<linux/kdev_t.h>

static dev_t first; // Global variable for the first device number
 
static int __init charRegEntry(void) /* Constructor */
{
    printk(KERN_INFO "Char Registration Step 1");
    if (alloc_chrdev_region(&first, 0, 3, "Shweta") < 0)
    {
        return -1;
    }
    printk(KERN_INFO "<Major, Minor>: <%d, %d>\n", MAJOR(first), MINOR(first));
    return 0;
}
 
static void __exit charRegExit(void) /* Destructor */
{
    unregister_chrdev_region(first, 3);
    printk(KERN_INFO "Ba Bye.....");
}
 
module_init(charRegEntry);
module_exit(charRegExit);
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Malli");
MODULE_DESCRIPTION("First Char reg by alloc_chrdev");
