ifndef $(CC)
	CC=gcc
endif

ifndef $(LD)
	LD=gcc
endif

ifndef $(DB)
	DB=valgrind
endif

ifndef $(EXECCMD)
	EXECCMD=exec
endif

CCFLAGS+=-I./src/ -Wall -g -Wextra -Werror
LDFLAGS+=-lm

CD=cd
RM=/usr/bin/rm -rf
CP=/usr/bin/cp
MV=/usr/bin/mv
ECHO=printf
MKDIR=/usr/bin/mkdir -p

EXEC=main
BINDIR=./bin
SRCDIR=./src

OBJECTS=$(SRCDIR)/main.o

all: $(EXEC)

$(EXEC): $(OBJECTS)
	@$(ECHO) "\tLD %s\n" bin/$(EXEC)
	@$(LD) -o $(BINDIR)/$(EXEC) $(OBJECTS) $(LDFLAGS)

%.o: %.c %.h
	@$(ECHO) "\tCC %s\n" $@
	@$(CC) -o $@ -c $< $(CCFLAGS)

mkdir:
	@$(MKDIR) $(BINDIR)

clean:
	$(RM) $(OBJECTS)
	$(RM) $(BINDIR)/$(EXEC)

run: $(EXEC)
	$(EXECCMD) $(BINDIR)/$(EXEC) $(ARGS)

debug: $(EXEC)
	$(DB) $(BINDIR)/$(EXEC)
