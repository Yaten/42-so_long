/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:42:20 by prafael-          #+#    #+#             */
/*   Updated: 2021/12/02 14:54:40 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str, const void *ptr, size_t n)
{
	size_t			a;
	unsigned char	*str1;
	unsigned char	*ptr1;

	str1 = (unsigned char *)str;
	ptr1 = (unsigned char *)ptr;
	a = 0;
	while (*(str1 + a) == *(ptr1 + a) && ++a < n)
		;
	if (a == n)
		return (0);
	return (*(str1 + a) - *(ptr1 + a));
}
