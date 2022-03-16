/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 12:57:46 by tburakow          #+#    #+#             */
/*   Updated: 2022/03/16 17:12:16 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_lgt(long long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	i++;
	return (i);
}

static char	*popul_str(char *str, long long *im, long long n)
{	
	str[im[0]--] = '\0';
	while (im[0] >= 0)
	{
		str[im[0]--] = (n % 10 + '0');
		n = n / 10;
		if (im[0] == 0 && im[1] != 0)
			str[im[0]--] = '-';
	}
	return (str);
}

char	*ft_itoa(long long n)
{
	long long	im[2];
	char		*str;

	im[0] = 0;
	im[1] = 0;
	if (n < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	if (n < 0)
	{
		im[1] = 1;
		n = n * -1;
	}
	str = (char *)malloc(sizeof(char) * (unsigned long)nbr_lgt(n) + \
	(unsigned long)im[1] + 1);
	if (!str)
		return (NULL);
	im[0] = (nbr_lgt(n) + im[1]);
	str = popul_str(str, im, n);
	return (str);
}

static int	nbr_lgt_uns(unsigned long long n)
{
	int i;

	i = 0;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	i++;
	return (i);
}

static char	*popul_str_uns(char *str, int len, unsigned long long n)
{	
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len--] = (n % 10 + '0');
		n = n / 10;
		if (len == 0 && len != 0)
			str[len--] = '-';
	}
	return (str);
}

char	*ft_itoa_unsigned(unsigned long long n)
{
	char		*str;
	int			len;
	
	len = nbr_lgt_uns(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str = popul_str_uns(str, len, n);
	return (str);
}