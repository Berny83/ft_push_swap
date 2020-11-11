/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 21:02:30 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/11 23:05:06 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_struct.h"
#include "push_swap.h"

// static void	middle_chunk_b(t_chunk *b, t_chunk *a, t_elem **elems)
// {
// 	b->size = a->size / b->split; //20 //20 //20 //20
// 	b->pos_median = a->pos_median; //20 //40 //60 //80
// 	b->val_median = elems[b->pos_median]->num;  //elems[20] = 21//elems[40] = 40 //60
// 	b->split = a->split; //4 //3 //2 //1
// }

static void	new_a_chunk(t_chunk *a, t_elem **elems)
{
	a->pos_median += (a->size / a->split); // 40 + 60/3=60//100
	a->size -= (a->size / a->split); //80 //60 //40 //20
	a->val_median = elems[a->pos_median]->num; //elems[40] = 40 //elems[60] = 60
	a->split--; //4 //3 //2
}

int			find_moves_a(t_stack *tmp, int median, int border)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tmp->first)
	{
		if (tmp->first->num < median && tmp->first->num >= border)
			break ;
		i++;
		tmp->first = tmp->first->next;
	}
	while (tmp->last)
	{
		if (tmp->last->num < median && tmp->last->num >= border)
			break ;
		j++;
		tmp->last = tmp->last->prev;
	}
	if (i <= j)
		return (1);
	return (0);
}

void		check_b_nums(t_data *d)
{
	if (&d->b.first)
	{
		if (d->b.first->num > d->b.first->next->num)
			rb(&d->b, 'b');
	}
}

int			make_moves(t_data *d, int border)
{
	int		i;

	i = 0;
	if (find_moves_a(&d->a, d->a.ch->val_median, border))//20
	{
		if (d->a.first->num < d->a.ch->val_median && d->a.first->num >= border)
		{
			i += push(&d->a, &d->b, 'b');
			check_b_nums(d);
		}
		ra(&d->a, 'a');
	}
	else
	{
		if (d->a.last->num < d->a.ch->val_median && d->a.last->num >= border)
		{
			rra(&d->a, 'a');
			i += push(&d->a, &d->b, 'b');
			check_b_nums(d);
		}
		rra(&d->a, 'a');
	}
	return (i);
}

void		solve_quarters_a(t_data *d)
{
	int		i;
	int		border;

	i = 0;
	border = 0;
	if (!initiate_chunk(&d->b))
		ft_exit(d, EXIT_FAILURE);
	border = d->a.ch->val_median;
	middle_chunk_b(d->b.ch, d->a.ch, d->elems);
	while (i < d->a.ch->size)
		i += make_moves(d, border);
	new_a_chunk(d->a.ch, d->elems);
	// if (d->b.ch->split == 0 && )
	// 	sort_remains();
}
// make smth with remains