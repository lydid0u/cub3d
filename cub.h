/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:03:43 by lboudjel          #+#    #+#             */
/*   Updated: 2024/08/31 19:56:59 by lboudjel         ###   ########.fr       */
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
	char	*value[6];
	char	**directions[6];
	char	**floor_colors;
	char	**ceiling_colors;
	int		nb_line_file;
}			t_jeu;

// utils.c
void		print_tab(char **tab);
void		free_tab(char **tab);
int			empty_line(char *str);

// parsing_directions.c
int			parsing(char *str);

// map_value.c
int			copy_map_value(char *file, t_jeu *jeu);
int			check_map_value(t_jeu *jeu);
int			check_direction(char *str, t_jeu *jeu);

// game_map.c
int			copy_game_map(char *file, t_jeu *jeu);
void		count_line(char *file, t_jeu *jeu);

#endif