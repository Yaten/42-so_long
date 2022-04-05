/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:19:48 by prafael-          #+#    #+#             */
/*   Updated: 2021/12/02 14:53:30 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_flags(const char *ptr, va_list my_args)
{
	if (*ptr == 'd' || *ptr == 'i' || *ptr == 'u')
	{
		if (*ptr == 'u')
			return (ft_decimal(va_arg(my_args, unsigned int)));
		else
			return (ft_decimal(va_arg(my_args, int)));
	}
	else if (*ptr == 'x' || *ptr == 'X' || *ptr == 'p')
	{
		if (*ptr == 'x' || *ptr == 'X')
			return (ft_hex(va_arg(my_args, unsigned int), ptr));
		else
			return (ft_pointer(va_arg(my_args, unsigned long int)));
	}
	else if (*ptr == 'c')
		return (ft_char(va_arg(my_args, int)));
	else if (*ptr == 's')
		return (ft_string(va_arg(my_args, char *)));
	else if (*ptr == '%')
	{
		write(1, ptr, 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		c;
	int		num;

	c = -1;
	num = 0;
	va_start(ap, format);
	while (format[++c])
	{
		if (format[c] == '%')
		{
			c += 1;
			num += ft_flags(&format[c], ap);
		}
		else
		{
			write(1, &format[c], 1);
			num++;
		}
	}
	va_end(ap);
	return (num);
}
