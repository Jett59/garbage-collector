all:
	echo please specify windows/osx/linux

osx: gc_osx.a
linux: gc_linux.a
windows: gc.lib

gc.lib:
		gcc -o gc.lib -shared src/main/*.c

gc_osx.a:
	gcc -o gc_osx.a -shared src/main/*.c

gc_linux.a:
	gcc -o gc_linux.a -shared src/main/*.c

test: test.exe
	./test.exe

test.exe: gc.lib
	gcc -o test.exe src/test/*.c gc.*