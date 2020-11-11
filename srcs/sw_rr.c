/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:55:19 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/11 16:44:02 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_struct.h"
#include "push_swap.h"

static void		reverse(t_stack *tmp)
{
	if (tmp->size > 1)
	{
		tmp->last->next = tmp->first;
		tmp->last->next->prev = tmp->last;
		tmp->first = tmp->first->next;
		tmp->last->next->next = NULL;
		tmp->first->prev = NULL;
		tmp->last = tmp->last->next;
	}
}

void			ra(t_stack *a, char c)
{
	reverse(a);
	if (c == 'a')
		write(1, "ra\n", 3);
}

void			rb(t_stack *b, char c)
{
	reverse(b);
	if (c == 'b')
		write(1, "rb\n", 3);
}

void			rr(t_stack *a, t_stack *b)
{
	ra(a, 0);
	rb(b, 0);
	
	write(1, "rr\n", 3);
}
