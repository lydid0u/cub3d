/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 18:53:45 by lboudjel          #+#    #+#             */
/*   Updated: 2024/08/31 20:09:58 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	count_line(char *file, t_jeu *jeu)
{
	int	i;
	int fd;
	char *line;
	
	i = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("line [%i], %s", i, line);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	jeu->nb_line_file = i;
	printf("NB LINE FILE %i\n", jeu->nb_line_file);
}
int	copy_game_map(char *file, t_jeu *jeu)
{
	int	i;
	int count;
	int fd;
	char *line;
	(void)jeu;
	
	i = 0;
	count = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("la\n");
		if (!ft_strncmp(line, jeu->value[5], ft_strlen(jeu->value[5])))
		{
			count++;
			free(line);
			line = get_next_line(fd);
			break;
		}
		count++;
		free(line);
		line = get_next_line(fd);
	}
	jeu->map = malloc (sizeof(char *) * (jeu->nb_line_file - count) + 1);
	printf("count %i where %i\n", count, (jeu->nb_line_file - count));
	while (line)
	{
		if (line && !empty_line(line))
		{
			jeu->map[i] = ft_strdup(line);
			printf("[%i] %s\n", i, line);
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	print_tab(jeu->map);
	return 1;
}