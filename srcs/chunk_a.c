/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 21:02:30 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/13 00:10:38 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_struct.h"
#include "push_swap.h"

static void	middle_chunk_b(t_chunk *b, t_chunk *a, t_elem **elems)
{
	b->split = a->split; //4 //3 //2 //1
	b->size = a->size / b->split; //20 //20 //20 //20
	b->pos_median = a->pos_median - (b->size / 2); //10 //20 //30 //40
	b->val_median = elems[b->pos_median]->num;  //elems[10] = 21//elems[20] = 40 //60
}

void		new_a_chunk(t_chunk *a, t_elem **elems)
{
	a->pos_median += (a->size / a->split); // 40 + 60/3=60//100 скорее всего еще минус 1
	a->size -= (a->size / a->split); //80 //60 //40 //20
	a->split--; //4 //3 //2
	a->lll = 1;
	if (a->lll)
	{
		a->val_median = elems[a->pos_median]->num;
		// a->val_median++;
	} //elems[40] = 40 //elems[60] = 60
}

int			find_moves_a(t_stack *tmp, int median, int border)
{
	int		i;
	int		j;
	t_elem	*fi;
	t_elem	*lst;

	i = 0;
	j = 0;
	fi = tmp->first;
	lst = tmp->last;
	while (tmp->first)
	{
		if (tmp->first->num < median && tmp->first->num >= border)
			break ;
		i++;
		tmp->first = tmp->first->next;
	}
	if (i != 0)
	{
		while (tmp->last)
		{
			if (tmp->last->num < median && tmp->last->num >= border)
				break ;
			j++;
			tmp->last = tmp->last->prev;
		}
	}
	tmp->first = fi;
	tmp->last = lst;
	if (i <= j)
		return (1);
	return (0);
}

void		check_b_nums(t_data *d)
{
	if (d->b.first->next)
	{
		if (d->b.first->num <= d->b.ch->val_median)
		{
			if (d->b.first->num > d->b.first->next->num)
				sb(d, 'b');
		}
		else
			rb(d, 'b');
	}
}

int			make_moves_a(t_data *d, int border, char c)
{
	int		i;

	i = 0;
	if (c == 'f')
	{
		if (d->a.first->num < d->a.ch->val_median && d->a.first->num >= border)
		{
			i += push_pr(d, 'b');
			check_b_nums(d);
		}
		else
			ra(d, 'a');
	}
	else
	{
		if (d->a.last->num < d->a.ch->val_median && d->a.last->num >= border)
		{
			rra(d, 'a');
			i += push_pr(d, 'b');
			check_b_nums(d);
		}
		else
			rra(d, 'a');
	}
	return (i);
}

void		solve_quarters_a(t_data *d, int border)
{
	int		i;

	i = 0;
	middle_chunk_b(d->b.ch, d->a.ch, d->elems);
	while (i < d->b.ch->size)
	{
		if (find_moves_a(&d->a, d->a.ch->val_median, border))
			i += make_moves_a(d, border, 'f');
		else
			i += make_moves_a(d, border, 'l');
	}
}
// make smth with remains -кажется просто последний чанк больше остальных получается без
// всяких остатков