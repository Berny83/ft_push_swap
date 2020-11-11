/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:55:24 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/09 20:45:24 by aagrivan         ###   ########.fr       */
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

void			rra(t_stack *a, char c)
{
	r_reverse(a);
	if (c == 'a')
		write(1, "rra\n", 4);
}

void			rrb(t_stack *b, char c)
{
	r_reverse(b);
	if (c == 'b')
		write(1, "rrb\n", 4);
}

void			rrr(t_stack *a, t_stack *b)
{
	rra(a, 0);
	rrb(b, 0);
	
	write(1, "rrr\n", 4);
}
