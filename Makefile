# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kellen <kellen@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/03 11:33:43 by keramos-          #+#    #+#              #
#    Updated: 2025/03/16 01:45:40 by kellen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

# **************************************************************************** #
#                                 variables                                    #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -O3

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
	sources/validate/check_arg.c sources/validate/check_texture.c \
	sources/validate/check_layout.c sources/validate/check_map.c \
	sources/init/init_game.c sources/init/init_mlx.c sources/init/init_txt.c \
	sources/utils/art.c sources/utils/clean_close.c sources/utils/ft_error.c \
	sources/utils/utils.c sources/utils/free.c \
	sources/parsing/parsing.c sources/parsing/texture.c sources/parsing/map.c \
	sources/parsing/player.c \
	sources/events/key.c sources/events/moves.c sources/events/rotate.c \
	sources/render/raycasting.c sources/render/draw_textures.c \
	sources/render/render.c sources/render/game_loop.c sources/render/minimap.c \
	sources/parsing/doors.c \
	validator_lib/cub3d_validator.c \
	validator_lib/cub3d_file_parser.c \
	validator_lib/cub3d_element_parser.c \
	validator_lib/cub3d_map_parser.c \
	validator_lib/cub3d_map_parser2.c \
	validator_lib/cub3d_map_validator.c \
	validator_lib/cub3d_map_validator_extra.c \
	validator_lib/cub3d_utils.c \
	validator_lib/cub3d_color_validator.c \
	validator_lib/cub3d_color_validator_extra.c \
	validator_lib/position/position_player.c \
	validator_lib/position/position_empty.c \
	validator_lib/validator_integration.c


OBJS_DIR = objs/

OBJS = $(SRCS:%.c=$(OBJS_DIR)%.o)


# **************************************************************************** #
#                                  RULES                                       #
# **************************************************************************** #

all: Start $(NAME) End

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

$(NAME): $(OBJS) $(LIBFT) $(LIB)
	$(call print_status,"Creating Cub3D...")
	@$(CC) $(INCLUDES) $(OBJS) $(LIBFT) $(LIB) $(MLXFLAGS) -o $@ > /dev/null
	@echo "${CHECK} Compiling utilities and grafics!         🎮"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/sources/validate
	@mkdir -p $(OBJS_DIR)/sources/init
	@mkdir -p $(OBJS_DIR)/sources/utils
	@mkdir -p $(OBJS_DIR)/sources/parsing
	@mkdir -p $(OBJS_DIR)/sources/events
	@mkdir -p $(OBJS_DIR)/sources/render
	@mkdir -p $(OBJS_DIR)/validator_lib
	@mkdir -p $(OBJS_DIR)/validator_lib/position
	@echo "${CHECK} Object directory created!         📁"

$(OBJS_DIR)%.o: %.c | $(OBJS_DIR)
	@$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@ > /dev/null

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
	@$(MAKE) clean -C mlx > /dev/null
	@echo "${CHECK} Cleanup complete               🧹"

fclean: clean
	@echo "${ORG}==> Full clean - Removing executables...${1}${RT}"
	@$(MAKE) fclean -C Libft > /dev/null
	@$(RM) $(NAME)
	@echo "${CHECK} Full cleanup complete          🧹"

re: fclean all

.PHONY: all clean fclean re
