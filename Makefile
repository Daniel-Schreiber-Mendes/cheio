VERSION = -std=c99
ERRORFLAGS = -Wall -Wuninitialized -Werror=implicit-function-declaration -Wextra -Werror=int-conversion -Wno-unused-function -Wno-unused-parameter
CFLAGS = $(ERRORFLAGS) $(VERSION) -c -g -fpic
OBJFILES = file.o string.o



make: $(OBJFILES)
	gcc -shared -o libcheio.so $(OBJFILES)
	cp *.h /usr/local/include/cheio/
	mv libcheio.so /usr/local/lib/

file.o: file.c
	gcc $(CFLAGS) file.c

string.o: string.c
	gcc $(CFLAGS) string.c