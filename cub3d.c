/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 22:44:18 by alexa             #+#    #+#             */
/*   Updated: 2025/03/16 01:31:26 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	initialize_game(&game);
	check_argc(argc, argv);
	parse_file(&game, argv[1]);
	art(argv[1]);
	init_mlx(&game);
	init_imgs(&game);
	load_txt(&game);
	ft_events(&game);
	mlx_loop_hook(game.mlx, &start_game, &game);
	mlx_loop(game.mlx);
	return (0);
}

/* 
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
 */
