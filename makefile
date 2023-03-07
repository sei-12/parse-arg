
CC = gcc
CFLAGS = -Wall -Wextra -Werror

TARGET = main
SRCS = main.c arg.c
OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
