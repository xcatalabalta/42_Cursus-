/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3d.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatala- <fcatala-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:49:01 by mvisca            #+#    #+#             */
/*   Updated: 2025/02/26 14:43:30 by fcatala-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// void cub_debug_structraw(t_cub3d *cub)
// {
// 	printf("-------------------------\n");
// 	printf("DEBUG: t_cub3d Err Msg\n");
// 	printf("-------------------------\n");

// 	for (int i = 0; cub->err_msg[i]; i++)
// 	{
// 		printf("%s\n", cub->err_msg[i]);
// 	}

// 	printf("-------------------------\n");
// 	printf("DEBUG: t_cub3d raw\n");
// 	printf("-------------------------\n");

// 	int j;
// 	j = 0;
// 	while (cub->raw_args && cub->raw_args[j])
// 		printf("%s\n", cub->raw_args[j++]);

// 	j = 0;
// 	while (cub->raw_map && cub->raw_map[j])
// 		printf("%s\n", cub->raw_map[j++]);
// }

// void cub_debug_struct(t_cub3d *cub)
// {
// 	printf("-------------------------\n");
// 	printf("DEBUG: t_cub3d Err Msg\n");
// 	printf("-------------------------\n");

// 	for (int i = 0; cub->err_msg[i]; i++)
// 	{
// 		printf("ErrMsg:\n");
// 		printf("%s\n", cub->err_msg[i]);
// 	}

// 	printf("-------------------------\n");
// 	printf("DEBUG: t_cub3d Structure\n");
// 	printf("-------------------------\n");

// 	// Texturas
// 	printf("Textures:\n");
// 	printf("  North: %s\n", cub->north ? cub->north : "(null)");
// 	printf("  South: %s\n", cub->south ? cub->south : "(null)");
// 	printf("  West:  %s\n", cub->west ? cub->west : "(null)");
// 	printf("  East:  %s\n", cub->east ? cub->east : "(null)");

// 	// Colores
// 	printf("Colors:\n");
// 	printf("  Floor: R=%d G=%d B=%d\n", cub->floor[0], cub->floor[1],
//			cub->floor[2]);
// 	printf("  Ceiling: R=%d G=%d B=%d\n", cub->ceiling[0], cub->ceiling[1],
//			cub->ceiling[2]);

// 	// Dimensiones del Mapa
// 	printf("Map Dimensions:\n");
// 	printf("  Width: %d\n", cub->mw);
// 	printf("  Height: %d\n", cub->mh);

// 	printf("Player Position:\n");
// 	printf("  X: %d\n", cub->px);
// 	printf("  Y: %d\n", cub->py);
// 	printf("  Orientation: %c\n", cub->po);
// }

void	show_map(char **map)
{
	int	i;

	i = 0;
	printf("Start show map\n");
	while (map && map[i])
	{
		printf("<%s>\n", map[i]);
		i++;
	}
	printf("Fin show map\n");
}

int	main(int ac, char **av)
{
	t_cub3d	cub;

	if (ac != 2 || !av[1])
	{
		printf("Error\nTry: './cub3d <map.cub>'");
		return (0);
	}
	if (!init(&cub))
		error_exit(&cub, "Init failed.");
	if (!parse(&cub, av[1]))
		error_exit(&cub, "Parse failed.");
	if (!validate(&cub))
		error_exit(&cub, "Validation failed.");
	show_map(cub.map);
	cub_run(&cub);
	free_all(&cub);
	return (0);
}
