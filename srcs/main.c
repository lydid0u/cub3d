/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboudjel <lboudjel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:38:06 by lboudjel          #+#    #+#             */
/*   Updated: 2024/08/31 19:57:43 by lboudjel         ###   ########.fr       */
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
		parsing(argv[1]);
		copy_map_value(argv[1], &jeu);
		count_line(argv[1], &jeu);
		check_map_value(&jeu);
		copy_game_map(argv[1], &jeu);
	}
	else
	{
		printf("Erreur avec les arguments !\n");
		return (1);
	}
	// free_exit(&jeu);
}
//dans la fonction empty line rajouter tab aussi