/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 11:54:24 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/14 12:26:27 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_struct.h"
#include "push_swap.h"

static t_bool	is_sorted_3(t_data *d)
{
	t_elem		*curr;

	curr = d->a.first;
	if (!d->a.first)
		return (false);
	while (curr && curr->next)
	{
		if (curr->num > curr->next->num)
			return (false);
		curr = curr->next;
	}
	return (true);
}

static void	make_moves_5(t_data *d, int small, char c)
{
	if (c == 'f')
	{
		if (d->a.first->num == small)
			push_pr(d, 'b');
		else
			ra(d, 'a');
	}
	else
	{
		if (d->a.last->num == small)
		{
			rra(d, 'a');
			push_pr(d, 'b');
		}
		else
			rra(d, 'a');
	}
}

static void	sort_5_extend(t_data *d)
{
	int		i;
	int		small;

	i = 2;
	small = 0;
	while (d->a.size != 3)
	{
		small = find_smallest(d->a.first);
		if (find_moves_b(&d->a, small))
			make_moves_5(d, small, 'f');
		else
			make_moves_5(d, small, 'l');
	}
	sort_3(d);
	while (i--)
		push_pr(d, 'a');
}

void		sort_3(t_data *d)
{
	if (!is_sorted_3(d))
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
