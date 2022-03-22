/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsub_with_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:08:08 by tburakow          #+#    #+#             */
/*   Updated: 2022/03/22 11:55:56 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*strsub_with_free(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*fsh;

	i = start;
	if (!s)
		return (NULL);
	fsh = (char *)malloc(sizeof(char) * (len + 1));
	if (!fsh)
		return (NULL);
	while ((i - start) < len)
	{
		fsh[i - start] = s[i];
		i++;
	}
	fsh[i - start] = '\0';
	ft_strdel(&s);
	return (fsh);
}
