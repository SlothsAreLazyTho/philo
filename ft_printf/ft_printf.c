/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 12:51:06 by cbijman       #+#    #+#                 */
/*   Updated: 2022/11/02 19:38:12 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdarg.h>

static size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	is_flag(char flag)
{
	if (flag == 'c' || flag == 's' || flag == 'p'
		|| flag == 'd' || flag == 'i' || flag == 'u'
		|| flag == 'x' || flag == 'X' || flag == '%')
		return (1);
	return (0);
}

static int	convert(char flag, va_list args)
{
	if (flag == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (flag == 'i' || flag == 'd')
		return (ft_putnbr(va_arg(args, int)));
	if (flag == 'u')
		return (ft_putunbr(va_arg(args, unsigned int)));
	if (flag == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (flag == 'p')
		return (ft_printptr(va_arg(args, unsigned long int)));
	if (flag == 'x' || flag == 'X')
		return (ft_printhex(va_arg(args, unsigned int), flag));
	if (flag == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	size_t		i;
	size_t		size;
	size_t		length;
	va_list		args;

	if (!s)
		return (0);
	i = 0;
	length = 0;
	size = ft_strlen(s);
	va_start(args, s);
	while (i < size)
	{
		if (s[i] == '%' && is_flag(s[++i]))
			length += convert(s[i], args);
		else
			length += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (length);
}

//#include <stdio.h>
//int	main(void)
//{
//	int		result1;
//	int		result2;
//	int		result3;
//	int		result4;
//	int		result5;
//	int		result6;
//	int		result7;
//	int		result8;
//	int		*result9;
//	int		result10;
//	int		result11;
//	int		result12;
//	int		result13;
//	int		result14;
//	int		result15;
//
//	result1 = printf("%s - %s\n", "Hello there!", "Obi-one kanobi");
//	result2 = ft_printf("%s - %s\n", "Hello there!", "Obi-one kanobi");
//	ft_printf("Expected: %d, Result: %d\n", result1, result2);
//	ft_printf("--------------------END TEST 1--------------------\n\n");
//	result3 = printf("NULL %s NULL\n", NULL);
//	result4 = ft_printf("NULL %s NULL\n", NULL);
//	ft_printf("Expected: %d, Result: %d\n", result3, result4);
//	ft_printf("--------------------END TEST 2--------------------\n\n");
//	result5 = printf("%c and %c are not equal, one is uppercase\n", 'a', 'A');
//	result6 = ft_printf("%c and %c are not equal, one is lowercase\n", 'A', 'a');
//	ft_printf("Expected: %d, Result: %d\n", result5, result6);
//	ft_printf("--------------------END TEST 3--------------------\n\n");
//	result7 = printf(    "%% % % % % %%%% % % % %% %%%\n");
//	result8 = ft_printf("%% % % % % %%%% % % % %% %%%\n");
//	ft_printf("Expected: %d, Result: %d\n", result7, result8);
//	ft_printf("--------------------END TEST 4--------------------\n\n");
//	result9 = &result8;
//	result10 = printf("Cool pointer incoming -> %p\n", result9);
//	result11 = ft_printf("Cool pointer incoming -> %p\n", result9);
//	ft_printf("[Size] Expected: %d, Result: %d\n", result10, result11);
//	ft_printf("--------------------END TEST 5--------------------\n\n");
//	result12 = printf("%u is not %u without %u\n", 9, 21, 10);
//	result13 = ft_printf("%u is not %u without %u\n", 9, 21, 10);
//	ft_printf("[Size] Expected: %d, Result: %d\n", result12, result13);
//	ft_printf("--------------------END TEST 6--------------------\n\n");
//	result14 = printf("#%x is cool but #%X = better\n", 4360181, 9772233);
//	result15 = ft_printf("#%x is cool but #%X = better\n", 4360181, 9772233);
//	ft_printf("[Size] Expected: %d, Result: %d\n", result14, result15);
//	ft_printf("--------------------END TEST 7--------------------\n\n");
//	int result16 = printf(   "%X436g%xc7i%X?4> \n", 1307330508, -80257127, 1950611107);
//	int result17 = ft_printf("%X436g%xc7i%X?4> \n", 1307330508, -80257127, 1950611107);
//	ft_printf("[Size] Expected: %d, Result: %d\n", result16, result17);
//	ft_printf("--------------------END TEST 8--------------------\n\n");
//	int result18 = printf(   "jWSjiZD`(%%}v0il4T\f E%X[~@3I9GsBX%%\{{=\vlAk|%i5]W]%dvVb>SpT%XG{%XCzV|!b%i0J%X\n", 1601843095, 868503380, -31394902, -60627185, -337451764, 874074370, -681403271);
//	int result19 = ft_printf("jWSjiZD`(%%}v0il4T\f E%X[~@3I9GsBX%%\{{=\vlAk|%i5]W]%dvVb>SpT%XG{%XCzV|!b%i0J%X\n", 1601843095, 868503380, -31394902, -60627185, -337451764, 874074370, -681403271);	
//	ft_printf("[Size] Expected: %d, Result: %d\n", result18, result19);
//	ft_printf("--------------------END TEST 9--------------------\n\n");
//	return (0);
//}
