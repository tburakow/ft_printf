/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:37:09 by tburakow          #+#    #+#             */
/*   Updated: 2022/01/11 15:34:28 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*d;
	char		*s;

	i = 0;
	d = (char *)dst;
	s = (char *)src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst > src)
		while (len--)
			d[len] = s[len];
	else
		ft_memcpy(d, s, len);
	return (dst);
}

ft_putendl.c (line 17) : ft_putchar() should be declared as static
ft_putendl_fd.c (line 17) : ft_putchar_fd() should be declared as static
ft_putnbr.c (line 17) : ft_putchar() should be declared as static
ft_putnbr_fd.c (line 17) : ft_putchar_fd() should be declared as static