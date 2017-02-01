CC=gcc
CFLAGS=-W -Wall `pkg-config --cflags elementary`
LDFLAGS=`pkg-config --cflags --libs elementary`
EDJE_CC=edje_cc

EXEC=example

OBJS=example.o

all: $(EXEC)

clean:
	rm -rf *.edj $(EXEC) $(OBJS)

%.edj: %.edc
	$(EDJE_CC) $<

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(EXEC): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)


# Depencies
example.c: example.edj

