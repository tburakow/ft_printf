/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:24:39 by tburakow          #+#    #+#             */
/*   Updated: 2021/11/29 15:35:07 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	f;
	size_t	i;

	i = 0;
	f = (char)c;
	while (i <= ft_strlen(s))
	{
		if (s[i] == f)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
