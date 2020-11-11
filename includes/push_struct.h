/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:05:34 by aagrivan          #+#    #+#             */
/*   Updated: 2020/11/11 18:58:25 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_STRUCT_H
# define PUSH_STRUCT_H

# define ERR "Error\n"

typedef struct 		s_elem
{
	long int		num;
	struct s_elem	*next;
	struct s_elem	*prev;
}					t_elem;

typedef struct		s_chunk
{
	int				size;
	int				pos_median;
	int				val_median;
	int				split;
	struct s_chunk	*next;
}					t_chunk;

typedef struct 		s_stack
{
	int				size;
	t_elem			*first;
	t_elem			*last;
	t_chunk			*ch;
}					t_stack;

typedef struct		s_data
{
	t_stack			a;
	t_stack			b;
	void			(*oper)(struct s_data *);
	t_elem			**elems;
}					t_data;

typedef enum
{
	false,
	true
}					t_bool;

#endif