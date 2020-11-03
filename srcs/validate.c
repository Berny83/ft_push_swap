/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:06:53 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/03 19:48:36 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_struct.h"

static void		parse_arg(t_data *d, int ac, char **av)
{
	av++;
	while(*av)
	{
		
		av++;
	}
}

void			validate(t_data *d, int ac, char **av)
{
	if (ac < 2)
	{
		ft_printf("Error\n");
		exit(1);
	}
	parse_arg(d, ac, av);
	parse_ints(d);
}

//check - av[1] = "0 1 2 3 4" - ft_strsplit needed, parse if arguments are bigger than an integer, and/or there are duplicates