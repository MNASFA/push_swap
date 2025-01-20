/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmnasfa <hmnasfa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:47:45 by hmnasfa           #+#    #+#             */
/*   Updated: 2025/01/19 12:44:10 by hmnasfa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


int	check_sign(char str, int sign)
{
	if (str == '-')
		sign = -1;
	return (sign);
}

long long	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long long		res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = check_sign (str[i++], sign);
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + (sign * (str[i] - 48));
		if (res > 2147483647 || res < -2147483648)
			return res;
		i++;
	}
	return (res);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write (fd, &s[i], 1);
		i++;
	}
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len ++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	length;
	size_t	i;

	length = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (length);
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (length);
}

