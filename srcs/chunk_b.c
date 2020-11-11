/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:46:17 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/11 22:54:05 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_struct.h"
#include "push_swap.h"

static int	find_smallest(t_elem *first)
{
	int		small;

	small = 0;
	while (first)
	{
		if (first->num < first->next->num)
			small = first->num;
		first = first->next;
	}
	return (small);
}

static int	find_moves_b(t_stack *b, int small)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (b->first)
	{
		if (b->first->num == small)
			break ;
		i++;
		b->first = b->first->next;
	}
	while (b->last)
	{
		if (b->last->prev == small)
			break ;
		j++;
		b->last = b->last->prev;
	}
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
			push(&d->b, &d->a, 'a');
			ra(&d->a, 'a');
		}
		rb(&d->b, 'b');
	}
	if (d->b.last->num == small)
	{
		rrb(&d->b, 'b');
		push(&d->b, &d->a, 'a');
		ra(&d->a, 'a');
	}
	rrb(&d->b, 'b');
}

void		solve_quarters_b(t_data *d)
{
	int		small;

	small = 0;
	while (d->b.size)
	{
		small = find_smallest(&d->b.first);
		if (find_moves_b(&d->b, small))
			make_moves_b(d, small, 'f');
		else
			make_moves_b(d, small, 'l');
	}
}