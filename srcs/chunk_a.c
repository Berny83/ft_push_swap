/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 21:02:30 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/13 16:44:41 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_struct.h"
#include "push_swap.h"

static int	find_moves_a_last(t_stack *tmp, int median, int border)
{
	t_elem	*lst;
	int		j;

	j = 0;
	lst = tmp->last;
	while (tmp->last)
	{
		if (tmp->last->num < median && tmp->last->num >= border)
			break ;
		j++;
		tmp->last = tmp->last->prev;
	}
	tmp->last = lst;
	return (j);
}

int			find_moves_a(t_stack *tmp, int median, int border)
{
	int		i;
	int		j;
	t_elem	*fi;

	i = 0;
	j = 0;
	fi = tmp->first;
	while (tmp->first)
	{
		if (tmp->first->num < median && tmp->first->num >= border)
			break ;
		i++;
		tmp->first = tmp->first->next;
	}
	if (i != 0)
		j = find_moves_a_last(tmp, median, border);
	tmp->first = fi;
	if (i <= j)
		return (1);
	return (0);
}

void		check_b_nums(t_data *d)
{
	if (d->b.first->next)
	{
		if (d->b.first->num <= d->b.ch->val_median)
		{
			if (d->b.first->num > d->b.first->next->num)
				sb(d, 'b');
		}
		else
			rb(d, 'b');
	}
}

int			make_moves_a(t_data *d, int border, char c)
{
	int		i;

	i = 0;
	if (c == 'f')
	{
		if (d->a.first->num < d->a.ch->val_median && d->a.first->num >= border)
		{
			i += push_pr(d, 'b');
			check_b_nums(d);
		}
		else
			ra(d, 'a');
	}
	else
	{
		if (d->a.last->num < d->a.ch->val_median && d->a.last->num >= border)
		{
			rra(d, 'a');
			i += push_pr(d, 'b');
			check_b_nums(d);
		}
		else
			rra(d, 'a');
	}
	return (i);
}

void		solve_quarters_a(t_data *d, int border)
{
	int		i;

	i = 0;
	middle_chunk_b(d->b.ch, d->a.ch, d->elems);
	if (d->a.ch->lll)
		redo_chunks(d->a.ch, d->b.ch, d->elems);
	while (i < d->b.ch->size)
	{
		if (find_moves_a(&d->a, d->a.ch->val_median, border))
			i += make_moves_a(d, border, 'f');
		else
			i += make_moves_a(d, border, 'l');
	}
}
