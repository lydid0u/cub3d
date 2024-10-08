/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:05:49 by lboudjel          #+#    #+#             */
/*   Updated: 2024/09/10 19:10:35 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("[%s]\n", tab[i]);
		i++;
	}
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

void	free_tab_tab(char ***tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (i < 6)
		{
			free_tab(tab[i]);
			i++;
		}
		if (tab)
			free(tab);
	}
}

int	empty_line(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\n')
		{
			j = 1;
			break ;
		}
		i++;
	}
	if (j == 1)
		return (0);
	return (1);
}
