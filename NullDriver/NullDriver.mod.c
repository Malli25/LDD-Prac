#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x885b74e3, "module_layout" },
	{ 0xf4e7c8c5, "cdev_del" },
	{ 0xf6fd5309, "device_destroy" },
	{ 0x27cdc719, "cdev_add" },
	{ 0x992ad80e, "cdev_init" },
	{ 0x5722473f, "class_destroy" },
	{ 0x6c075966, "device_create" },
	{ 0x7485e15e, "unregister_chrdev_region" },
	{ 0xdc5e7ab3, "__class_create" },
	{ 0x29537c9e, "alloc_chrdev_region" },
	{ 0x27e1a049, "printk" },
	{ 0xb4390f9a, "mcount" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "7010EE73673E51D7624BFD1");
