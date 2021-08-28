/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 19:42:03 by cdapurif          #+#    #+#             */
/*   Updated: 2021/08/21 22:32:23 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_info(t_info *info)
{
	if (info->map_ptr)
		ft_lstclear(&(info->map_ptr), &free);
	if (info->mlx_ptr)
	{
		if (info->window_ptr)
			mlx_destroy_window(info->mlx_ptr, info->window_ptr);
		free_texture(info->mlx_ptr, info->fl_texture);
		free_texture(info->mlx_ptr, info->wa_texture);
		free_texture(info->mlx_ptr, info->pl_texture);
		free_texture(info->mlx_ptr, info->co_texture);
		free_texture(info->mlx_ptr, info->ex_texture);
		mlx_destroy_display(info->mlx_ptr);
		free(info->mlx_ptr);
	}
	free(info);
}

void	close_error(char *line, t_info *info)
{
	if (line)
		free(line);
	free_info(info);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

int	correct_map_char(char *line)
{
	while (*line)
	{
		if (*line != '0' && *line != '1' && *line != 'C' && *line != 'E' \
			&& *line != 'P')
		{
			return (0);
		}
		line++;
	}
	return (1);
}

void	check_borders(t_info *info, t_list *tmp, int len, int size)
{
	int		line;
	char	*str;

	line = 1;
	while (tmp)
	{
		str = (char *)tmp->content;
		if (str[0] != '1' || str[len - 1] != '1')
		{
			ft_putstr_fd("Error\nThe map isn't closed\n", 2);
			free_info(info);
			exit(EXIT_FAILURE);
		}
		if (line == 1 || line == size)
			check_fl_line(info, str);
		if (line > 1 && line < size)
			check_componant(info, str, line - 1);
		tmp = tmp->next;
		line++;
	}
}

void	parse_map(t_info *info)
{
	int		len;
	t_list	*tmp;

	tmp = info->map_ptr;
	len = ft_strlen((char *)tmp->content);
	while (tmp)
	{
		if (ft_strlen((char *)tmp->content) != len)
		{
			ft_putstr_fd("Error\nThe map isn't rectangular\n", 2);
			free_info(info);
			exit(EXIT_FAILURE);
		}
		if (!correct_map_char((char *)tmp->content))
		{
			ft_putstr_fd("Error\nThe map contain bad character(s)\n", 2);
			free_info(info);
			exit(EXIT_FAILURE);
		}
		tmp = tmp->next;
	}
	check_borders(info, info->map_ptr, len, ft_lstsize(info->map_ptr));
}
