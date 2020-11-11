/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 12:34:47 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/09 20:07:59 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_struct.h"
#include "push_swap.h"

static void		swap(t_stack *tmp)
{
	if (tmp->size > 1)
	{
		tmp->first->prev = tmp->first->next;
		tmp->first->next = tmp->first->next->next;
		if (tmp->first->next)
			tmp->first->next->prev = tmp->first;
		tmp->first->prev->prev = NULL;
		tmp->first->prev->next = tmp->first;
		tmp->first = tmp->first->prev;
		if (tmp->size == 2)
			tmp->last = tmp->last->next;
	}
}

void			sa(t_stack *a, char c)
{
	swap(a);
	if (c == 'a')
		write(1, "sa\n", 3);
}

void			sb(t_stack *b, char c)
{
	swap(b);
	if (c == 'b')
		write(1, "sb\n", 3);
}

void			ss(t_stack *a, t_stack *b)
{
	sa(a, 0);
	sb(b, 0);
	write(1, "ss\n", 3);
}
