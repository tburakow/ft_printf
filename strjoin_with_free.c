/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin_with_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:42:24 by tburakow          #+#    #+#             */
/*   Updated: 2022/03/22 12:29:38 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*strjoin_with_free(char *s1, char *s2)
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
		res[j++] = s2[i++];
	res[j] = '\0';
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (res);
}
