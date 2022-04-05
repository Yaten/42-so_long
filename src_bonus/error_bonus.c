/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:45:38 by prafael-          #+#    #+#             */
/*   Updated: 2021/12/02 17:42:49 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	clear_map(t_map *map)
{
	close(map->fd);
	while (map->height--)
		free_ptr((void **)&map->map[map->height]);
	free_ptr((void **)&map->map);
	free_ptr((void **)&map);
}

void	close_window(t_module *module)
{
	int	i;

	i = -1;
	mlx_destroy_image(module->vars->mlx, module->sprite->collect);
	mlx_destroy_image(module->vars->mlx, module->sprite->wall);
	mlx_destroy_image(module->vars->mlx, module->sprite->ground);
	mlx_destroy_image(module->vars->mlx, module->sprite->exit);
	while (++i < 4)
		mlx_destroy_image(module->vars->mlx, module->sprite->player[i]);
	i = -1;
	while (++i < 4)
		mlx_destroy_image(module->vars->mlx, module->sprite->enemies[i]);
	free_ptr((void **)&module->sprite->player);
	free_ptr((void **)&module->sprite->enemies);
	free_ptr((void **)&module->sprite);
	mlx_destroy_window(module->vars->mlx, module->vars->win);
	mlx_destroy_display(module->vars->mlx);
	free_ptr((void **)&module->vars->mlx);
	free_ptr((void **)&module->vars);
}

int	close_all(t_module *module)
{
	close_window(module);
	clear_map(module->map);
	free_ptr((void **)&module->player);
	free_ptr((void **)&module->coin);
	free_ptr((void **)&module);
	exit(0);
	return (0);
}

int	error(int errnum, char *message)
{
	ft_printf("\033[31mError\n\033[35m\t");
	if (errnum > 0 && message != NULL)
		ft_printf("%s:%s\n", message, strerror(errnum));
	else
		perror(strerror(26));
	ft_printf("\033[0m");
	return (-1);
}
