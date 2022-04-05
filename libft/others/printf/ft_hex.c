/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:19:29 by prafael-          #+#    #+#             */
/*   Updated: 2021/12/02 14:53:16 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(unsigned int num, const char *type)
{
	char			*base;
	char			new_num;
	static int		c;

	base = "0123456789abcdef";
	c = 0;
	if (num >= 16)
		ft_hex(num / 16, type);
	if (*type == 'x')
		new_num = base[num % 16];
	else if (*type == 'X')
	{
		if ((base[num % 16] >= 'A' && base[num % 16] <= 'Z') || \
		(base[num % 16] >= 'a' && base[num % 16] <= 'z'))
			new_num = ((base[num % 16]) - 32);
		else
			new_num = base[num % 16];
	}
	write(1, &new_num, 1);
	c++;
	return (c);
}
