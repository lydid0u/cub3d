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

// int check_one(char c)
// {
// 	i
// }

int	error_handler(t_jeu *jeu)
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