# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kellen <kellen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/03 11:33:43 by keramos-          #+#    #+#              #
#    Updated: 2025/03/21 04:26:16 by kellen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

NAME_BONUS = cub3D_bonus

# **************************************************************************** #
#                                 variables                                    #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -O3

CFLAGS_BONUS = -Wall -Wextra -Werror -g -O3 -D BONUS=1

LIBFT = ./Libft/libft.a

LIB = ./mlx/libmlx.a

MLXFLAGS = -L./mlx -lmlx_Linux -lXext -lX11 -lm

INCLUDES = -I inc \
			-I Libft/inclu \
			-I ./mlx/ \
			-I ./validator_lib/

RM = rm -rf

#                         Color and Checkmark Definitions                      #

LILAC=\033[1;38;5;183m
PINK=\033[1;38;5;213m
BABY_BLUE = \033[1;38;5;153m
ORG =\033[38;5;216m
BLUE=\033[1;34m
AQUA=\033[1;38;5;79m
AQUA_L=\033[38;5;51m
GREEN=\033[1;32m
CHECK = \033[0;34m✔\033[0m
RT = \033[0m

#                                 Print Function                               #

define print_libs
	@echo "${BABY_BLUE}====> ${1}${RT}"
endef

define print_status
	@echo "${LILAC}====> ${1}${RT}"
endef

define download_libs
	@echo "${ORG}====> ${1}${RT}"
endef

#              Progress Bar for MLX cloning and compilation                    #
TOTAL_STEPS := 20  # Increased steps for smoother progress
STEP_NUM := 0

# **************************************************************************** #
#                                 SOURCES                                      #
# **************************************************************************** #

SRCS = cub3d.c \
	init/init_game.c init/init_mlx.c init/init_txt.c init/init_map.c \
	parsing/parsing.c parsing/texture.c parsing/map.c parsing/player.c \
	parsing/doors.c \
	utils/art.c utils/clean_close.c utils/free.c utils/ft_error.c utils/utils.c \
	validate/check_arg.c validate/check_texture.c validate/check_color.c \
	validate/check_map.c validate/check_layout.c \
	event/key.c event/moves.c event/rotate.c event/intro.c \
	render/draw_textures.c render/game_loop.c render/minimap.c \
	render/raycasting.c render/render.c render/mini_drap.c


OBJS_DIR = objs/

OBJS = $(SRCS:%.c=$(OBJS_DIR)%.o)

OBJS_BONUS_DIR = objs_bonus/

OBJS_BONUS = $(SRCS:%.c=$(OBJS_BONUS_DIR)%.o)


# **************************************************************************** #
#                                  RULES                                       #
# **************************************************************************** #

all: Start $(NAME) End

bonus: Start $(NAME_BONUS) End

Start :
	@if [ -f $(NAME) ]; then \
		echo "${LILAC}Checking if build is necessary...${RT}"; \
	else \
		echo "${PINK}Compiling Cub3D...${RT}"; \
		echo "Starting the build process...!"; \
	fi

# MiniLibX compilation with automatic cloning and building
#Adding 2>&1 redirects both the standard output and standard error to /dev/null,
#thus suppressing all command line outputs, including those from ar.
$(LIB):
	@if [ ! -d "mlx" ]; then \
		echo "${BABY_BLUE}====>Cloning MiniLibX repository...${1}${RT}"; \
		git clone https://github.com/42Paris/minilibx-linux.git mlx >/dev/null 2>&1; \
		echo "${ORG}Downloading and compiling MiniLibX...${RT}"; \
		i=1; \
		while [ $$i -le $(TOTAL_STEPS) ]; do \
			STEP_NUM=$$i; \
			PERCENT=$$(expr $$i \* 100 / $(TOTAL_STEPS)); \
			PROGRESS=$$(expr $$i \* 20 / $(TOTAL_STEPS)); \
			printf "\rMLX: ["; \
			printf "${GREEN}%0.s#${RT}" `seq 1 $$PROGRESS`; \
			if [ $$PERCENT -lt 100 ]; then \
				printf "%0.s-" `seq 1 $$(expr 20 - $$PROGRESS)`; \
			fi; \
			printf "] $$STEP_NUM/$(TOTAL_STEPS) - $$PERCENT%%"; \
			sleep 0.15; \
			i=$$(expr $$i + 1); \
		done; \
		echo ""; \
		echo "${CHECK} MiniLibX cloned!         ✅"; \
	else \
		echo "${ORG}====> MiniLibX already cloned!${RT}"; \
	fi
	@make -s -C mlx >/dev/null 2>&1;
	@echo "${CHECK} MLX compiled                 ✅"

$(LIBFT):
	$(call print_libs,"Compiling Libft...")
	@make -C Libft > /dev/null
	@echo "${CHECK} Libft compiled                 ✅"

# Ensure MLX and LIBFT are built before compiling the object files
$(OBJS): $(LIB) $(LIBFT)

$(OBJS_BONUS): $(LIB) $(LIBFT)

$(NAME): $(OBJS) $(LIBFT) $(LIB)
	$(call print_status,"Creating Cub3D...")
	@$(CC) $(INCLUDES) $(OBJS) $(LIBFT) $(LIB) $(MLXFLAGS) -o $@ > /dev/null
	@echo "${CHECK} Compiling utilities and grafics!         🎮"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)validate
	@mkdir -p $(OBJS_DIR)init
	@mkdir -p $(OBJS_DIR)utils
	@mkdir -p $(OBJS_DIR)parsing
	@mkdir -p $(OBJS_DIR)event
	@mkdir -p $(OBJS_DIR)render
	@echo "${CHECK} Object directory created!         📁"

# Rule for normal objects
$(OBJS_DIR)%.o: %.c | $(OBJS_DIR)
	@$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@ > /dev/null

$(OBJS_BONUS): $(LIB) $(LIBFT)

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT) $(LIB)
	$(call print_status,"Creating Cub3D...")
	@$(CC) $(INCLUDES) $(OBJS_BONUS) $(LIBFT) $(LIB) $(MLXFLAGS) -o $@ > /dev/null
	@echo "${CHECK} Compiling utilities and grafics!         🎮"

$(OBJS_BONUS_DIR):
	@mkdir -p $(OBJS_BONUS_DIR)
	@mkdir -p $(OBJS_BONUS_DIR)validate
	@mkdir -p $(OBJS_BONUS_DIR)init
	@mkdir -p $(OBJS_BONUS_DIR)utils
	@mkdir -p $(OBJS_BONUS_DIR)parsing
	@mkdir -p $(OBJS_BONUS_DIR)event
	@mkdir -p $(OBJS_BONUS_DIR)render
	@echo "${CHECK} Object directory created!         📁"

# Rule for bonus objects
$(OBJS_BONUS_DIR)%.o: %.c | $(OBJS_BONUS_DIR)
	@$(CC) $(INCLUDES) $(CFLAGS_BONUS) -c $< -o $@ > /dev/null

End :
	@echo "${PINK}Cub3D...${RT}";
	@echo "${CHECK} successfully compiled!         🎉$(RT)";

# **************************************************************************** #
#                                clean RULES                                   #
# **************************************************************************** #

clean:
	@echo "${ORG}==> Cleaning up object files...${1}${RT}"
	@$(MAKE) clean -C Libft > /dev/null
	@$(RM) $(OBJS_DIR)
	@$(RM) $(OBJS_BONUS_DIR)
	@$(MAKE) clean -C mlx > /dev/null
	@echo "${CHECK} Cleanup complete               🧹"

fclean: clean
	@echo "${ORG}==> Full clean - Removing executables...${1}${RT}"
	@$(MAKE) fclean -C Libft > /dev/null
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)
	@$(RM) mlx
	@echo "${CHECK} Full cleanup complete          🧹"

re: fclean all

.PHONY: all clean fclean re
