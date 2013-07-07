# My FIrst Make File

obj-m := CharReg2.o

KERNEL_SOURCE := /usr/src/linux-headers-3.2.0-29-generic
PWD:=$(shell pwd)


default:
	make -C ${KERNEL_SOURCE} SUBDIRS=${PWD} modules

clean:
	make -C ${KERNEL_SOURCE} SUBDIRS=${PWD} clean







