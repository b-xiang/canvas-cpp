
all: compile

configure:
	mkdir build
	(cd build && cmake ..)
	
compile:
	make -C build
	
run:
	(cd build/bin && ./demo)
	
test:
	(cd build/bin && ./unit_test)
	
clean:
	make -C build clean
	
distclean:
	(rm -rf build)