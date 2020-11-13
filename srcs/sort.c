/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 22:46:25 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/13 09:52:38 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_struct.h"
#include "push_swap.h"

t_bool			is_sorted(t_data *d)
{
	t_elem		*curr;
	
	curr = d->a.first;
	if (!d->a.first || d->b.first)
		return (false);
	while (curr && curr->next)
	{
		if (curr->num > curr->next->num)
			return (false);
		curr = curr->next;
	}
	return (true);
}

void			sort(t_data *d)
{
	while (!is_sorted(d))
	{
		if (d->a.size <= 5)
			sort_5(d);
		else
		{
			sort_100_500(d);
			clean_chunk(d);
		}
	}
}