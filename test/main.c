#include <stdio.h>

int octal_conversion(long d);

int main(void)
{
    printf("%.3f\n", 0.5595f);
    printf("%.12f\n", 0.5595f);
	printf("%.8f\n", 0.5595);
    printf("From hereon my own crap\n");
    printf("%c\n", 'x');
    printf("%d\n", 14);
    printf("%i\n", 20);
    printf("%e\n", 450.34);
    printf("%E\n", 560.567);
    printf("%f\n", 134.395);
    printf("%g\n", 1567.777);
    printf("%G\n", 1378.3);
    printf("%o\n", 206);
    printf("%s\n", "elvis");
    printf("%u\n", 345);
    printf("%%\n");
    printf("testing my octal conversion from 134 to 206:\n\n");
    printf("%d\n\n", octal_conversion(134));
}
