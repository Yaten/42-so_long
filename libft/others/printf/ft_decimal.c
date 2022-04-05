/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:19:24 by prafael-          #+#    #+#             */
/*   Updated: 2021/12/02 17:09:27 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_decimal(unsigned long int num)
{
	char	*res;
	int		counter;

	res = ft_itoaa(num);
	ft_putstr_fda(res, 1);
	counter = ft_strlena(res);
	free(res);
	return (counter);
}
