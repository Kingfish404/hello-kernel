obj-m := hello.o

all :
	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

insmod:
	sudo insmod ./hello.ko

rmmod:
	sudo rmmod hello

kern_log:
	tail /var/log/kern.log

clean:
	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
