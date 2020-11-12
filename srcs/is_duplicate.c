/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_duplicate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:57:42 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/12 20:52:02 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_struct.h"
#include "push_swap.h"

static t_bool	is_duplicate(t_data *d)
{
	int			i;

	i = 1;
	while (i < d->a.size)
	{
		if (d->elems[i]->num == d->elems[i - 1]->num)
			return (true);
		i++;
	}
	return(false);
}

static void		sorting(t_data *d)
{
	t_bool		sorted;
	t_elem		*curr;
	int			i;
	int			j;

	j = -1;
	sorted = 0;
	while (++j < d->a.size && !sorted)
	{
		i = 1;
		sorted = 1;
		while (i < d->a.size)
		{
			if (d->elems[i]->num < d->elems[i - 1]->num)
			{
				curr = d->elems[i];
				d->elems[i] = d->elems[i - 1];
				d->elems[i - 1] = curr;
				sorted = 0;
			}
			i++;
		}
	}
}

void			parse_duplicate(t_data *d)
{
	int			i;
	t_elem		*curr;

	i = 0;
	curr = d->a.first;
	while (i < d->a.size)
	{
		d->elems[i] = curr;
		curr = curr->next;
		i++;
	}
	sorting(d);
	if (is_duplicate(d))
		ft_exit(d, EXIT_FAILURE);
}
