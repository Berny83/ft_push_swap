/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:01:02 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/13 11:33:37 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include <errno.h>

t_data		initiate(void);
void		validate(t_data *d, char **av);
void		parse_duplicate(t_data *d);

void		sort(t_data *d);
void		sort_3(t_data *d);
void		sort_5(t_data *d);
void		sort_100_500(t_data *d);
t_bool		is_sorted(t_data *d);

t_bool		sorted_chunk(t_data *d);
void		new_a_chunk(t_chunk *a);
void		redo_chunks(t_chunk *a, t_chunk *b, t_elem **elems);
t_bool		initiate_chunk(t_stack *tmp);
void		solve_quarters_a(t_data *d, int border);
void		solve_quarters_b(t_data *d);
int			find_moves_a(t_stack *tmp, int median, int border);
int			make_moves_a(t_data *d, int border, char c);
void		make_moves_b(t_data *d, int small, char c);
void		check_b_nums(t_data *d);

int			sa(t_data *d, char c);
int			sb(t_data *d, char c);
int			ss(t_data *d, char c);

int			ra(t_data *d, char c);
int			rb(t_data *d, char c);
int			rr(t_data *d, char c);

int			rra(t_data *d, char c);
int			rrb(t_data *d, char c);
int			rrr(t_data *d, char c);

int			push(t_stack *fi, t_stack *sec, char c);
int			push_pr(t_data *d, char c);

void		ft_error(t_data *d, char **s);
void		clean(t_data *d);
void		clean_chunk(t_data *d);
void		ft_exit(t_data *d, int code);

#endif