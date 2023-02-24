/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:06:29 by Oceano            #+#    #+#             */
/*   Updated: 2023/02/24 10:13:59 by utente           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * Takes care bout [+_]
*/
int	ft_pad_char(char c, int bytes)
{
	int	count;

	count = 0;
	while (bytes--)
		count += ft_putchar(c);
	return (count);
}

/*
 * '+' overrides ' ' if both are used
 *  
 *  writes '+' or 'space' if bytes (given by precision)
*/
int	ft_handle_plus_space(long nbr, int bytes, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->plus_sign && bytes && nbr > 0)
		count += ft_putchar('+');
	else if (flags->space && !(flags->plus_sign) && bytes)
		count += ft_putchar(' ');
	return (count);
}
