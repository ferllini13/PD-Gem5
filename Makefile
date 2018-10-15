GIT = https://gem5.googlesource.com/public/gem5
SYS = http://www.gem5.org/dist/current/arm/aarch-system-20180409.tar.xz
DEPS = scons mercurial swig gcc g++ m4 python python-dev libgoogle-perftools-dev


install: dependencies download
	scons ~/gem5/build/ARM/gem5.opt -j20

download:
	git clone $(GIT) ~/

	wget $(SYS) -P ~/gem5/

dependencies:
	sudo apt-get install $(DEPS)

run:
