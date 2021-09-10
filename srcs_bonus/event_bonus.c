/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 14:22:48 by cdapurif          #+#    #+#             */
/*   Updated: 2021/09/10 16:14:46 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

unsigned short	nb_len(int nb)
{
	unsigned short	i;

	i = 1;
	while (nb > 9)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

int	minimize_event(void *info)
{
	display_map((t_info *)info, 0);
	return (0);
}

int	close_game(void *info)
{
	quit_game((t_info *)info);
	return (0);
}
