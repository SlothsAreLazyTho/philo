/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_ptr.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 17:49:21 by cbijman       #+#    #+#                 */
/*   Updated: 2022/11/02 17:50:51 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptr(unsigned long int n)
{
	int	count;

	count = 0;
	count += ft_putstr("0x");
	count += ft_puthex(n, 0);
	return (count);
}
