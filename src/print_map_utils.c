/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:11:35 by prafael-          #+#    #+#             */
/*   Updated: 2021/12/02 14:56:55 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_img(t_module *module, void *sprite)
{
	mlx_put_image_to_window (module->vars->mlx, module->vars->win, sprite,
		SPRITE_SIZE * module->map->col,
		SPRITE_SIZE * module->map->row);
}

static void	position_player(t_module *module)
{
	put_img(module, module->sprite->player[module->player->player_eye]);
	module->player->player_x = module->map->col;
	module->player->player_y = module->map->row;
}

static void	coin_print(t_module *module)
{
	module->coin->amount = module->coin->amount + 1;
	put_img(module, module->sprite->collect);
}

static void	enemines_print(t_module *module)
{
	int	col;

	col = module->map->col - module->player->player_x;
	if (abs(col) <= 3)
	{
		if (module->map->row <= module->player->player_y)
			put_img(module, module->sprite->enemies[0]);
		else
			put_img(module, module->sprite->enemies[3]);
	}
	else
	{
		if (module->map->col <= module->player->player_x)
			put_img(module, module->sprite->enemies[2]);
		else
			put_img(module, module->sprite->enemies[1]);
	}
}

int	choose_sprite(char *line, t_module *module)
{
	if (line[module->map->col] == '0')
		put_img(module, module->sprite->ground);
	else if (line[module->map->col] == '1')
		put_img(module, module->sprite->wall);
	else if (line[module->map->col] == 'C')
		coin_print(module);
	else if (line[module->map->col] == 'E')
		put_img(module, module->sprite->exit);
	else if (line[module->map->col] == 'P')
		position_player(module);
	else if (line[module->map->col] == 'J')
		enemines_print(module);
	else
		return (1);
	return (0);
}
