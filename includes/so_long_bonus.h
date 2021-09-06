/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <cdapurif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 17:44:50 by cdapurif          #+#    #+#             */
/*   Updated: 2021/09/06 16:23:57 by cdapurif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define BUFFER_SIZE 128

# include "../lib/libft/libft.h"
# include "../lib/mlx/mlx.h"
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/errno.h>

typedef struct s_texture
{
	int		width;
	int		height;
	void	*texture;
}				t_texture;

typedef struct s_info
{
	void			*mlx_ptr;
	void			*window_ptr;
	t_list			*map_ptr;
	unsigned int	player;
	unsigned int	collectible;
	unsigned int	exit;
	unsigned int	player_pos[2];
	t_texture		*fl_texture;
	t_texture		*pl_texture;
	t_texture		*left_texture;
	t_texture		*right_texture;
	t_texture		*wa_texture;
	t_texture		*co_texture;
	t_texture		*ex_texture;
}				t_info;

t_info			*ft_parsing(char *map);
void			free_info(t_info *info);
void			close_error(char *line, t_info *info);
int				get_next_line(int fd, char **line);
int				ft_strlen(char *str);
int				check_line(char *str);
char			*ft_substr_free(char *s, int start, int len, int set);
char			*ft_strjoin_free(char *s1, char *s2, int free);
void			parse_map(t_info *info);
void			check_fl_line(t_info *info, char *str);
void			check_componant(t_info *info, char *str, int line_index);
void			ft_display(t_info *info);
void			quit_game(t_info *info);
int				close_game(void *info);
void			load_textures(t_info *info);
void			free_texture(void *mlx_ptr, t_texture *texture);
void			display_map(t_info *info, int move);
t_texture		*get_texture(char *file, t_info *info);
unsigned short	nb_len(int nb);

#endif
