/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 14:22:48 by cdapurif          #+#    #+#             */
/*   Updated: 2021/09/10 16:05:58 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	minimize_event(void *info)
{
	display_map((t_info *)info);
	return (0);
}

int	close_game(void *info)
{
	quit_game((t_info *)info);
	return (0);
}
