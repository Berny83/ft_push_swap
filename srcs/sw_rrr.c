/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:55:24 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/12 21:38:36 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_struct.h"
#include "push_swap.h"

static void		r_reverse(t_stack *tmp)
{
	if (tmp->size > 1)
	{
		tmp->first->prev = tmp->last;
		tmp->first->prev->next = tmp->first;
		tmp->last = tmp->last->prev;
		tmp->first->prev->prev = NULL;
		tmp->last->next = NULL;
		tmp->first = tmp->first->prev;
	}
}

int				rra(t_data *d, char c)
{
	r_reverse(&d->a);
	if (c == 'a')
		write(1, "rra\n", 4);
	return (1);
}

int				rrb(t_data *d, char c)
{
	r_reverse(&d->b);
	if (c == 'b')
		write(1, "rrb\n", 4);
	return (1);
}

int				rrr(t_data *d, char c)
{
	rra(d, c);
	rrb(d, c);
	if (c == 'c')
		write(1, "rrr\n", 4);
	return (1);
}
