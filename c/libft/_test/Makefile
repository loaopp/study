CC		= gcc
CFLAGS	= "" #"-Wall -Werror -Wextar"
TARGET	= a.out
OBJS	= *.o

all:	$(TARGET)

$(TARGET):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

*.o:	*.c
		gcc -c ${CFLAGS} *.c

clean:
	rm $(OBJS) $(TARGET)
