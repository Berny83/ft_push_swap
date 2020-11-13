/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_a2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 16:39:16 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/13 16:42:22 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_struct.h"
#include "push_swap.h"

void			middle_chunk_b(t_chunk *b, t_chunk *a, t_elem **elems)
{
	b->split = a->split;
	b->size = a->size / b->split;
	if (a->lll == 0)
	{
		b->pos_median = a->pos_median - (b->size / 2);
		b->val_median = elems[b->pos_median]->num;
	}
}

void			redo_chunks(t_chunk *a, t_chunk *b, t_elem **elems)
{
	a->pos_median += b->size;
	if (a->lll)
	{
		a->val_median = elems[a->pos_median - 1]->num;
		a->val_median++;
	}
	b->pos_median = a->pos_median - (b->size / 2);
	b->val_median = elems[b->pos_median]->num;
}
