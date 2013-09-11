CC	 =	gcc

CFLAGS	+=	-I. -Isys/ -Werror
CFLAGS	+=	-Wall -Wstrict-prototypes -Wmissing-declarations
CFLAGS	+=	-Wcast-qual -Wsign-compare -Wpointer-arith

PROG	 =	mergesort
OBJS	 =	main.o

.PHONY: clean

all: ${PROG}

${PROG}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o $@;

.c.o:
	${CC} ${CFLAGS} $< -c -o $@;

clean:
	rm -f ${PROG} ${OBJS};
