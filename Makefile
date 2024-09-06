# Standard
NAME				= so_long

# Directories
LIBFT_DIR			= ./libft
LIBFT_LIB			= $(LIBFT_DIR)/libft.a
INC					= inc/
SRC_DIR				= src/
OBJ_DIR				= obj/

# Compiler and CFlags
CC					= gcc
CFLAGS				= -g -Wall -Werror -Wextra
MLX_FLAGS			= -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
RM					= rm -f
INCLUDES			= -I/usr/include -Imlx

# Source Files
SRCS 				= 	$(SRC)so_long.c \
						$(SRC)parse.c 

# Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Build rules
all: 				$(NAME)

$(NAME): 			$(OBJ) $(LIBFT_LIB)
					@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_LIB) -o $(NAME) $(MLX_FLAGS) $(INCLUDES)

# Compile object files from source files (general pattern)
.c.o:
					@mkdir -p $(OBJ_DIR)
					@$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)/$*.o $(INCLUDES)

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_LIB):
					@make -C $(LIBFT_DIR)

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C $(LIBFT_DIR)

fclean: 			clean
					@$(RM) $(NAME)
					@make fclean -C $(LIBFT_DIR)

re: 				fclean all

# Phony targets represent actions not files
.PHONY: 			all clean fclean re