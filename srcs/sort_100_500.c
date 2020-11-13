/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100_500.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:52:25 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/13 16:36:11 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_struct.h"
#include "push_swap.h"

static int		size_chunk(int size)
{
	if (size <= 30)
		return (2);
	else if (size <= 100)
		return (5);
	else
		return (10);
}

static void		a_chunk(t_stack *a, t_elem **elems, int div)
{
	a->ch->split = div;
	a->ch->size = a->size;
	a->ch->pos_median = a->ch->size / a->ch->split;
	a->ch->val_median = elems[a->ch->pos_median]->num;
	a->ch->lll = 0;
}

void			new_a_chunk(t_chunk *a)
{
	a->lll = 1;
	a->size -= (a->size / a->split);
	a->split--;
}

t_bool			sorted_chunk(t_data *d)
{
	t_elem		*tmp;
	int			i;

	i = 0;
	tmp = d->a.first;
	while (++i < d->a.ch->size)
	{
		if (tmp->next->num < tmp->num)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

void			sort_100_500(t_data *d)
{
	int			div;
	int			border;

	border = d->elems[0]->num;
	div = size_chunk(d->a.size);
	a_chunk(&d->a, d->elems, div);
	while (d->a.ch->size)
	{
		if (sorted_chunk(d))
			d->a.ch->size = 0;
		else
		{
			while (d->a.size != 0)
			{
				solve_quarters_a(d, border);
				border = d->a.ch->val_median;
				new_a_chunk(d->a.ch);
			}
		}
		if (d->b.size != 0)
			solve_quarters_b(d);
	}
}
