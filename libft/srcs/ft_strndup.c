/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 19:09:55 by aagrivan          #+#    #+#             */
/*   Updated: 2020/09/01 18:21:10 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *str, int count)
{
	char	*cp;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	if (!(cp = (char *)malloc(sizeof(char) + count + 1)))
		return (NULL);
	while (i < count)
	{
		cp[i] = str[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}
