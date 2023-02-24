/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:10:41 by Oceano            #+#    #+#             */
/*   Updated: 2023/02/24 10:28:47 by utente           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned long hex_value)
{
	if (hex_value >= 0 && hex_value < 16)
		return (1);
	return (ft_hex_len(hex_value / 16) + 1);
}

int	ft_puthex(unsigned long hex_value, t_flags *flags)
{
	char	*symbols;
	int		count;

	count = 0;
	symbols = "0123456789ABCDEF";
	if (hex_value >= 0 && hex_value < 16)
	{
		if (flags->is_upper || hex_value < 10)
			return (ft_putchar(symbols[hex_value]));
		else
			return (ft_putchar(symbols[hex_value] + 32));
	}
	else
	{
		count += ft_puthex(hex_value / 16, flags);
		ft_puthex(hex_value % 16, flags);
		return (count + 1);
	}	
}
