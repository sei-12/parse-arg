CC = gcc
SRCS = main.c

main:$(SRCS)
	gcc $(SRCS) -o $@