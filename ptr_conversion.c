#include "ft_printf.h"

static char *ptr_base(char *hexadec, long long d, long long i, \
t_flags **flags)
{
    long long	rem;
	char		*output;

	ft_strdel(&hexadec);
	output = ft_strnew((*flags)->base_size);
    while (d > 0)
    {
        rem = d % 16;
        if (rem <= 9)
            rem += 48;
        else
            rem += 87;
        output[i - 1] = rem;
        i--;
        d = d / 16;
    }
    output[(*flags)->base_size] = '\0';
    if (i > 0)
        output = ft_strsub(output, i, (*flags)->base_size - 1);
    return (output);
}

static char *neg_ptr_base(char *hexadec, unsigned long long neg, long long i,\
 t_flags **flags)
{
    long long	rem;
	char		*output;

	ft_strdel(&hexadec);
	output = ft_strnew((*flags)->base_size);
    while (neg > 0 && i >= 0)
    {
            rem = neg % 16;
        if (rem <= 9)
            rem += 48;
        else
            rem += 87;
        output[i - 1] = rem;
        i--;
        neg = neg / 16;
    }
    output[(*flags)->base_size] = '\0';
    if (i > 0)
        output = ft_strsub(output, i, (*flags)->base_size - 1);
    return (output);
}

char    *ptr_conversion(long long d, t_flags **flags)
{
    char        *hexadec;
    long long   i;
    unsigned long long neg;

    neg = 0;
	if (d == 0)
		return ("0");
    hexadec = ft_strnew((*flags)->base_size);
    if (!hexadec)
        return (NULL);
    i = (*flags)->base_size;
    if (d > 0)
        hexadec = ptr_base(hexadec, d, i, flags);
    else
    {
        neg = d;
        hexadec = neg_ptr_base(hexadec, neg, i, flags);
    }
    return (hexadec);
}