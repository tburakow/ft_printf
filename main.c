/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tburakow <tburakow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:39:29 by tburakow          #+#    #+#             */
/*   Updated: 2022/03/16 14:53:05 by tburakow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	long long	buzz;
	char	*z;
	char	**c;
	int	x;
	int	y;
	int	ret;
	unsigned short shit;
	unsigned char torspo;
	long double tantor;
	
	tantor = 234567.1023;
	shit = 167;
	torspo = 't';
	buzz = 100000;
	z = "Elvis";
	c = &z;
	x = 6;
	y = 9;
	ret = 0;
/* 	//ret = ft_printf("elvis\n%i\n%x\n%X\n%%\n%p\n\n", 67, 120456, 120456, NULL);
	//printf("\n");
	//printf("elvis\n%i\n%x\n%X\n%%\n%p\n", 67, 120456, 120456, NULL);
	//ret = ft_printf("\nMe: X%+20lliX\n\n", -25);
	//ret = ft_printf("\nMe: X%+20iX\n\n", 25);
	ret = ft_printf("\nMe: X%20.8iX\n\n", 25);
	ret = ft_printf("\nMe: X%xX\n\n", 25);
	ret = ft_printf("\nMe: X%-+20.8iX\n\n", 25);
	ret = ft_printf("\nMe: X%+20.8hiX\n\n", 25);
	//ret = ft_printf("\nMe: X%-20.5iX\n\n", 2567890);
	//printf("It: X%20iX\n", -25);
	//printf("It: X%+020iX\n", 25);
	//printf("It: X%+020iX\n", -25);
	printf("It: X%20.8iX\n\n", 25);
	printf("It: X%-+20.8iX\n", 25);
	//printf("It: X%+20.8hiX\n", 10234);
	ft_printf("Me: X%.3fX\n\n", 2.90890989);
	printf("It: X%.3fX\n\n", 2.90890989);
	ft_printf("Me: X%.fX\n\n", 2.90890989);
	printf("It: X%.fX\n\n", 2.90890989);
	ft_printf("Me: X%06.3fX\n\n", -2.90890989);
	printf("It: X%06.3fX\n\n", -2.90890989);
	//printf("It: X%-20.5iX\n", 2567890);
	//printf("It: X%+20.32lliX\n", buzz);
	ft_printf("MEiz: %hhX\n", torspo);
	ft_printf("MEiz: %hX\n", shit);
	ret =ft_printf("MEiz: %llX\n", buzz);
	ft_printf("MEiz: %lX\n", (long)buzz);
	ft_printf("MEiz: %Lf\n", tantor);
	ft_printf("MEiz: %o\n", -56);
	ft_printf("\n%d\n\n", ret);
	printf("Seee: %hhX\n", torspo);
	printf("Seee: %hX\n", shit);
	ret = printf("Seee: %llX\n", buzz);
	printf("Seee: %lX\n", (long)buzz);
	printf("Seee: %Lf\n", tantor);
	printf("Seee: %o\n", -56);
	ft_printf("\n%d\n", ret);


  	ft_printf("\\n");
	printf("\\n"); */
/* 	ret = ft_printf("%x\n", -49);
	ret = printf("%x\n", -49); */

	ft_printf("\n%#08x\n", 42);
	printf("\n%#08x\n", 42);
	printf("\n\n");
	ft_printf("|% 10%|");
	printf("\n\n");
	printf("|% 10%|");
	printf("\n\n");
	ft_printf("@moulitest: %#.x %#.0x", 0, 0);
	printf("\n\n");
	printf("@moulitest: %#.x %#.0x", 0, 0);
	printf("\n\n");
	ft_printf("%.2s is a string", "this");
	printf("\n\n");
	printf("%.2s is a string", "this");
	printf("\n\n");
	ft_printf("@moulitest: %s", NULL);
	printf("\n\n");
	printf("@moulitest: %s", NULL);
	printf("\n\n");
	ft_printf("@moulitest: %c", 0);
	printf("\n\n");
	printf("@moulitest: %c", 0);
	printf("\n\n");
	ft_printf("%x", 176);
	printf("\n\n");
	printf("%x", 176);
	printf("\n\n");
	ft_printf("%ld", 2147483648);
	
/* 	ret = ft_printf("%d\n", 100);
	printf("\n\n%u", ret);
	printf("\n\n");
	printf("%d\n\n", 100); */
	
	if (ret > 0)
		return (1);
	return (0);
}
// for integer # -flag doesn't work.