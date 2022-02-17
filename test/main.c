#include <stdio.h>

int	ft_atoi(const char *str);

int octal_conversion(long d);

int main(void)
{
	int	*ptr;
	int x;
	int i;
	char *str = "6666.1234";

	x = 5;
	ptr = &x;
	i = 0;

    printf("%.3f\n", 0.5595f);
    printf("%.12f\n", 0.5595f);
	printf("%10.8f\n", 0.5595);
    printf("From hereon my own crap\n");
    printf("%c\n", 'e');
	printf("%-10s\n", "elvis");
	printf("%p\n", ptr);
    printf("%d\n", 14);
    printf("%i\n", 20);
    printf("%o\n", 206);
	printf("%O\n", 206);
	printf("%u\n", 12345);
	printf("%x\n", 12345);
	printf("%X\n", 4567);
	printf("%f\n", 134.395);
	printf("%d\n", 4567123);
	printf("%d\n", 400);
	printf("%400.d\n", 400);
    printf("testing my octal conversion from 134 to 206:\n\n");
    printf("%d\n\n", octal_conversion(134));
	printf("%d", ft_atoi(&str[5]));
}
