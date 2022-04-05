/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:42:48 by prafael-          #+#    #+#             */
/*   Updated: 2021/12/02 14:54:49 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int n)
{
	int		len;
	char	ch;

	ch = (unsigned char)n;
	len = ft_strlen(str);
	if (ch == 0)
		return ((char *)(str + len));
	while (--len >= 0)
	{
		if (*(str + len) == ch)
		{
			return ((char *)(str + len));
		}
	}
	return (NULL);
}
