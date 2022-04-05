/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 15:19:46 by prafael-          #+#    #+#             */
/*   Updated: 2021/12/02 14:55:32 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	count;

	if (!s || !f)
		return (NULL);
	count = 0;
	res = ft_strdup(s);
	if (res == NULL)
		return (NULL);
	while (res[count] != 0)
	{
		res[count] = f(count, res[count]);
		count++;
	}
	return (res);
}
