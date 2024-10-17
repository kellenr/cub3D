# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keramos- <keramos-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/03 11:33:43 by keramos-          #+#    #+#              #
#    Updated: 2024/10/17 15:37:50 by keramos-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

# **************************************************************************** #
#                                 variables                                    #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -Wpedantic -g

LIBFT = ./Libft/libft.a

LIB = ./mlx/libmlx.a

MLXFLAGS = -L./mlx -lmlx_Linux -lXext -lX11 -lm

INCLUDES = -I inc \
			-I Libft/inclu \
			-I ./mlx/

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

SRCS = cub3d.c src/ft_error.c src/check_argc.c src/init.c src/free.c \
		src/clean.c src/events/key.c src/events/w_events.c src/parsing.c/map.c

OBJS = $(SRCS:.c=.o)


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

%.o: %.c
	@${CC} $(INCLUDES) ${CFLAGS} -c $< -o $@ > /dev/null

End :
	@echo "${PINK}Cub3D...${RT}";
	@echo "${CHECK} successfully compiled!         🎉$(RT)";

# **************************************************************************** #
#                                clean RULES                                   #
# **************************************************************************** #

clean:
	@echo "${ORG}==> Cleaning up object files...${1}${RT}"
	@$(MAKE) clean -C Libft > /dev/null
	@$(RM) $(OBJS)
	@$(MAKE) clean -C mlx > /dev/null
	@echo "${CHECK} Cleanup complete               🧹"

fclean: clean
	@echo "${ORG}==> Full clean - Removing executables...${1}${RT}"
	@$(MAKE) fclean -C Libft > /dev/null
	@$(RM) $(NAME)
	@$(RM) mlx
	@echo "${CHECK} Full cleanup complete          🧹"

re: fclean all

.PHONY: all clean fclean re
