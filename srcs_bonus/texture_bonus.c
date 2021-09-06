/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 20:25:28 by cdapurif          #+#    #+#             */
/*   Updated: 2021/09/06 15:19:03 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	free_texture(void *mlx_ptr, t_texture *texture)
{
	if (texture)
	{
		if (texture->texture)
		{
			mlx_destroy_image(mlx_ptr, texture->texture);
			texture->texture = NULL;
		}
		free(texture);
	}
}

t_texture	*get_texture(char *file, t_info *info)
{
	t_texture	*img;

	img = ft_calloc(1, sizeof(t_texture));
	if (!img)
		close_error(NULL, info);
	img->texture = mlx_xpm_file_to_image(info->mlx_ptr, file, \
	&img->width, &img->height);
	return (img);
}

void	load_textures(t_info *info)
{
	info->mlx_ptr = mlx_init();
	if (!info->mlx_ptr)
		close_error(NULL, info);
	info->fl_texture = get_texture("./res/floor.xpm", info);
	info->wa_texture = get_texture("./res/wall.xpm", info);
	info->left_texture = get_texture("./res/player_rev.xpm", info);
	info->right_texture = get_texture("./res/player.xpm", info);
	info->pl_texture = ft_calloc(1, sizeof(t_texture));
	if (!info->pl_texture)
		close_error(NULL, info);
	info->pl_texture->texture = info->right_texture->texture;
	info->co_texture = get_texture("./res/collectible.xpm", info);
	info->ex_texture = get_texture("./res/exit.xpm", info);
}
