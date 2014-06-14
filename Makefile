PROG=lifegame
SRCS=main.c clean_field.c random_field.c update_field.c output_field.c
SRCS_MDEP=$(SRCS)
SRCS_NDEP=$(SRCS)
SRCS_TURNDEP=main.c
OBJS=$(SRCS:%.c=%.c.o)
OBJS_MDEP=$(SRCS_MDEP:%.c=%.c.o)
OBJS_NDEP=$(SRCS_NDEP:%.c=%.c.o)
OBJS_TURNDEP=$(SRCS_TURNDEP:%.c=%.c.o)
ALLDEP=$(MAKEFILE_LIST)
TOCLEAN_OUTPUTS=turn*.pbm

all: $(PROG)

CC:=cc
HEADERFLAGS:=-I.
OPTFLAGS:=-O0 -g
WARNFLAGS:=-ansi -pedantic -Wall -Wextra -W -Wundef -Wshadow -Wcast-qual -Winline -Wno-long-long -fsigned-char
RM:=rm -r -f
WC:=wc -c -l
ADDCFLAGS=-fopenmp
LINKFLAGS=-fopenmp

COMPILE.c=$(CC) $(HEADERFLAGS) $(OPTFLAGS) $(WARNFLAGS) $(DEPFLAGS) $(ADDCFLAGS) $(CFLAGS) -c
LINK.o=$(CC) $(OPTFLAGS) $(WARNFLAGS) $(LINKFLAGS) $(LDFLAGS)

M?=20
M_VALFLAGS=-DM=$(M)
MNUM=.m
$(shell ([ -f $(MNUM) ] && [ `cat $(MNUM)` -eq $(M) ]) || echo $(M) >$(MNUM))
$(OBJS_MDEP): $(MNUM)
$(OBJS_MDEP): DEPFLAGS+=$(M_VALFLAGS)

N?=10
N_VALFLAGS=-DN=$(N)
NNUM=.n
$(shell ([ -f $(NNUM) ] && [ `cat $(NNUM)` -eq $(N) ]) || echo $(N) >$(NNUM))
$(OBJS_NDEP): $(NNUM)
$(OBJS_NDEP): DEPFLAGS+=$(N_VALFLAGS)

TURN?=30
TURN_VALFLAGS=-DTURN=$(TURN)
TURNNUM=.turn
$(shell ([ -f $(TURNNUM) ] && [ `cat $(TURNNUM)` -eq $(TURN) ]) || echo $(TURN) >$(TURNNUM))
$(OBJS_TURNDEP): $(TURNNUM)
$(OBJS_TURNDEP): DEPFLAGS+=$(TURN_VALFLAGS)


$(PROG): $(OBJS) $(ALLDEP)
	$(LINK.o) $(OUTPUT_OPTION) $(OBJS)

%.c.o: %.c $(ALLDEP)
	$(COMPILE.c) $(OUTPUT_OPTION) $<

run: $(PROG)
	./$(PROG)

.PHONY: line
line:
	$(WC) $(SRCS) $(MAKEFILE_LIST)

.PHONY: clean-outputs
clean-outputs:
	$(RM) $(TOCLEAN_OUTPUTS)

.PHONY: clean
clean: clean-outputs
	$(RM) $(PROG) $(OBJS)
	$(RM) $(MNUM) $(NNUM) $(TURNNUM)
	$(RM) $(TOCLEAN)
