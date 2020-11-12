/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_ss.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 12:34:47 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/12 21:38:02 by aagrivan         ###   ########.fr       */
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

int				sa(t_data *d, char c)
{
	swap(&d->a);
	if (c == 'a')
		write(1, "sa\n", 3);
	return (1);
}

int				sb(t_data *d, char c)
{
	swap(&d->b);
	if (c == 'b')
		write(1, "sb\n", 3);
	return (1);
}

int				ss(t_data *d, char c)
{
	sa(d, c);
	sb(d, c);
	if (c == 'c')
		write(1, "ss\n", 3);
	return (1);
}
