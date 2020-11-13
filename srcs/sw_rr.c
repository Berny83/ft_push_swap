/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:55:19 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/13 10:46:35 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_struct.h"
#include "push_swap.h"

static void		reverse(t_stack *tmp)
{
	if (tmp->size > 1)
	{
		tmp->first->prev = tmp->last;
		tmp->last->next = tmp->first;
		tmp->last = tmp->first;
		tmp->first = tmp->first->next;
		tmp->last->next = NULL;
		tmp->first->prev = NULL;
	}
}

int				ra(t_data *d, char c)
{
	reverse(&d->a);
	if (c == 'a')
		write(1, "ra\n", 3);
	return (1);
}

int				rb(t_data *d, char c)
{
	reverse(&d->b);
	if (c == 'b')
		write(1, "rb\n", 3);
	return (1);
}

int				rr(t_data *d, char c)
{
	ra(d, c);
	rb(d, c);
	if (c == 'c')
		write(1, "rr\n", 3);
	return (1);
}
