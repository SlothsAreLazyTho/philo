/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_hex.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 12:06:30 by cbijman       #+#    #+#                 */
/*   Updated: 2022/11/02 17:50:23 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned long int n, char flag)
{
	if (flag == 'x')
		return (ft_puthex(n, 0));
	else if (flag == 'X')
		return (ft_puthex(n, 1));
	return (0);
}
