/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sw_pp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:55:22 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/13 17:11:12 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_struct.h"
#include "push_swap.h"

static int		add_top_element(t_stack *tmp, int n)
{
	t_elem		*new;

	if (!(new = (t_elem*)malloc(sizeof(t_elem))))
		return (0);
	new->num = n;
	new->next = tmp->first;
	new->prev = NULL;
	if (!tmp->last)
		tmp->last = new;
	if (tmp->first)
		tmp->first->prev = new;
	tmp->first = new;
	tmp->size++;
	return (1);
}

static int		del_top_element(t_stack *tmp)
{
	t_elem		*del;

	if (tmp)
	{
		del = tmp->first;
		if (tmp->size > 1)
		{
			tmp->first = tmp->first->next;
			tmp->first->prev = NULL;
		}
		tmp->size--;
		free(del);
		del = NULL;
	}
	return (tmp->size);
}

int				push(t_stack *fi, t_stack *sec, char c)
{
	long int	tmp;

	tmp = fi->first->num;
	if (fi)
	{
		if (!del_top_element(fi))
		{
			fi->first = NULL;
			fi->last = NULL;
		}
		if (!add_top_element(sec, tmp))
			return (0);
	}
	(c == 'b') ? ft_putendl("pb") : 0;
	(c == 'a') ? ft_putendl("pa") : 0;
	return (1);
}

int				push_pr(t_data *d, char c)
{
	if (c == 'b' || c == 'e')
	{
		if (!push(&d->a, &d->b, c))
			ft_exit(d, EXIT_FAILURE);
	}
	else if (c == 'a' || c == 'd')
	{
		if (!push(&d->b, &d->a, c))
			ft_exit(d, EXIT_FAILURE);
	}
	return (1);
}
