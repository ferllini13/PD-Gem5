APP = arm1
CC = /home/ferllini13/x-tools/aarch64-unknown-linux-uclibc/bin/aarch64-unknown-linux-uclibc-gcc -o
CC2 =  /home/ferllini13/x-tools/arm-unknown-linux-uclibcgnueabi/bin/arm-unknown-linux-uclibcgnueabi-gcc -o
FLG= -static -fopenmp -lm


RN = /home/ferllini13/gem5/build/ARM/gem5.opt
SE= /home/ferllini13/gem5/configs/example/se.py


FS=/home/ferllini13/gem5/configs/example/arm/starter_fs.py
KNL=/home/ferllini13/gem5/binaries/vmlinux.vexpress_gem5_v1_64
DTB=/home/ferllini13/gem5/binaries/armv8_gem5_v1_$(CPU)cpu.dtb
IMG=/home/ferllini13/gem5/disks/linaro-minimal-aarch64.img
RTP=/home/ferllini13/gem5/m5out/cpt.
CHK=64973166434807500 

com:$(APP).c
	$(CC) $(APP) $(APP).c $(FLG)
	rm -rf *.o

	
com2:$(APP).c
	$(CC2) $(APP) $(APP).c $(FLG)
	rm -rf *.o
	
	
sys:$(APP)
	$(RN) $(SE) -c $(APP)
	
	
full:
	.$(RN) $(FS) --cpu=minor --num-cores=$(CPU) --disk-image=$(IMG) --dtb=$(DTB) --kernel=$(KNL)
	

chk:	
	$(RN) $(FS) --cpu=minor --num-cores=$(CPU) --disk-image=$(IMG) --dtb=$(DTB) --kernel=$(KNL) --restore=$(RTP)$(CHK)
	

	
clean:
	rm -rf $(APP)
