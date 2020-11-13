/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 21:40:33 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/13 16:24:43 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_struct.h"
#include "push_swap.h"

t_data			initiate(void)
{
	t_data		new;

	ft_memset(&new, 0, sizeof(t_data));
	return (new);
}

t_bool			initiate_chunk(t_stack *tmp)
{
	t_chunk		*new;

	if (!tmp->ch || tmp->ch->size)
	{
		if (!(new = (t_chunk *)malloc(sizeof(t_chunk))))
			return (false);
		ft_memset(new, 0, sizeof(t_chunk));
		new->next = tmp->ch;
		tmp->ch = new;
	}
	return (true);
}
