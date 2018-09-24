/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shillebr <shillebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 16:41:59 by xeno              #+#    #+#             */
/*   Updated: 2018/09/24 13:04:51 by shillebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		draw_map(t_param *p)
{
	t_pnt	s;
	int		i;
	int		j;
	int		v;

	j = -1;
	while (++j < p->map->max_y)
	{
		i = -1;
		while (++i < p->map->max_x)
		{
			v = p->map->m[j][i] - '0';
			s = (t_pnt){(i * p->x_scale), (j * p->y_scale)};
			if (v > 0)
			{
				if (v == 1)
					draw_f_square(&s, p, 0xffffff);
				else if (v == 2)
					draw_f_square(&s, p, 0xffb612);
				else if (v == 3)
					draw_f_square(&s, p, 0xde3831);
				else if (v == 4)
					draw_f_square(&s, p, 0x002395);
				else if (v == 9)
					draw_f_square(&s, p, 0x00000);
				draw_f_square(&s, p, WALL_COL);
			}
			else
				draw_f_square(&s, p, 0x007a4d);
		}
	}
	p->player->m_pos.x = p->player->pos->x;
	p->player->m_pos.y = p->player->pos->y;
}
