.PHONY: all clean distclean test

CC := gcc

DEPS := $(wildcard opt/*.h) $(wildcard common/*.h)
IN := $(wildcard opt/*.c)
OUT := $(patsubst %.c,%.o,$(IN))

# TODO: add .a file as well
BIN := libdiscotango.so

CC_OPTS :=
LINK_OPTS :=

all: $(BIN)

%.o: %.c $(DEPS)
	$(CC) -fPIC $(CC_OPTS) -o $@ -c $<

$(BIN): $(OUT)
	$(CC) -shared $(LINK_OPTS) -o $@ $^

clean:
	rm -f $(OUT) $(BIN)

distclean: clean

test:
	echo 'not defined!' && exit -1
