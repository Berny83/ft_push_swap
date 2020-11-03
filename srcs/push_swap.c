/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:00:56 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/03 19:12:55 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_struct.h"

static t_data			initiate()
{
	t_data				new;

	ft_memset(&new, 0, sizeof(t_data));
}

int				main(int ac, char **av)
{
	t_data		d;
	
	d = initiate();
	validate(&d, ac, av);
	// sort();
	// clean();
	return (0);
}
