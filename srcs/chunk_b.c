/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:46:17 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/13 18:59:44 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_struct.h"
#include "push_swap.h"

int			find_smallest(t_elem *first)
{
	int		small;

	small = first->num;
	while (first)
	{
		if (small > first->num)
			small = first->num;
		first = first->next;
	}
	return (small);
}

int			find_moves_b_last(t_stack *b, int small)
{
	t_elem	*lst;
	int		j;

	j = 0;
	lst = b->last;
	while (b->last)
	{
		if (b->last->num == small)
			break ;
		j++;
		b->last = b->last->prev;
	}
	b->last = lst;
	return (j);
}

int			find_moves_b(t_stack *b, int small)
{
	int		i;
	int		j;
	t_elem	*fi;

	i = 0;
	j = 0;
	fi = b->first;
	while (b->first)
	{
		if (b->first->num == small)
			break ;
		i++;
		b->first = b->first->next;
	}
	if (i != 0)
		j = find_moves_b_last(b, small);
	b->first = fi;
	if (i <= j)
		return (1);
	return (0);
}

void		make_moves_b(t_data *d, int small, char c)
{
	if (c == 'f')
	{
		if (d->b.first->num == small)
		{
			push_pr(d, 'a');
			ra(d, 'a');
		}
		else
			rb(d, 'b');
	}
	else
	{
		if (d->b.last->num == small)
		{
			rrb(d, 'b');
			push_pr(d, 'a');
			ra(d, 'a');
		}
		else
			rrb(d, 'b');
	}
}

void		solve_quarters_b(t_data *d)
{
	int		small;

	small = 0;
	while (d->b.size)
	{
		small = find_smallest(d->b.first);
		if (find_moves_b(&d->b, small))
			make_moves_b(d, small, 'f');
		else
			make_moves_b(d, small, 'l');
	}
}
