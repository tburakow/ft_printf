/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_ascii.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 10:45:38 by tburakow          #+#    #+#             */
/*   Updated: 2022/03/09 14:22:26 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *add_fractions(char *temp, long double mant, t_flags **flags)
{
    unsigned int    start;
    unsigned int    i;
    char            *str;

    str = ft_strnew(ft_strlen(temp) + (*flags)->precision + 1 + 1);
    if (!str)
        return (NULL);
    start = ft_strlen(temp);
    i = 0;
    while (i < start)
    {
        str[i] = temp[i];
        i++;
    }
    str[i++] = '.';
    while (i - start <= (*flags)->precision)
    {
        mant = mant * 10;
        str[i] = (intmax_t)mant + '0';
        mant = mant - (intmax_t)mant;
        i++;
    }
    return (str);
}

/* char    *add_fractions(char *temp, long double mant, t_flags **flags)
{
    unsigned int    start;
    unsigned int    i;
    char            *str;

    start = ft_strlen(temp);
    i = 0;
    str = NULL;
    while (i < start)
    {
        str[i] = temp[i];
        i++;
    } 
    str[i] = '.';
    while (i - start <= (*flags)->precision)
    {
        mant = mant * 10;
        str[i] = (intmax_t)mant + '0';
        mant = mant - (intmax_t)mant;
        i++;
    }
    return (str);
} */

char    *to_ascii(long double number, t_flags **flags)
{
    char        *final;
    char        *temp;
    intmax_t    exp;
    long double mant;
    
    exp = (intmax_t)number;
    temp = ft_itoa(exp);
    mant = number - (long double)exp;
    if ((*flags)->precision == 0)
    {
        if ((*flags)->hash == 1)
        {
            final = ft_strjoin(temp, ".");
            ft_strdel(&temp);
            return (final);
        }
        return (temp);
    }
    final = add_fractions(temp, mant, flags);
    ft_strdel(&temp);
    return (final);
}

/* char    *to_ascii(long double number, t_flags **flags)
{
    char        *final;
    char        *temp;
    intmax_t    exp;
    long double mant;
    
    exp = (intmax_t)number;
    temp = ft_itoa(exp);
    mant = number - (long double)exp;
    printf("\n%s\n", temp);
    if ((*flags)->precision > 0 || (*flags)->hash == 1)
        final = ft_strnew(ft_strlen(temp) + (*flags)->precision + 1 + 1);
    else
        return (temp);
    if (!final)
        return (NULL);
    final = add_fractions(temp, mant, flags);
    ft_strdel(&temp);
    printf("\n%Lf\n", mant);
    printf("%s", temp);
    return (final);
} */