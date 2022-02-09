/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:42:24 by tburakow          #+#    #+#             */
/*   Updated: 2021/11/30 13:01:11 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	res = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		res[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (i < ft_strlen(s2))
	{
		res[j++] = s2[i++];
	}
	res[j] = '\0';
	return (res);
}
