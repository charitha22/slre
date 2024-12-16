CFLAGS=-emit-llvm -g -c -O0 -Xclang -disable-O0-optnone
CLANG=${LLVM_BUILD_DIR}/bin/clang
LLVM_LINK=${LLVM_BUILD_DIR}/bin/llvm-link

test-driver.bc : test-driver.c
	$(CLANG) $(CFLAGS) test-driver.c
	${CLANG} $(CFLAGS) slre.c
	${LLVM_LINK} test-driver.bc slre.bc -o runner.bc

clean:
	rm -rf *.bc klee-* *.ll *.o