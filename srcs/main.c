/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:38:06 by lboudjel          #+#    #+#             */
/*   Updated: 2024/09/07 21:29:12 by lboudjel         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	static t_jeu	jeu = {0};

	if (argc == 2)
	{
		if (filename(argv[1]))
			return (printf("la 1"), 1);
		else if (copy_file(argv[1], &jeu))
			return (printf("la 2"), 1);
		else if (copy_map_value(argv[1], &jeu))
			return (printf("la 3"), 1);
		else if (check_map_value(&jeu))
			return (printf("la 4"), 1);
		else if (copy_game_map(&jeu))
			return (printf("la 5"), 1);
		else if (parsing_map(&jeu))
			return (printf("la 6"), 1);
		else if (error_handler(&jeu))
			return (printf("la 7"), 1);
	}
	else
		return (printf("Error\nArgs !\n"), 1);
	printf("la");
	free_exit(&jeu);
	return (0);
}
//dans la fonction empty line rajouter tab aussi