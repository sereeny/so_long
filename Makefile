# Variables
NAME = so_long
NAME_BONUS = so_long_bonus
LIBFT_PATH = libft
LIBMLX = MLX42
LIBMLX_REPO = https://github.com/42-Fundacion-Telefonica/MLX42.git
SRC = src/so_long.c src/parser.c src/utils.c src/parserii.c src/core.c
SRC_BONUS = src_bonus/core_bonus.c src_bonus/parser_bonus.c src_bonus/parserii_bonus.c src_bonus/so_long_bonus.c src_bonus/utils_bonus.c
OBJ_DIR = obj
SRC_O = $(SRC:src/%.c=$(OBJ_DIR)/%.o)
BONUS_O = $(SRC_BONUS:src_bonus/%.c=$(OBJ_DIR)/%_bonus.o)
CFLAGS = -g -Wall -Wextra -Werror -ggdb3
LDFLAGS = -L$(LIBFT_PATH) -ldl -lglfw -Iinclude -pthread -lm
GLFW_PATH = "/Users/$(USER)/.brew/opt/glfw/lib/"

# Default rule
all: $(NAME)

# Bonus rule that builds the bonus executable only if necessary
bonus: $(NAME_BONUS)
	@echo "\033[1;32m[OK]\033[0m Built bonus version: $(NAME_BONUS)"

# Standard executable
$(NAME): $(SRC_O) $(LIBFT_PATH)/libft.a $(LIBMLX)/build/libmlx42.a
	@gcc -o $@ $^ $(LDFLAGS) -L$(GLFW_PATH)
	@echo "\033[1;32m[OK]\033[0m Built standard version: $(NAME)"

# Bonus executable with unique output file
$(NAME_BONUS): $(BONUS_O) $(LIBFT_PATH)/libft.a $(LIBMLX)/build/libmlx42.a
	@gcc -o $@ $^ $(LDFLAGS) -L$(GLFW_PATH)
	@echo "\033[1;32m[OK]\033[0m Built bonus executable: $(NAME_BONUS)"

# Build libft only if needed
$(LIBFT_PATH)/libft.a:
	$(MAKE) -C $(LIBFT_PATH) all
	@echo "\033[1;34m[INFO]\033[0m Built libft library"

# Build MLX42 library only if needed
$(LIBMLX)/build/libmlx42.a:
	@cmake -S $(LIBMLX) -B $(LIBMLX)/build
	@$(MAKE) -C $(LIBMLX)/build -j4
	@echo "\033[1;34m[INFO]\033[0m Built MLX42 library"

# Object file compilation rules for both regular and bonus sources
$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(CFLAGS) -c $< -o $@
	@echo "\033[1;34m[INFO]\033[0m Compiled $<"

$(OBJ_DIR)/%_bonus.o: src_bonus/%.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(CFLAGS) -c $< -o $@
	@echo "\033[1;34m[INFO]\033[0m Compiled bonus $<"

clean:
	@$(MAKE) -C $(LIBFT_PATH) clean
	@rm -f $(SRC_O) $(BONUS_O)
	@echo "\033[1;33m[CLEAN]\033[0m Object files removed"

fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@rm -rf $(LIBMLX)/build
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "\033[1;33m[CLEAN]\033[0m All binaries removed"

re: fclean all

# Clone or update MLX42 repository if not present
get_mlx:
	@if [ -d "$(LIBMLX)" ]; then \
		echo "\033[1;33m[INFO]\033[0m Removing existing $(LIBMLX) folder..."; \
		rm -rf $(LIBMLX); \
	fi
	@git clone $(LIBMLX_REPO) $(LIBMLX)
	@echo "\033[1;34m[INFO]\033[0m Cloned MLX42 repository"

.PHONY: all clean fclean re bonus get_mlx
