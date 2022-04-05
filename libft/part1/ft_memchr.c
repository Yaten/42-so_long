/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:42:18 by prafael-          #+#    #+#             */
/*   Updated: 2021/12/02 14:54:39 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *string, int character, size_t len)
{
	size_t	counter;
	char	*str;

	counter = 0;
	str = (char *) string;
	while (counter < len)
	{
		if (*(str + counter) == (char) character)
			return (str + counter);
		counter++;
	}
	return (NULL);
}
