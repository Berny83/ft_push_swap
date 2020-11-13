/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 17:27:17 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/13 16:01:58 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_struct.h"
#include "push_swap.h"

void		clean(t_data *d)
{
	t_elem	*curr;

	curr = d->a.first;
	while (curr)
	{
		d->a.last = curr;
		curr = curr->next;
		free(d->a.last);
	}
	d->a.first = NULL;
	d->a.last = NULL;
	if (d->elems)
	{
		free(d->elems);
		d->elems = NULL;
	}
	if (d->a.ch || d->b.ch)
		clean_chunk(d);
}

void		clean_chunk(t_data *d)
{
	free(d->a.ch);
	d->a.ch = NULL;
	free(d->b.ch);
	d->b.ch = NULL;
}

void		ft_error(t_data *d, char **s)
{
	free(*s);
	free(s);
	ft_exit(d, EXIT_FAILURE);
}

void		ft_exit(t_data *d, int code)
{
	ft_printf(ERR);
	clean(d);
	exit(code);
}
