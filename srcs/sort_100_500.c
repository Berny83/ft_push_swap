/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100_500.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 15:52:25 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/13 11:58:14 by aagrivan         ###   ########.fr       */
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
}//500-9-10

static void		a_chunk(t_stack *a, t_elem **elems, int div)
{
	a->ch->split = div;
	a->ch->size = a->size; //100
	a->ch->pos_median = a->ch->size / a->ch->split; //20
	a->ch->val_median = elems[a->ch->pos_median]->num; //elems[20] = 21
	a->ch->lll = 0;
}
// 0-19 20-39 40-59 60-79 80-99

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
	int	border;

	border = d->elems[0]->num;
	div = size_chunk(d->a.size);
	if (!initiate_chunk(&d->a))
		ft_exit(d, EXIT_FAILURE);
	if (!initiate_chunk(&d->b))
		ft_exit(d, EXIT_FAILURE);
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
