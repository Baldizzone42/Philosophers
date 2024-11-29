NAME    = philo
USER    = jormoral
CFLAGS  = -Wall -Wextra -Werror -g -fsanitize=thread
CC      = clang

MAGENTA = \033[35;1m
YELLOW  = \033[33;1m
GREEN   = \033[32;1m
WHITE   = \033[37;1m
RESET   = \033[0m
GRAY 	= \033[0;90m
BLUE    = \033[34;1m
CYAN    = \033[37;1m
BOLD	= \033[1m
RED		= \033[31;1m

SRCS	:= init.c monitor.c philosophers.c routine.c utils.c print.c

OBJS	:= ${SRCS:.c=.o}

all: $(NAME)

$(NAME):	compiling $(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
			@echo "$(MAGENTA)philosophers compiled!$(RESET)"

$%.o: %.c
			@echo "$(BLUE)Compiling: $(RESET)$(notdir $<)"
			@$(CC) $(CFLAGS) -c $< -o $@

compiling:
			@echo "$(YELLOW)Compiling philosophers!$(RESET)"
			
clean:
			@rm -rf $(OBJS)
			@echo "$(RED)Cleaning philosophers executables.$(RESET)"
			

fclean:
			@rm -rf $(OBJS)
			@rm -rf $(NAME)
			@echo "$(RED)Fcleaning philosophers.$(RESET)"

re: fclean all
			@echo "$(YELLOW)philosophers recompiled$(RESET)"

norm:
			@echo "$(YELLOW)Norminette of philosophers files & BONUS.$(RESET)"
			@norminette $(SRCS)
			@echo 
			@echo "$(YELLOW)Norminette of LIBFT.$(RESET)"
			@norminette $(LIBFT)
						
.PHONY: all clean fclean re norm compiling