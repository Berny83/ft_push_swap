/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 19:52:13 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/12 22:33:58 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_struct.h"
#include "push_swap.h"

static int		check_operation(t_data *d, char *str)
{
	if (!ft_strcmp(str, "sa") && (d->oper = sa))
		return (1);
	else if (!ft_strcmp(str, "ra") && (d->oper = ra))
		return (2);
	else if (!ft_strcmp(str, "rra") && (d->oper = rra))
		return (3);
	else if (!ft_strcmp(str, "pa") && (d->oper = push_pr))
		return (4);
	else if (!ft_strcmp(str, "sb") && (d->oper = sb))
		return (5);
	else if (!ft_strcmp(str, "rb") && (d->oper = rb))
		return (6);
	else if (!ft_strcmp(str, "rrb") && (d->oper = rrb))
		return (7);
	else if (!ft_strcmp(str, "pb") && (d->oper = push_pr))
		return (8);
	else if (!ft_strcmp(str, "ss") && (d->oper = ss))
		return (9);
	else if (!ft_strcmp(str, "rr") && (d->oper = rr))
		return (10);
	else if (!ft_strcmp(str, "rrr") && (d->oper = rrr))
		return (11);
	return (0);
}

static char		check_stack(int n)
{
	if (n <= 4)
		return ('d');
	else if (n <= 8)
		return ('e');
	else
		return ('f');
}

static void		get_commands(t_data *d)
{
	int			o;
	char 		*str;
	
	o = 0;
	while (get_next_line(STDIN_FILENO, &str))
	{
		if ((o = check_operation(d, str)) == 0)
		{	
			free(str);
			return ;
		}
		d->oper(d, check_stack(o));
		free(str);
	}
}

int				main(int ac, char **av)
{
	t_data		d;
	
	if (ac >= 2)
	{
		d = initiate();
		validate(&d, av);
		get_commands(&d);
		(is_sorted(&d)) ? ft_putendl("OK") :\
		ft_putendl("KO");
		clean(&d);
	}
	return (0);
}