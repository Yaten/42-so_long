/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 15:19:39 by prafael-          #+#    #+#             */
/*   Updated: 2021/12/02 14:55:26 by prafael-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_fill_matrix(char const *s, char c, size_t num, char **res);
static size_t	countn(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	num;

	res = NULL;
	if (!s)
		return (NULL);
	num = countn(s, c);
	res = (char **)malloc(sizeof(char *) * (num + 1));
	if (!res)
		return (NULL);
	ft_fill_matrix(s, c, num, res);
	return (res);
}

static size_t	countn(char const *s, char c)
{
	size_t	count;
	size_t	len;

	if (!s[0])
		return (0);
	len = 0;
	count = 0;
	while (s[len] && s[len] == c)
		len++;
	while (s[len])
	{
		if (s[len] == c)
		{
			count++;
			while (s[len] && s[len] == c)
				len++;
			continue ;
		}
		len++;
	}
	if (s[len - 1] != c)
		count++;
	return (count);
}

static void	ft_fill_matrix(char const *s, char c, size_t num, char **res)
{
	size_t	count;
	char	*start_str;
	int		lenword;

	count = 0;
	start_str = (char *)s;
	while (count < num)
	{
		lenword = 0;
		while (*start_str == c && *start_str != 0)
			++start_str;
		while (start_str[lenword] != c && start_str[lenword] != 0)
			lenword++;
		res[count] = ft_substr(start_str, 0, lenword);
		start_str += lenword;
		count++;
	}
	res[count] = 0;
}
