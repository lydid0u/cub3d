/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:38:06 by lboudjel          #+#    #+#             */
/*   Updated: 2024/09/10 18:33:58 by lboudjel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_exit(t_jeu *jeu)
{
	free_tab(jeu->value);
	free_tab(jeu->map);
	free_tab(jeu->map_spaced);
	free_tab(jeu->ceiling_colors);
	free_tab(jeu->floor_colors);
	free_tab_tab(jeu->directions);
	free_tab(jeu->file_map);
}

int	parsing(char *file, t_jeu *jeu)
{
	if (filename(file))
		return (free_exit(jeu), 1);
	else if (copy_file(file, jeu))
		return (free_exit(jeu), 2);
	else if (copy_map_value(file, jeu))
		return (free_exit(jeu), 3);
	else if (check_map_value(jeu))
		return (free_exit(jeu), 4);
	else if (copy_game_map(jeu))
		return (free_exit(jeu), 5);
	else if (parsing_map(jeu))
		return (free_exit(jeu), 6);
	else if (error_handler(jeu))
		return (free_exit(jeu), 7);
	return (0);
}

int	main(int argc, char **argv)
{
	static t_jeu	jeu = {0};
	int				error;

	if (argc == 2)
	{
		error = parsing(argv[1], &jeu);
		if (error)
			return (printf("%i\n", error), 1);
		free_exit(&jeu);
	}
	else
		return (printf("Error\nArgs !\n"), 1);
	printf("a la fin\n");
	return (0);
}
//dans la fonction empty line rajouter tab aussi