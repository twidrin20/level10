load: load.c
	clang -g load.c -o load
	
clean:
	rm -f load
	
check: load
	valgrind ./load words3.txt