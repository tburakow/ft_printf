#include "ft_printf.h"

void    character_mod(t_flags **flags, char c)
{
    unsigned int    i;
    char            x;

    i = 1;
    x = ' ';
    if ((*flags)->minus != 0)
        (*flags)->output += write(1, &c, 1);
    if ((*flags)->width > 0)
        while(i < (*flags)->width)
        {
            (*flags)->output += write(1, &x, 1);
            i++;
        }
    if ((*flags)->minus == 0)
        (*flags)->output += write(1, &c, 1);
}