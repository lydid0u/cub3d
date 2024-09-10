/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:03:43 by lboudjel          #+#    #+#             */
/*   Updated: 2024/09/10 19:08:58 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "./libft/libft.h"
# include "./srcs/gnl/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define SPACE ' '
# define TAB '\t'
# define ALLSPACES " \t"

# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3
# define CEILING 4
# define FLOOR 5

typedef struct s_jeu
{
	char	**map;
	char	**value;
	char	**file_map;
	char	***directions;
	char	**floor_colors;
	char	**ceiling_colors;
	char	**map_spaced;
	int		pos_i;
	int		pos_j;
	char	start_position;
	int		nb_line_file;
	int		nb_line_map;
	int		ok[7];
	size_t	longest_line;
}			t_jeu;

// utils.c
void		print_tab(char **tab);
void		free_tab(char **tab);
int			empty_line(char *str);

// parsing.c
int			filename(char *str);

// first_six_line.c
int			copy_map_value(char *file, t_jeu *jeu);
int			check_map_value(t_jeu *jeu);
int			check_direction(char *str, t_jeu *jeu);

// copy_map.c
int			copy_game_map(t_jeu *jeu);
void		count_line(char *file, t_jeu *jeu);

int			copy_file(char *file, t_jeu *jeu);
int			parsing_map(t_jeu *jeu);

int			error_handler(t_jeu *jeu);
void		free_tab_tab(char ***tab);

#endif