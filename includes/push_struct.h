/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:05:34 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/03 19:47:21 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_STRUCT_H
#define PUSH_STRUCT_H

typedef struct 		s_elem
{
	int				num;
	t_elem			*next;
	t_elem			*prev;
}					t_elem;

typedef struct 		s_stack
{
	int				size;
	t_elem			*first;
	t_elem			*last;
}					t_stack;

typedef struct		s_data
{
	t_stack			*a;
	t_stack			*b;
	void			(*oper)(struct s_data *);
	t_elem			*ints;
}					t_data;

#endif