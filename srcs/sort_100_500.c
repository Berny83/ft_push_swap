/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100_500.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:52:25 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/11 23:08:51 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_struct.h"
#include "push_swap.h"

t_bool			initiate_chunk(t_stack *tmp)
{
	t_chunk		*new;
	
	if (!tmp->ch || tmp->ch->size)
	{
		if (!(new = (t_chunk *)malloc(sizeof(t_chunk))))
			return (false);
		ft_memset(new, 0, sizeof(t_chunk));
		new->next = tmp->ch;
		tmp->ch = new;
	}
	return (true);
}

static void		a_chunk(t_stack *a, t_elem **elems)
{
	a->ch->split = 5;
	a->ch->size = a->size; //100
	a->ch->pos_median = a->ch->size / a->ch->split; //20
	a->ch->val_median = elems[a->ch->pos_median]->num; //elems[20] = 21
}
// 0-19 20-39 40-59 60-79 80-99
// if a.size < 20 then split is 2

void			sort_100_500(t_data *d)
{
	if (!initiate_chunk(&d->a))
		ft_exit(d, EXIT_FAILURE);
	a_chunk(&d->a, d->elems);
	while (d->a.ch->size)
	{
		if (sorted_chunk(d))
			d->a.ch->size = 0;
		else
			solve_quarters_a(d);
		if (d->b.ch->size != 0)
		{
			if (sorted_chunk(d))
				return_all_to_a(d);
			else
				solve_quarters_b(d);
		}
	}
}