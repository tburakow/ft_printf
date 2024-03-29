/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_putchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 14:26:40 by tburakow          #+#    #+#             */
/*   Updated: 2022/03/16 14:17:36 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	special_putchar(char c, t_flags **flags)
{
	if (c != '\0')
	{
		(*flags)->output++;
		write(1, &c, 1);
	}
}
