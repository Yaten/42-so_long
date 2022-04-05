/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:19:42 by prafael-          #+#    #+#             */
/*   Updated: 2021/12/02 17:23:38 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nelements(long int num)
{
	int	c;

	c = 0;
	if (num == 0)
		c += 1;
	while (num > 0)
	{
		num = num / 10;
		c++;
	}
	return (c);
}

char	*ft_itoaa(long int n)
{
	int			el;
	int			flag;
	char		*str;
	long int	num;

	flag = 0;
	num = n;
	if (num < 0)
	{
		flag = 1;
		num *= -1;
	}
	el = ft_nelements(num) + flag;
	str = (char *)malloc(el + 1 * sizeof(char));
	if (!str)
		return (NULL);
	if (flag > 0)
		str[0] = '-';
	str[el] = '\0';
	while (el-- > flag)
	{
		str[el] = ((num % 10) + '0');
		num = num / 10;
	}
	return (str);
}

void	ft_putstr_fda(char *s, int fd)
{
	if (s != NULL)
	{
		while (*s)
			write(fd, s++, 1);
	}
}

size_t	ft_strlena(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
