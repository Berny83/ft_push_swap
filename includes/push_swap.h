/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:01:02 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/11 21:33:16 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include <errno.h>

void		validate(t_data *d, char **av);
// int			add_top_element(t_stack *tmp, int n);
// void		del_top_element(t_stack *tmp);
void		parse_duplicate(t_data *d);

void		sort(t_data *d);
void		sort_3(t_data *d);
void		sort_5(t_data *d);
void		sort_100_500(t_data *d);

t_bool		initiate_chunk(t_stack *tmp);
void		solve_quarters_a(t_data *d);
int			find_moves_a(t_stack *tmp, int median, int border);
int			make_moves(t_data *d, int border);
void		solve_quarters_b(t_data *d);

void		sa(t_stack *a, char c);
void		sb(t_stack *b, char c);
void		ss(t_stack *a, t_stack *b);

void		ra(t_stack *a, char c);
void		rb(t_stack *b, char c);
void		rr(t_stack *a, t_stack *b);

void		rra(t_stack *a, char c);
void		rrb(t_stack *b, char c);
void		rrr(t_stack *a, t_stack *b);

int			push(t_stack *fi, t_stack *sec, char c);

void		ft_error(t_data *d, char **s);
void		clean(t_data *d);
void		ft_exit(t_data *d, int code);

#endif