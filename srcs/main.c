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
		int z = 0;
		
		z = error_handler(&jeu);
		if (z)
			printf("c la merde chef: %i\n", z);
	}
	else
	{
		printf("Erreur avec les arguments !\n");
		return (1);
	}
}
	// free_exit(&jeu);
//dans la fonction empty line rajouter tab aussi