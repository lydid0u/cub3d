/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:59:40 by lboudjel          #+#    #+#             */
/*   Updated: 2024/09/06 19:52:57 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_letters(t_jeu *jeu)
{
	int	i;
	int j;
	char **map = jeu->map_spaced;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strchr(" 10WNES", map[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_wall(t_jeu *jeu)
{
	int	col;
	int row;
	char **map = jeu->map_spaced;

	col = 0;
	while (map[col])
	{
		row = 0;
		while (map[col][row])
		{
			if (map[col][row] == ' ')
			{
				// nord
				if (col != 0)
					if (!ft_strchr(" 1", map[col - 1][row]))
						return (1);
				// ouest
				if (row != 0)
					if (!ft_strchr(" 1", map[col][row - 1]))
						return (2);
				// sud
				// si la ligne dapres nest pas null
				if (map[col + 1])
					if (!ft_strchr(" 1", map[col + 1][row]))
						return (3);
				// est
				// si le char dapres nest pas null
				if (map[col][row + 1])
					if (!ft_strchr(" 1", map[col][row + 1]))
						return (4);
			}
			row++;
		}
		col++;
	}
	return (0);
}

int	check_position(t_jeu *jeu)
{
	int	i;
	int j;
	int letter;
	char **map;
	
	map = jeu->map_spaced;
	i = 0;
	letter = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("WNES", map[i][j]))
				letter++;
			if (letter > 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int error_handler(t_jeu *jeu)
{
	int z = 0;		
	z = check_wall(jeu);
	if (z)
		return (printf("c la merde chef: %i\n", z), 1);
	if (check_letters(jeu))
		return(printf("Error\nA char is wrong !\n"), 1);
	if (check_position(jeu))
		return(printf("Error\nTwo or more start position !\n"), 1);
	return (0);
}