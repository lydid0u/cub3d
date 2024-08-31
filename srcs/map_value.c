/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:38:22 by lboudjel          #+#    #+#             */
/*   Updated: 2024/08/31 19:34:19 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	copy_map_value(char *file, t_jeu *jeu)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (line && !empty_line(line))
		{
			jeu->value[i] = malloc(ft_strlen(line) + 1);
			if (!jeu->value[i])
				return (1);
			ft_strcpy(jeu->value[i++], line);
		}
		if (i == 6)
			break ;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
	if (i != 6)
		return (printf("Error\nA value is missing !\n"), free_tab(jeu->value), 1);
	return (0);
}

int	check_rgb_ceiling(t_jeu *jeu)
{
	int	i;
	int	nb;

	i = 0;
	jeu->ceiling_colors = ft_split(jeu->directions[4][1], ',');
	while (jeu->ceiling_colors[i])
		i++;
	if (i != 3)
		return (printf("Error\nWith the ceiling's rgb value !\n"), 1);
	i = 0;
	while (i != 3)
	{
		nb = ft_atoi(jeu->ceiling_colors[i]);
		printf("nb %i\n", nb);
		if (nb < 0 || nb >= 255)
			printf("erreur %i\n", nb);
		i++;
	}
	return (0);
}

int	check_rgb_floor(t_jeu *jeu)
{
	int	i;
	int	nb;

	i = 0;
	jeu->floor_colors = ft_split(jeu->directions[5][1], ',');
	while (jeu->floor_colors[i])
		i++;
	if (i != 3)
		return (printf("Error\nWith the floor's rgb value !\n"), 1);
	i = 0;
	while (i != 3)
	{
		nb = ft_atoi(jeu->ceiling_colors[i]);
		if (nb < 0 || nb >= 255)
			return (printf("Error\nWith the floor's rgb value !\n"), 1);
		i++;
	}
	return (0);
}

int	check_map_value(t_jeu *jeu)
{
	int	i;

	i = 0;
	while (jeu->value[i])
	{
		check_direction(jeu->value[i], jeu);
		i++;
	}
	i = 0;
	printf("splited :\n");
	while (i < 6)
	{
		if (!jeu->directions[i])
			return (printf("Error\nya un double jcrois %s !\n", "blabla"), 1);
		if (jeu->directions[i][2])
			return (printf("Error\nToo many instructions on the line %s !\n",
					"blabla"), 1);
		print_tab(jeu->directions[i]);
		i++;
	}
	check_rgb_ceiling(jeu);
	check_rgb_floor(jeu);
	return (0);
}

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t');
}

int	check_direction(char *str, t_jeu *jeu)
{
	int		i;
	static char	*tab[7] = {"NO", "SO", "EA", "WE", "C", "F"};

	i = 0;
	while (tab[i])
	{
		if (!ft_strncmp(str, tab[i], ft_strlen(tab[i]))
			&& ft_isspace(str[ft_strlen(tab[i])]))
		{
			jeu->directions[i] = ft_split(str, ' ');
		}
		i++;
	}
	return (0);
}
