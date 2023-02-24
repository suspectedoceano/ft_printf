/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 22:06:21 by Oceano            #+#    #+#             */
/*   Updated: 2023/02/24 10:30:20 by utente           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>//TODO
#include "ft_printf.h"

/*
 * With the char type only
 * 	~width
 * 	~left_justify
 * flags make sense.
*/

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

/*
 * Handles the flag '-'
*/
static int	ft_char_justify(char c, t_flags *flags)
{
	int	count;

	count = 0;
	if (!(flags->left_justified))
	{
		while (--(flags->width))
			count += ft_putchar(32);
		count += (ft_putchar(c));
		return (count);
	}
	else
	{
		count += (ft_putchar(c));
		while (--(flags->width))
			count += ft_putchar(32);
		return (count);
	}
}

int	ft_putchar_format(char c, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->width > 1)
		return (ft_char_justify(c, flags));
	return (ft_putchar(c));
}
