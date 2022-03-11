/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:03:27 by tburakow          #+#    #+#             */
/*   Updated: 2022/03/11 15:03:29 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"
#include <limits.h>

int main(void)
{
	char					*str = "Ma'am";
	char					*str2 = "19";
	char					*format;
	int						i;
	int						len;
	int						len2;

	system("echo Nice to meet you $(whoami)");
	printf("\n1. mine, 2. unix: testing string:|\n");
	len = ft_printf("\t|Hello|\n");
	len2 = printf("\t|Hello|\n");
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: testing length:|\n");
	len = ft_printf("\t|Should return 19:|\n");
	len2 = printf("\t|Should return 19:|\n");
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: testing length, test2:|\n");
	len = ft_printf("\t|Should return %s:|\n", str2);
	len2 = printf("\t|Should return %s:|\n", str2);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: testing length, test2:|\n");
	len = ft_printf("\t|Should return %x:|\n", -19);
	len2 = printf("\t|Should return %x:|\n", -19);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: testing another string:|\n");
	len = ft_printf("\t|Hello %s|\n", str);
	len2 = printf("\t|Hello %s|\n", str);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


 	printf("|\n1. mine, 2. unix: testing upper-case character|\n");
	len = ft_printf("\t|This... is... %cPARTA!|\n", 'S');
	len2 = printf("\t|This... is... %cPARTA!|\n", 'S'); 
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: testing lower-case character|\n");
	len = ft_printf("\t|This... is... %canta! Ho ho ho!|\n", 's');
	len2 = printf("\t|This... is... %canta! Ho ho ho!|\n", 's');
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: testing integer|\n");
	len = ft_printf("\t|Is this mambo number %d|\n", 5);
	len2 = printf("\t|Is this mambo number %d|\n", 5);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: testing negative integer|\n");
	len = ft_printf("\t|Is this mambo number %d|\n", -5);
	len2 = printf("\t|Is this mambo number %d|\n", -5);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: testing float|\n");
	len = ft_printf("\t|So far I've made %f€ on my programming career|\n", 0.00);
	len2 = printf("\t|So far I've made %f€ on my programming career|\n", 0.00);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: testing hexadecimal|\n");
	len = ft_printf("\t|Got an %x on my exam|\n", 16);
	len2 = printf("\t|Got an %x on my exam|\n", 16);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: testing BIG hexadecimal|\n");
	len = ft_printf("\t|Got an %X on my exam|\n", 16);
	len2 = printf("\t|Got an %X on my exam|\n", 16);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: testing negative hexadecimal|\n");
	len = ft_printf("\t|Got an %x on my exam|\n", -16);
	len2 = printf("\t|Got an %x on my exam|\n", -16);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: testing BIG negative hexadecimal|\n");
	len = ft_printf("\t|Got an %X on my exam|\n", -16);
	len2 = printf("\t|Got an %X on my exam|\n", -16);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: testing hexadecimal with width modifier|\n");
	len = ft_printf("\t|Got an %10X on my exam|\n", -16);
	len2 = printf("\t|Got an %10X on my exam|\n", -16);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: testing unsigned integer|\n");
	len = ft_printf("\t|Kimi Raikkonen is number %u|\n", 1);
	len2 = printf("\t|Kimi Raikkonen is number %u|\n", 1);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: testing a negative unsigned integer|\n");
	len = ft_printf("\t|Wow this ia big number %u|\n", (1-2));
	len2 = printf("\t|Wow this ia big number %u|\n", (1-2));
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: testing a pointer|\n");
	len = ft_printf("\t|Address: %p|\n", str); 
	len2 = printf("\t|Address: %p|\n", str);
			printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);
		
		/*
	An unsigned is an integer that can never be negative. 
	If you take an unsigned 0 and subtract 1 from it, the result wraps around, 
	leaving a very large number (2^32-1 with the typical 32-bit integer size).
	*/
	printf("|\n1. mine, 2. unix: testing octal|\n");
	len = ft_printf("\t|I guess this is an octal? %o == 12 ?|\n", 10);
	len2 = printf("\t|I guess this is an octal? %o == 12 ?|\n", 10);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: testing zero-fill|\n");
	len = ft_printf("\t|You miss 1%04d of the shots you don't take|\n", 0);
	len2 = printf("\t|You miss 1%04d of the shots you don't take|\n", 0);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: testing decimal formatting|\n");
	len = ft_printf("\t|Don't let this be devil's number: %.1f|\n", 6.66);
	len2 = printf("\t|Don't let this be devil's number: %.1f|\n", 6.66);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: Testing in all the conversion specifiers in one:|\n");
	len = ft_printf("\t|%c%s%p%d%i%o%u%x%X%f|\n", 'a', str, str, 123, 456, 9, 11, 0xf, 0xf, 111.0);
	len2 = printf("\t|%c%s%p%d%i%o%u%x%X%f|\n", 'a', str, str, 123, 456, 9, 11, 0xf, 0xf, 111.0);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: general test:|\n");
	len = ft_printf("\t|%% %%%1iiii%+0i1 %01i- #+i%011i- #%%%%|\n", 123, 456, 789, 0);
	len2 = printf("\t|%% %%%1iiii%+0i1 %01i- #+i%011i- #%%%%|\n", 123, 456, 789, 0);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: testing bad boi float|\n");
	format = strdup("%.10f|\n");
	i = 0;
	while (i < 9)
	{
		len = ft_printf(format, 1234567.123456789123456789);
		printf(format, 1234567.123456789123456789);
		fflush(NULL);
		format[3]++;
		i++;
	}
	free(format);

	printf("|\n1. mine, 2. unix: Special characters:|\n");
	len = ft_printf("tab: \t|Backspace\b form feed: \f, newline: |\n carriage return:|\n delete\r vertical tab: \v and a backslash: \\");
	printf("|\n1. mine, 2. unix: -------------------------------------------------------|\n");
	printf("tab: \t|Backspace\b form feed: \f, newline: |\n carriage return:|\n delete\r vertical tab: \v and a backslash: \\");

	printf("|\n1. mine, 2. unix: Testing width:|\n");
	len = ft_printf("\t|%*d|\n", 5, 10);
	len2 = printf("\t|%*d|\n", 5, 10);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: Testing width, test 2:|\n");
	len = ft_printf("\t|%5d|\n", 10);
	len2 = printf("\t|%5d|\n", 10);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: Testing width with zero flag:|\n");
	len = ft_printf("\t|%05d|\n", 10);
	len2 = printf("\t|%05d|\n", 10);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: Testing 42filechecker tests 1:|\n");
	len = ft_printf("\t|%10x|\n", 42);
	len2 = printf("\t|%10x|\n", 42);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: Testing 42filechecker tests 2:|\n");
	len = ft_printf("\t|%-10x|\n", 42);
	len2 = printf("\t|%-10x|\n", 42);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


/* 	printf("|\n1. mine, 2. unix: Testing 42filechecker tests:|\n");
	len = ft_printf("\t|%5%|\n");
	len2 = printf("\t|%5%|\n"); */
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: Testing 42filechecker tests 3:|\n");
	len = ft_printf("\t|%jx|\n", 4294967296);
	len2 = printf("\t|%jx|\n", 4294967296);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: Testing 42filechecker tests 4:|\n");
	len = ft_printf("\t|%lx|\n", 9223372036854775807);
	len2 = printf("\t|%lx|\n", 9223372036854775807);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: Testing 42filechecker tests 5:|\n");
	len = ft_printf("\t|%-5%|\n");
	len2 = printf("\t|%-5%|\n");
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: Testing 42filechecker tests 6:|\n");
	len = ft_printf("\t|%-15x|\n", 542);
	len2 = printf("\t|%-15x|\n", 542);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	/* why doesn't print (null) */
	printf("|\n1. mine, 2. unix: Testing moulitest tests 1:|\n");
	len = ft_printf("\t|{%s}|\n", NULL);
	len2 = printf("\t|{%s}|\n", NULL);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: Testing moulitest tests 2:|\n");
	len = ft_printf("\t|%d|\n", -42);
	len2 = printf("\t|%d|\n", -42);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: Testing moulitest tests 3:|\n");
	len = ft_printf("\t|%p|\n", NULL);
	len2 = printf("\t|%p|\n", NULL);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: Testing moulitest tests 4:|\n");
	len = ft_printf("\t|%  %|\n");
	len2 = printf("\t|%  %|\n");
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: Testing moulitest tests 5:|\n");
	len = ft_printf("\t|%ld%ld|\n", 0l, 42l);
	len2 = printf("\t|%ld%ld|\n", 0l, 42l);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: Testing moulitest tests 6:|\n");
	len = ft_printf("\t|%ld|\n", LONG_MIN);
	len2 = printf("\t|%ld|\n", LONG_MIN);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: Testing moulitest tests 7:|\n");
	len = ft_printf("\t|%u|\n", 4294967295);
	len2 = printf("\t|%lu|\n", 4294967295);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: Testing moulitest tests 8:|\n");
	len = ft_printf("\t|%lo, %lo|\n", 0ul, ULONG_MAX);
	len2 = printf("\t|%lo, %lo|\n", 0ul, ULONG_MAX);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: Testing moulitest tests 9:|\n");
	len = ft_printf("\t|%llo, %llo|\n", 0llu, ULLONG_MAX);
	len2 = printf("\t|%llo, %llo|\n", 0llu, ULLONG_MAX);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: Testing moulitest tests 9:|\n");
	len = ft_printf("\t|%x, %x|\n", 0, UINT_MAX);
	len2 = printf("\t|%x, %x|\n", 0, UINT_MAX);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: Testing moulitest tests 10:|\n");
	len = ft_printf("\t|%lx, %lx|\n", 0ul, ULONG_MAX);
	len2 = printf("\t|%lx, %lx|\n", 0ul, ULONG_MAX);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: Testing moulitest tests 11:|\n");
	len = ft_printf("\t|%lx, %lx|\n", 0ul, ULONG_MAX);
	len2 = printf("\t|%lx, %lx|\n", 0ul, ULONG_MAX);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: Testing moulitest tests 12:|\n");
	len = ft_printf("\t|%#o|\n", 42);
	len2 = printf("\t|%#o|\n", 42);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: Testing moulitest tests 13:|\n");
	len = ft_printf("\t|%#o|\n", INT_MAX);
	len2 = printf("\t|%#o|\n", INT_MAX);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: Testing moulitest tests 14:|\n");
	len = ft_printf("\t|%#o|\n", 0);
	len2 = printf("\t|%#o|\n", 0);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: Testing moulitest tests 15:|\n");
	len = ft_printf("\t|%#x|\n", 42);
	len2 = printf("\t|%#x|\n", 42);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: Testing moulitest tests 16:|\n");
	len = ft_printf("\t|%#x|\n", INT_MAX);
	len2 = printf("\t|%#x|\n", INT_MAX);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: Testing moulitest tests 17:|\n");
	len = ft_printf("\t|%#x|\n", 0);
	len2 = printf("\t|%#x|\n", 0);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: Testing moulitest tests 18:|\n");
	len = ft_printf("\t|%#X|\n", 42);
	len2 = printf("\t|%#X|\n", 42);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: Testing moulitest tests 19:|\n");
	len = ft_printf("\t|%#X|\n", INT_MAX);
	len2 = printf("\t|%#X|\n", INT_MAX);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: Testing moulitest tests 20:|\n");
	len = ft_printf("\t|%#X|\n", 0);
	len2 = printf("\t|%#X|\n", 0);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


/* 	unsigned int is right but fucks up others, unsigned long int gives wrong
	ffffffffffffffd6 instead of
	ffffffd6 */
	printf("|\n1. mine, 2. unix: Testing moulitest tests 21:|\n");
	len = ft_printf("\t|%x|\n", -42);
	len2 = printf("\t|%x|\n", -42);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: Testing moulitest tests 22:|\n");
	len = ft_printf("\t|{%030X}|\n", 0xFFFF);
	len2 = printf("\t|{%030X}|\n", 0xFFFF);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: Testing moulitest tests 23:|\n");
	len = ft_printf("\t|%#10x|\n", 100);
	len2 = printf("\t|%#10x|\n", 100);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: Testing moulitest tests 24:|\n");
	len = ft_printf("\t|%#10x|\n", 100);
	len2 = printf("\t|%#10x|\n", 100);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: Testing moulitest tests 25:|\n");
	len = ft_printf("\t|% d|\n", 9999);
	len2 = printf("\t|% d|\n", 9999);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);



	printf("|\n1. mine, 2. unix: Testing moulitest tests 31:|\n");
	len = ft_printf("\t|%5.2s is a string|\n", "this");
	len2 = printf("\t|%5.2s is a string|\n", "this");
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: Testing moulitest tests 32:|\n");
	len = ft_printf("\t|%5.2s is a string|\n", "this");
	len2 = printf("\t|%5.2s is a string|\n", "this");
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: Testing moulitest tests 33:|\n");
	len = ft_printf("\t|%-10s is a string|\n", "this");
	len2 = printf("\t|%-10s is a string|\n", "this");
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: Testing moulitest tests 34:|\n");
	len = ft_printf("\t|%-5.2s is a string|\n", "this");
	len2 = printf("\t|%-5.2s is a string|\n", "this");
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: Testing moulitest tests 35:|\n");
	len = ft_printf("\t|%-5.2s is a string|\n", "");
	len2 = printf("\t|%-5.2s is a string|\n", "");
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: Testing moulitest tests 36:|\n");
	len = ft_printf("\t|%4.15d|\n", 42);
	len2 = printf("\t|%4.15d|\n", 42);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: Testing moulitest tests 37:|\n");
	len = ft_printf("\t|%-10d|\n", 42);
	len2 = printf("\t|%-10d|\n", 42);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: Testing moulitest tests 38:|\n");
	len = ft_printf("\t|%  %|\n");
	len2 = printf("\t|%  %|\n");
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("|\n1. mine, 2. unix: Testing moulitest tests 39:|\n");
	len = ft_printf("\t|% +d|\n", 42);
	
	printf("|\n1. mine, 2. unix: Testing moulitest tests 40:|\n");
	len = ft_printf("\t|{%010d}||\n", -42);
	len2 = printf("\t|{%010d}|\n", -42);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("\n1. mine, 2. unix: Testing moulitest tests 41:\n");
	len = ft_printf("\t|%#o|\n", 0);
	len2 = printf("\t|%#o|\n", 0);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("\n1. mine, 2. unix: Testing moulitest tests 42:\n");
	len = ft_printf("\t|%+03d|\n", 0);
	len2 = printf("\t|%+03d|\n", 0);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("\n1. mine, 2. unix: Testing moulitest tests 44:\n");
	len = ft_printf("\t|% 03d|\n", 0);
	len2 = printf("\t|% 03d|\n", 0);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("\n1. mine, 2. unix: Testing moulitest tests 45:\n");
	len = ft_printf("\t|{%0-3d}|\n", 0);

	/* why is no zero printed in the right answer? */
	printf("\n1. mine, 2. unix: Testing moulitest tests 46:\n");
	len = ft_printf("\t|%03.2d|\n", 0);
	len2 = printf("\t|%03.2d|\n", 0);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("\n1. mine, 2. unix: Testing moulitest tests 47:\n");
	len = ft_printf("\t|@moulitest: %#.x %#.0x|\n", 0, 0);
	len2 = printf("\t|@moulitest: %#.x %#.0x|\n", 0, 0);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	/* why only one space before in the real printf? */


	printf("\n1. mine, 2. unix: Testing moulitest tests 49:\n");
	len = ft_printf("\t|%5o is a string|\n", 41);
	len2 = printf("\t|%5o is a string|\n", 41);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("\n1. mine, 2. unix: Testing moulitest tests 50:\n");
	len = ft_printf("\t|%.10d|\n", 4242);
	len2 = printf("\t|%.10d|\n", 4242);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("\n1. mine, 2. unix: Testing moulitest tests 51:\n");
	len = ft_printf("\t|%.10d|\n", -42);
	len2 = printf("\t|%.10d|\n", -42);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("\n1. mine, 2. unix: Testing moulitest tests 52:\n");
	len = ft_printf("\t|%#08x|\n", 42);
	len2 = printf("\t|%#08x|\n", 42);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


/* 	printf("\n1. mine, 2. unix: Testing moulitest tests 53:\n");
	len = ft_printf("\t|%#-78x|\n", 42);
	len2 = printf("\t|%#-78x|\n", 42);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2); */


	printf("\n1. mine, 2. unix: Testing moulitest tests 54:\n");
	len = ft_printf("\t|%#8x|\n", 42);
	len2 = printf("\t|%#8x|\n", 42);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("\n1. mine, 2. unix: Testing moulitest tests 55:\n");
	len = ft_printf("\t|%-5o|\n", 2500);
	len2 = printf("\t|%-5o|\n", 2500);
			printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);
		
		printf("%d\n", len);

	printf("\n1. mine, 2. unix: Testing moulitest tests 56:\n");
	len = ft_printf("\t|%-10.5o|\n", 2500);
	len2 = printf("\t|%-10.5o|\n", 2500);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("\n1. mine, 2. unix: Testing moulitest tests 57:\n");
	len = ft_printf("\t|%.10o|\n", 42);
	len2 = printf("\t|%.10o|\n", 42);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("\n1. mine, 2. unix: Testing moulitest tests 58:\n");
	len = ft_printf("\t|%-5.10o|\n", 2500);
	len2 = printf("\t|%-5.10o|\n", 2500);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);

	printf("\n1. mine, 2. unix: Testing moulitest tests 59:\n");
	len = ft_printf("\t|%-10s is a strimg|\n", "");
	len2 = printf("\t|%-10s is a strimg|\n", "");
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);

	printf("\n1. mine, 2. unix: Testing moulitest tests 60:\n");
	len = ft_printf("\t|%-10.5d|\n", 4242);
	len2 = printf("\t|%-10.5d|\n", 4242);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);

	printf("\n1. mine, 2. unix: Testing moulitest tests 61:\n");
	len = ft_printf("\t|%15.4d|\n", -42);
	len2 = printf("\t|%15.4d|\n", -42);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);

	printf("\n1. mine, 2. unix: Testing moulitest tests 62:\n");
	len = ft_printf("\t|%03.2d|\n", 0);
	len2 = printf("\t|%03.2d|\n", 0);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);

	printf("\n1. mine, 2. unix: Testing moulitest tests 63:\n");
	len = ft_printf("\t|%.d|\n", 0);
	len2 = printf("\t|%.d|\n", 0);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);
	
	printf("\n1. mine, 2. unix: Testing moulitest tests 64:\n");
	len = ft_printf("\t|%+10.5d|\n", 4242);
	len2 = printf("\t|%+10.5d|\n", 4242);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);

	printf("\n1. mine, 2. unix: Testing moulitest tests 65:\n");
	len = ft_printf("\t|%   %|\n");
	len2 = printf("\t|%   %|\n");
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);

	printf("\n1. mine, 2. unix: Testing moulitest tests 65:\n");
	len = ft_printf("\t|%.d, %.0d|\n", 0, 0);
	len2 = printf("\t|%.d, %.0d|\n", 0, 0);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);

	printf("\n1. mine, 2. unix: Testing moulitest tests 65:\n");
	len = ft_printf("\t|%llx|\n", 9223372036854775807);
	printf("\tmine: (%d)\n", len);

	printf("\n1. mine, 2. unix: Testing moulitest tests 65:\n");
	len = ft_printf("\t|%#llx|\n", 9223372036854775807);
	printf("\tmine: (%d)\n", len);

	printf("\n1. mine, 2. unix: Testing moulitest tests 48:\n");
	len = ft_printf("\t|%-.2s is a string|\n", "");
	len2 = printf("\t|%-.2s is a string|\n", "");
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);

	return (0);

/* 	Doesn't compile for some reason:
	printf("\n1. mine, 2. unix: Testing moulitest tests 51:\n");
	len = ft_printf("\t|%Lf|\n", -7.0L);
	len2 = printf("\t|%Lf|\n", -7.0L);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	len2 = printf("\t|{%0-3d}|\n", 0);
			printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);
		
		len2 = printf("\t|{%5p}|\n", 0);
			printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);
		
		len2 = printf("\t|% +d\n", 42);
			printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);
		
		len2 = printf("\t|%\n", 42);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("\n1. mine, 2. unix: Testing moulitest tests 27:\n");
	len = ft_printf("\t|%010s is a string\n", "this");
	len2 = printf("\t|%010s is a string\n", "this");
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("\n1. mine, 2. unix: Testing moulitest tests 29:\n");
	len = ft_printf("\t|%#+10.5d\n", 4242);
	len2 = printf("\t|%#+10.5d\n", 4242);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("\n1. mine, 2. unix: Testing moulitest tests 28:\n");
	len = ft_printf("\t|%+10.5d\n", 4242);
	len2 = printf("\t|%+10.5d\n", 4242);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("\n1. mine, 2. unix: Testing moulitest tests 26:\n");
	len = ft_printf("\t|%p\n", 0);
	len2 = printf("\t|%p\n", 0);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("\n1. mine, 2. unix: Testing moulitest tests 30:\n");
	len = ft_printf("\t|%#+10.5d\n", -4242);
	len2 = printf("\t|%#+10.5d\n", -4242);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("\n1. mine, 2. unix: Testing moulitest tests 12:\n");
	len = ft_printf("\t|%#c\n", 0);
	len2 = printf("\t|%#c\n", 0);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("\n1. mine, 2. unix: Testing moulitest tests 12:\n");
	len = ft_printf("\t|%hhd\n", CHAR_MAX + 42);
	len2 = printf("\t|%hhd\n", CHAR_MAX + 42);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("\n1. mine, 2. unix: Testing moulitest tests 10:\n");
	len = ft_printf("\t|%ho, %ho\n", 0, USHRT_MAX);
	len2 = printf("\t|%ho, %ho\n", 0, USHRT_MAX);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("\n1. mine, 2. unix: Testing 42filechecker tests 7:\n");
	len = ft_printf("\t|%hhX\n", 294967296);
	len2 = printf("\t|%hhX\n", 294967296);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


	printf("\n1. mine, 2. unix: Testing 42filechecker tests 7:\n");
	len = ft_printf("\t|%X\n", 4294967296);
	len2 = printf("\t|%X\n", 4294967296);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);



	printf("\n1. mine, 2. unix: Testing 42filechecker tests 8:\n");
	len = ft_printf("\t|%llX\n", 4294967296);
	len2 = printf("\t|%llX\n", 4294967296);
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);


  	printf("\n1. mine, 2. unix: testing a percent sign\n");
	len = ft_printf("\t|wooow 1000%% or 1000%\\n"); 
	len2 = printf("\t|wooow 1000%% or 1000%\\n");  
	printf("\tmine: (%d)\n\tunix: (%d)\n", len, len2);}	*/
}
