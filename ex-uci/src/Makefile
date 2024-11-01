OBJS = uci_excise.o

all: uci_excise

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $<

uci_excise: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS)

clean:
	rm -rf uci_excise *.o
