CC=gcc
LFLAGS =  -lm
CFLAGS = -wall -wextra -g -I include

platil : s1.o s2.o .... sN.o

[TAB] $(CC) s1.o s2.o .... sN.o -o platil $(CFLAGS)

s1.o : s1.c
[TAB] $(CC) s1.c -c $(CFLAGS)

.
.

sN.o : sN.c
[TAB] $(CC) sN.c -c $(CFLAGS)
