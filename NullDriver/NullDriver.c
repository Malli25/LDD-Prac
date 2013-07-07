#include<linux/module.h>
#include<linux/version.h>
#include<linux/kernel.h>
#include<linux/kdev_t.h>
#include<linux/types.h>
#include<linux/fs.h>
#include<linux/device.h>
#include<linux/cdev.h>

dev_t first;  // Stores Device Numbers Major(first) Minor(first)
static struct cdev c_dev; // Stores Char device Structure
static struct class *cl; // Describes Device class Structure

// File Operations

static int my_open(struct inode *i, struct file *f)
{
  printk(KERN_INFO "Driver: open()\n");
  return 0;
}
static int my_close(struct inode *i, struct file *f)
{
  printk(KERN_INFO "Driver: close()\n");
  return 0;
}
static ssize_t my_read(struct file *f, char __user *buf, size_t
  len, loff_t *off)
{
  printk(KERN_INFO "Driver: read()\n");
  return 0;
}
static ssize_t my_write(struct file *f, const char __user *buf,
  size_t len, loff_t *off)
{
  printk(KERN_INFO "Driver: write()\n");
  return len;
}


// Filling File Operations Structure

static struct file_operations my_fops =
{
  .owner = THIS_MODULE,
  .open = my_open,
  .release = my_close,
  .read = my_read,
  .write = my_write
};

static int __init Nullentry()
{
  printk(KERN_INFO "Welcome to NUll Driver reg");
  if (alloc_chrdev_region(&first, 0, 1, "Malli") < 0)
  {
    return -1;
  } 
    
  if ((cl = class_create(THIS_MODULE, "chardrv")) == NULL)
  {
    unregister_chrdev_region(first, 1);
    return -1;
  }

  if (device_create(cl, NULL, first, NULL, "mynull") == NULL)
  {
    class_destroy(cl);
    unregister_chrdev_region(first, 1);
    return -1;
  }
  cdev_init(&c_dev, &my_fops);
    if (cdev_add(&c_dev, first, 1) == -1)
  {
    device_destroy(cl, first);
    class_destroy(cl);
    unregister_chrdev_region(first, 1);
    return -1;
  }

return 0;

}

static void __exit Nullexit()
{
  cdev_del(&c_dev);
  device_destroy(cl, first);
  class_destroy(cl);
  printk(KERN_INFO "Good Bye Hello World : Unregistered");

}

module_init(Nullentry);
module_exit(Nullexit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MALLI FROM L4u");
MODULE_DESCRIPTION("JUST A NULLDriver MODULE");









