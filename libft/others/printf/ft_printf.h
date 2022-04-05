/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:19:54 by prafael-          #+#    #+#             */
/*   Updated: 2021/12/02 17:09:34 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# if __APPLE__
#  define IS_MACOS 1
# else
#  define IS_MACOS 0
# endif

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

char	*ft_itoaa(long int n);
void	ft_putstr_fda(char *s, int fd);
size_t	ft_strlena(const char *s);
int		ft_decimal(unsigned long int num);
size_t	ft_string(const char *c);
size_t	ft_char(const int c);
int		ft_hex(unsigned int num, const char *type);
int		ft_pointer(unsigned long int num);
int		ft_printf(const char *format, ...);

#endif
