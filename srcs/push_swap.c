/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:00:56 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/12 21:40:50 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_struct.h"
#include "push_swap.h"

int				main(int ac, char **av)
{
	t_data		d;
	
	if (ac >= 2)
	{
		d = initiate();
		validate(&d, av);
		sort(&d);
		clean(&d);
	}
	else
		ft_printf(ERR);
	return (0);
}
