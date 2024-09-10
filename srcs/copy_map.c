/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 18:53:45 by lboudjel          #+#    #+#             */
/*   Updated: 2024/09/10 19:16:48 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

//compte le nombre de ligne de la map 
void	count_line(char *file, t_jeu *jeu)
{
	int		fd;
	char	*line;

	jeu->nb_line_file = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return ;
	line = get_next_line(fd, 0);
	while (line)
	{
		if (line == NULL)
			break ;
		jeu->nb_line_file++;
		free(line);
		line = get_next_line(fd, 0);
	}
	free(line);
	close(fd);
}

//jcopie le fichier grace a gnl
int	copy_file(char *file, t_jeu *jeu)
{
	int		i;
	int		fd;
	char	*line;

	count_line(file, jeu);
	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1 || read(fd, &line, 0) < 0)
		return (printf("Error\nThere is an error with the file !\n"), 0);
	jeu->file_map = malloc(sizeof(char *) * (jeu->nb_line_file + 1));
	if (!jeu->file_map)
		return (free(line), close(fd), 1);
	while (1)
	{
		line = get_next_line(fd, 0);
		if (line == NULL)
			break ;
		jeu->file_map[i] = malloc(ft_strlen(line) + 1);
		if (!jeu->file_map[i])
			return (free(line), close(fd), 1);
		ft_strcpy(jeu->file_map[i], line);
		free(line);
		i++;
	}
	return (jeu->file_map[i] = NULL, close (fd), 0);
}

//jcopie la map du jeu
int	copy_game_map(t_jeu *jeu)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	//redecouper ca en une autre fonction imo
	while (jeu->file_map[i])
	{
		if (!ft_strncmp(jeu->file_map[i], jeu->value[5],
				ft_strlen(jeu->value[5])))
		{
			i++;
			count++;
			break ;
		}
		count++;
		i++;
	}
	jeu->map = malloc(sizeof(char *) * ((jeu->nb_line_file - count) + 1));
	while (jeu->file_map[i])
	{
		if (jeu->file_map[i] && !empty_line(jeu->file_map[i]))
		{
			if (ft_strlen(jeu->file_map[i]) > jeu->longest_line)
				jeu->longest_line = ft_strlen(jeu->file_map[i]);
			jeu->map[j++] = ft_strdup(jeu->file_map[i]);
			jeu->nb_line_map++;
		}
		i++;
	}
	jeu->map[j] = NULL;
	return (0);
}
