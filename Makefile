OBJDIR = obj
SRCDIR = src

CC = cc
VPATH = $(SRCDIR)
FLAGS = -Wall -Wextra -Werror -g3
NAME = philo
SRCS = philosophers.c
OBJ = $(SRCS:.c=.o)
OBJ := $(patsubst $(SRCDIR)/%, $(OBJDIR)/%, $(OBJ))
INCLUDE_PATH = -I./include
CFLAGS = $(FLAGS) $(INCLUDE_PATH)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@mkdir -p $(dir $@)
	$(V)$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB_PATH) $(LIB_NAME) -o $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)
	$(MAKE) clean && cd ../..

fclean: clean
	rm -rf $(NAME)
	$(MAKE) fclean && cd ../..

re: fclean all

.PHONY: all clean fclean re