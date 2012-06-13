CC = gcc
CFLAGS = -Wall

PROG = stochastic_kinetics
HDRS = stochastic_kinetics.h
SRCS = main.c stochastic_kinetics.c

OBJS = $(SRCS:.c=.o)

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.c stochastic_kinetics.h

stochastic_kinetics.o : stochastic_kinetics.c stochastic_kinetics.h

.PHONY : clean

clean :
	-rm $(PROG) $(OBJS)
