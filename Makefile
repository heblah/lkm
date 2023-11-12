#
# Makefile compiling a simple lkm with no flag
#

KVERSION=$(shell uname -r)

obj-m += khello.o

all:
	mkdir -p /lib/modules/$(KVERSION)/build
	make -C /lib/modules/$(KVERSION)/build/ M=$(PWD) modules

clean:
	make -C /lib/modules/$(KVERSION)/build/ M=$(PWD) clean


.PHONY: all clean fclean re bonus run
