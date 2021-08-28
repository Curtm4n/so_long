/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 16:06:20 by cdapurif          #+#    #+#             */
/*   Updated: 2021/08/25 15:08:32 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	quit_game(t_info *info)
{
	ft_putstr_fd("Goodbye ! hope we'll see you soon\n", 1);
	free_info(info);
	exit(EXIT_SUCCESS);
}

void	display_good_texture(t_info *info, char c, int pos, int line)
{
	if (c == '0')
	{
		mlx_put_image_to_window(info->mlx_ptr, info->window_ptr, \
		info->fl_texture->texture, pos, line);
	}
	if (c == '1')
	{
		mlx_put_image_to_window(info->mlx_ptr, info->window_ptr, \
		info->wa_texture->texture, pos, line);
	}
	if (c == 'P')
	{
		mlx_put_image_to_window(info->mlx_ptr, info->window_ptr, \
		info->pl_texture->texture, pos, line);
	}
	if (c == 'C')
	{
		mlx_put_image_to_window(info->mlx_ptr, info->window_ptr, \
		info->co_texture->texture, pos, line);
	}
	if (c == 'E')
	{
		mlx_put_image_to_window(info->mlx_ptr, info->window_ptr, \
		info->ex_texture->texture, pos, line);
	}
}

void	display_line(t_info *info, char *str, int line)
{
	int	pos;

	pos = 0;
	while (*str)
	{
		display_good_texture(info, *str, pos, line);
		str++;
		pos += 32;
	}
}

void	display_map(t_info *info)
{
	int		line;
	t_list	*tmp;

	line = 0;
	tmp = info->map_ptr;
	while (tmp)
	{
		display_line(info, (char *)tmp->content, line);
		tmp = tmp->next;
		line += 32;
	}
}
