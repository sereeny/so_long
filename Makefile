NAME = so_long
LIBFT_PATH = libft
LIBMLX = MLX42
SRC = src/so_long.c src/parser.c src/utils.c src/parserii.c src/core.c
#SRC_BONUS =
OBJ_DIR = obj
SRC_O = $(SRC:src/%.c=$(OBJ_DIR)/%.o)
BONUS_O = $(SRC_BONUS:src_bonus/%.c=$(OBJ_DIR)/%.o)
FLAGS = -g -Wall -Wextra -Werror

all: LIBMLX $(NAME)

#bonus: $(BONUS_O) $(LIBFT_PATH)/libft.a $(LIBMLX)/libmlx42.a
#	gcc -o $(NAME) $^ -L$(LIBFT_PATH) -ldl -lglfw -I include -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/" -pthread -lm
#	@echo
#	@echo 125% - BONUS
#	@echo

$(NAME): $(SRC_O) $(LIBFT_PATH)/libft.a $(LIBMLX)/build/libmlx42.a
	gcc -o $@ $^ -L$(LIBFT_PATH) -ldl -lglfw -Iinclude  -ldl -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/" -pthread -lm
	@echo
	@echo 100%
	@echo

$(LIBFT_PATH)/libft.a:
	$(MAKE) -C $(LIBFT_PATH) all
	@echo
	@echo 80%
	@echo

LIBMLX:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(OBJ_DIR)/%.o : src/%.c
	@mkdir -p $(OBJ_DIR)
	gcc $(FLAGS) -c $< -o $@

$(OBJ_DIR)/%.o : src_bonus/%.c
	@mkdir -p $(OBJ_DIR)
	gcc $(FLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(SRC_O)
#	rm -rf $(BONUS_O)
	rm -rf $(OBJ_DIR)
	rm -rf $(LIBMLX)/build

fclean: clean
#	$(MAKE) -C $(LIBFT_PATH) fclean
#	$(MAKE) -C MLX42 fclean
#	rm -f $(SRC_O)
#	rm -rf $(BONUS_O)
	rm -f $(NAME)
#	rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: all, clean, fclean, re, libmlx
