/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cbijman <cbijman@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/01 11:59:54 by cbijman       #+#    #+#                 */
/*   Updated: 2022/11/02 19:39:18 by cbijman       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>

int		ft_printf(const char *s, ...);

/// @brief Writes a character to stdout
/// @param c: Character
/// @return Length of how many characters (Just 1)
int		ft_putchar(char c);

/// @brief Writes a string to stdout
/// @param s: char* that represents a string.
/// @return Length of the string send to stdout
int		ft_putstr(char *s);

/// @brief Writes a number to stdout
/// @param nb: Number that you desire to write to stdout
/// @return Total numbers
int		ft_putnbr(int nb);

/// @brief Writes a number to stdout
/// @param nb: Unsigned integer
/// @return Total numbers
int		ft_putunbr(unsigned int nb);

/// @brief Converts number to hex decimal
/// @param n 
/// @param type: 0 for lowercase and 1 for uppercase
/// @return Total hex length
int		ft_puthex(unsigned long int n, int type);

/* No documentation! */
int		ft_printptr(unsigned long int n);
int		ft_printhex(unsigned long int n, char flag);

#endif