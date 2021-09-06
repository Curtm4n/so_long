/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 20:16:14 by cdapurif          #+#    #+#             */
/*   Updated: 2021/09/06 15:34:27 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	check_fl_line(t_info *info, char *str)
{
	while (*str)
	{
		if (*str != '1')
		{
			ft_putstr_fd("Error\nThe map isn't closed\n", 2);
			free_info(info);
			exit(EXIT_FAILURE);
		}
		str++;
	}
}

void	check_componant(t_info *info, char *str, int line_index)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == 'P')
		{
			info->player_pos[0] = i;
			info->player_pos[1] = line_index;
			info->player++;
		}
		if (str[i] == 'C')
			info->collectible++;
		if (str[i] == 'E')
			info->exit++;
	}
}
