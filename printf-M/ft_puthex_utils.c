/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:08:47 by Oceano            #+#    #+#             */
/*   Updated: 2023/02/24 10:32:53 by utente           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_rigthjustified(unsigned long hex_value, t_flags *flags)
{
	int	count;
	int	len;

	len = ft_hex_len(hex_value);
	count = 0;
	if (!flags->precision_point)
	{
		count += ft_pad_char(32, flags->width - len);
		count += ft_puthex(hex_value, flags);
	}
	else if (flags->precision_point && (flags->precision_value > flags->width))
	{
		count += ft_pad_char(48, flags->precision_value - len);
		count += ft_puthex(hex_value, flags);
	}
	return (count);
}

static int	ft_hex_leftjustified(unsigned long hex_value, t_flags *flags)
{
	int	count;
	int	len;

	len = ft_hex_len(hex_value);
	count = 0;
	if (!flags->precision_point)
	{
		count += ft_puthex(hex_value, flags);
		count += ft_pad_char(32, flags->width - len);
	}
	else if (flags->precision_point && (flags->precision_value > flags->width))
	{
		count += ft_pad_char(48, flags->precision_value - len);
		count += ft_puthex(hex_value, flags);
	}
	return (count);
}

int	ft_puthex_format(long hex_value_to_cast, t_flags *flags)
{
	int				count;
	unsigned long	hex_value;

	hex_value = (unsigned long)hex_value_to_cast;
	count = 0;
	if (flags->width > ft_hex_len(hex_value))
	{
		if (flags->left_justified)
			count += ft_hex_leftjustified(hex_value, flags);
		else if (!flags->left_justified)
			count += ft_hex_rigthjustified(hex_value, flags);
	}
	else if (flags->width <= ft_hex_len(hex_value))
	{
		if (flags->precision_value > ft_hex_len(hex_value))
		{
			count += ft_pad_char(48, flags->precision_value - flags->width);
			count += ft_puthex(hex_value, flags);
		}
		count += ft_puthex(hex_value, flags);
	}
	return (count);
}
