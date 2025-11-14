CYAN = \033[1;36m
YELLOW = \033[1;33m
GREEN = \033[1;92m
RED = \033[1;31m
NC = \033[0m

NAME_CLIENT = client
NAME_SERVER = server

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./libft -I./ft_printf

SRC_CLIENT = client.c  clientinput.c
SRC_SERVER = server.c 

OBJ_CLIENT =$(SRC_CLIENT:.c=.o)
OBJ_SERVER =$(SRC_SERVER:.c=.o)

LIBFT_DIR = ./libft
FT_PRINTF_DIR = ./ft_printf
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: logo $(LIBFT) $(FT_PRINTF) $(NAME_CLIENT) $(NAME_SERVER)

bonus: all
	@echo "$(GREEN) Bonus part is done"
logo:
	@echo "$(GREEN)"
	@echo "███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗  ██╗"
	@echo "████╗ ████║██║████╗  ██║██║╚══██╔══╝██╔══██╗██║     ██║ ██╔╝"
	@echo "██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝ "
	@echo "██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗ "
	@echo "██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗"
	@echo "╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝"
	@echo "$(NC)"
	@echo "$(YELLOW) Welcome to My MINITALK Server! $(NC)"
	@echo "$(GREEN)================================================================$(NC)"
	@echo ""

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)


$(FT_PRINTF):
	@$(MAKE) -C $(FT_PRINTF_DIR)


$(NAME_CLIENT): $(OBJ_CLIENT) $(LIBFT) $(FT_PRINTF)
	@echo "$(GREEN)Compiling client... $(NC)"
	@$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBFT) $(FT_PRINTF) -o $(NAME_CLIENT)
	@echo "$(GREEN)Client compiled successfully!$(NC)"

$(NAME_SERVER): $(OBJ_SERVER) $(LIBFT) $(FT_PRINTF)
	@echo "$(GREEN)Compiling server...$(NC)"
	@$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBFT) $(FT_PRINTF) -o $(NAME_SERVER)
	@echo "$(GREEN)Server compiled successfully!$(NC)"


clean:
	@echo "$(RED)Cleaning...$(NC)"
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(FT_PRINTF_DIR) clean
	@rm -f $(OBJ_CLIENT) $(OBJ_SERVER)
	@echo "$(RED)✓ Done$(NC)"


fclean: clean
	@echo "$(RED)Full clean...$(NC)"
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean
	@rm -f $(NAME_CLIENT) $(NAME_SERVER)
	@echo "$(RED)✓ Everything cleaned$(NC)"

re: fclean all

.PHONY: all clean fclean re logo bonus 