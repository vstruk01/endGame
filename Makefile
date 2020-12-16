NAME = endgame

NCURSES = -lncurses

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
CC = clang

OBJD = obj
DIRS = src

SRCD = src

INCD = -I inc/

SRCC = $(foreach dir, $(DIRS), $(wildcard $(dir)/*.c))

OBJS = $(SRCC:src/%.c=$(OBJD)/%.o)

.PHONY: all MINILIBMX $(OBJD) uninstall clean reinstall

all: MINILIBMX

MINILIBMX: $(OBJD) $(OBJS)
	@printf "\x1b[32mcompile obj file:\x1b[33m ok\x1b[0m\n"
	@$(CC) $(NCURSES) -o $(NAME) $(OBJS)
	@printf "\x1b[32mcreate minilibmx:\x1b[33m ok\x1b[0m\n"

$(OBJD)/%.o: $(SRCD)/%.c
	@$(CC) $(CFLAGS) $(INCD) -c $< -o $@
	@printf "\x1b[32mcompiled:\x1b[0m $<\n"

$(OBJD):
	@mkdir -p obj

uninstall: clean
	@rm -f $(NAME)
	@printf "\x1b[31mdelete \x1b[32m$(NAME)\x1b[33m ok \x1b[0m\n"

clean:
	@rm -rf $(OBJD)
	@printf "\x1b[31mdelete \x1b[32m$(OBJD)\x1b[33m ok \x1b[0m\n"

reinstall: uninstall MINILIBMX

