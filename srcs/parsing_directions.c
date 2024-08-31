/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_directions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:03:07 by lboudjel          #+#    #+#             */
/*   Updated: 2024/08/27 18:13:22 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	parsing(char *str)
{
	char	*cub;

	if (ft_strlen(str) > 4)
	{
		cub = ft_strnstr(str, ".cub", ft_strlen(str));
		if (cub && ft_strlen(cub) == 4)
			return (0);
	}
	printf("Nom de fichier pas valide !\n");
	return (1);
}
