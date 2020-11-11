/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:06:53 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/10 15:14:45 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_struct.h"
#include "push_swap.h"

static t_bool	is_integer(char *s)
{
	long int	value;
	int			sign;

	sign = 1;
	value = 0;
	while (ft_isblank(*s))
		s++;
	if (*s == '+' || (*s == '-' && (sign = -1)))
		s++;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (false);
		value = value * 10 + (*s - '0');
		s++;
	}
	if ((value * sign) <= INT_MAX && (value * sign) >= INT_MIN)
		return (true);
	return (false);
}

static int		add_element(t_stack *tmp, int n)
{
	t_elem		*new;
	
	if (!(new = (t_elem*)malloc(sizeof(t_elem))))
		return (0);
	new->num = n;
	new->next = NULL;
	new->prev = tmp->last;
	if (!tmp->first)
		tmp->first = new;
	if (tmp->last)
		tmp->last->next = new;
	tmp->last = new;
	tmp->size++;
	return (1);
}

static void		parse_arg(t_data *d, char *av)
{
	char		**str;
	int			i;
	int			n;
	
	i = 0;
	n = 0;
	str = ft_strsplit((const char *)av, ' ');
	while (str[i])
	{
		if (!is_integer(str[i]))
			ft_error(d, str);
		n = ft_atoi(str[i]);
		if (!add_element(&d->a, n))
			ft_exit(d, EXIT_FAILURE);
		free(str[i]);
		i++;
	}
	free(str);
}

void			validate(t_data *d, char **av)
{
	av++;
	while(*av)
	{
		parse_arg(d, *av);
		av++;
	}
	if (!(d->elems = (t_elem**)malloc(sizeof(t_elem*) * d->a.size)))
		ft_exit(d, EXIT_FAILURE);
	parse_duplicate(d);
}
