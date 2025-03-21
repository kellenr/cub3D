/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   art.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kellen <kellen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 22:29:47 by keramos-          #+#    #+#             */
/*   Updated: 2025/03/21 04:20:15 by kellen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	art(const char *map_name)
{
	ft_printf("\n" P_P \
	"                           bbbbbbb \n" \
"       CCCCCCCC             b::::b          3333333333   DDDDDDDDDD \n" \
"    CCC:::::::C             b::::b         3::::::::::33 D:::::::::DD \n" \
"   C::::::::::C             b::::b         3:::3333:::::3D:::::::::::D \n" \
"  C::::CCCCC::C              b:::b         3333    3::::3DDD:::DDDD:::D \n" \
" C::::C    CCCCuuuuu   uuuuu b:::bbbbbbb           3::::3  D:::D   D:::D \n" \
"C::::C         u:::u   u:::u b::::::::::b          3::::3  D:::D    D:::D \n" \
"C::::C         u:::u   u:::u b:::::::::::b   333333::::3   D:::D    D:::D \n" \
"C::::C         u:::u   u:::u b:::bbbb:::::b  3::::::::3    D:::D    D:::D \n" \
"C::::C         u:::u   u:::u b:::b   b::::b  333333::::3   D:::D    D:::D \n" \
"C::::C         u:::u   u:::u b:::b    b:::b        3::::3  D:::D    D:::D \n" \
"C::::C         u:::u   u:::u b:::b    b:::b        3::::3  D:::D    D:::D \n" \
" C::::C    CCCCu::::uuu::::u b:::b    b:::b        3::::3  D:::D   D:::D \n" \
"  C::::CCCCC::Cu::::::::::::ub:::bbbbb::::b3333    3::::3DDD:::DDDD:::D \n" \
"   C::::::::::C u:::::::::::ub:::::::::::b 3:::3333:::::3D:::::::::::D \n" \
"    CCC:::::::C  uu::::::u::ub::::::::::b  3::::::::::33 D:::::::::DD \n" \
"       CCCCCCCC    uuuuuu uuubbbbbbbbbbb    3333333333   DDDDDDDDDD \n" \
"\n" RT \
"     "RT P_M"                  Welcome to the Cub3d Project \n" \
"                    This beautifull project is made by \n" \
"                          Keramos- and Fibarros! " RT "\n\n" \
"\t────────────────────── {.⋅ ✯&&✯ ⋅.}──────────────────────     \n" \
	"\n");
	control_opction(map_name);
}

void	control_opction(const char *map_name)
{
	ft_printf(P_P \
"\t+======================================================+\n" \
"\t|               "RT P_B"    🎮 controls 🎮 "RT P_P"                    |\n" \
"\t|======================================================|\n" \
"\t| ⬆️   W  : Move Forward                                |\n" \
"\t| ⬇️   S  : Move Backward                               |\n" \
"\t| ⬅️   A  : Move Left                                   |\n" \
"\t| ➡️   D  : Move Right                                  |\n" \
"\t| 🔄  <  : Rotate Left                                 |\n" \
"\t| 🔄  >  : Rotate Right                                |\n" \
"\t+======================================================+\n" RT);
	ft_printf("\n\t      🎮 Starting the game with map: %s\n", map_name);
	ft_printf("\n\t\t       💖 Enjoy Your Adventure! 💖 \n\n");
}
