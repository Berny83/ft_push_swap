/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 11:54:24 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/12 21:01:13 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_struct.h"
#include "push_swap.h"

static void	sort_5_extend(t_data *d)
{
	int		i;

	i = d->a.size - 3;
	while (i-- > 0)
		push_pr(d, 'b');
	i = d->b.size;
	sort_3(d);
	while (i-- > 0)
	{
		push_pr(d, 'a');
		if (d->a.first->num > d->a.last->num)
			ra(d, 'a');
	}
}

void		sort_3(t_data *d)
{
	if ((d->a.first->num > d->a.first->next->num &&\
	d->a.last->num < d->a.first->next->num) ||\
	d->a.first->num < d->a.last->num)
		sa(d, 'a');
	if (d->a.first->num > d->a.last->num &&\
	d->a.first->num > d->a.first->next->num)
		ra(d, 'a');
	if (d->a.first->num > d->a.last->num &&\
	d->a.first->num < d->a.first->next->num)
		rra(d, 'a');
}

void		sort_5(t_data *d)
{
	if (d->a.size <= 2)
	{
		if (d->a.first->num > d->a.first->next->num)
			sa(d, 'a');
	}
	else if (d->a.size == 3)
		sort_3(d);
	else if (d->a.size <= 5)
		sort_5_extend(d);
}
