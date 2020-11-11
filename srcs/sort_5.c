/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 11:54:24 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/10 16:33:13 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_struct.h"
#include "push_swap.h"

static void	sort_5_extend(t_data *d)
{
	int		i;

	i = d->a.size - 3;
	while (3 < i--)
		if (!push(&d->a, &d->b, 'b'))
			ft_exit(d, EXIT_FAILURE);
	i = d->b.size;
	sort_3(d);
	while (i-- > 0)
	{
		if (!push(&d->b, &d->a, 'a'))
			ft_exit(d, EXIT_FAILURE);
		if (d->a.first->num > d->a.last->num)
			ra(&d->a, 'a');
	}
}

void		sort_3(t_data *d)
{
	if ((d->a.first->num > d->a.first->next->num &&\
	d->a.last->num < d->a.first->next->num) ||\
	d->a.first->num < d->a.last->num)
		sa(&d->a, 'a');
	if (d->a.first->num > d->a.last->num &&\
	d->a.first->num > d->a.first->next->num)
		ra(&d->a, 'a');
	if (d->a.first->num > d->a.last->num &&\
	d->a.first->num < d->a.first->next->num)
		rra(&d->a, 'a');
}

void		sort_5(t_data *d)
{
	if (d->a.size <= 2)
	{
		if (d->a.first->num > d->a.first->next->num)
			sa(&d->a, 'a');
	}
	else if (d->a.size == 3)
		sort_3(d);
	else if (d->a.size <= 5)
		sort_5_extend(d);
}
