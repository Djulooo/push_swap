/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaisne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:57:43 by jlaisne           #+#    #+#             */
/*   Updated: 2022/12/31 14:19:59 by jlaisne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_int_max(long *arg)
{
	if (*arg > 2147483647 || *arg < -2147483648)
		display_error();
}

void	ft_atoi(const char *s, long *arg)
{
	int			i;
	int			sign;

	i = 0;
	sign = 1;
	while ((s[i] == ' ' || (s[i] >= 9 && s[i] <= 13)))
		i++;
	if (s[i] == '-' && s[i + 1] != '\0')
	{
		sign = -sign;
		i++;
	}
	else if (s[i] == '+' && s[i + 1] != '\0')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		*arg = (*arg * 10) + (s[i] - 48);
		check_int_max(arg);
		i++;
	}
	if ((s[i] < '0' || s[i] > '9') && s[i] != '\0')
		display_error();
	*arg = *arg * sign;
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s != 0)
	{
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*src;
	char			*str;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = start;
	src = (char *)s;
	if (!s)
		return (NULL);
	if (len > (ft_strlen(s) - start))
		len = (ft_strlen(s) - start);
	if (len > ft_strlen(s) || start >= ft_strlen(src) || s == 0 || len <= 0)
		len = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (!(str))
		return (NULL);
	while (j < start + len && src[i])
	{
		str[i] = src[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
