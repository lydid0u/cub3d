/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:38:06 by lboudjel          #+#    #+#             */
/*   Updated: 2024/09/06 19:47:03 by lboudjel         ###   ########.fr       */
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
		filename(argv[1]);
		copy_file(argv[1], &jeu);
		copy_map_value(argv[1], &jeu);
		check_map_value(&jeu);
		copy_game_map(&jeu);
		parsing_map(&jeu);
		if (error_handler(&jeu))
			return(1);
	}
	else
	{
		printf("Erreur avec les arguments !\n");
		return (1);
	}
	free_exit(&jeu);
	return (0);
}
//dans la fonction empty line rajouter tab aussi