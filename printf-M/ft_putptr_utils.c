/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:54:58 by Oceano            #+#    #+#             */
/*   Updated: 2023/02/24 10:34:02 by utente           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptr_justify(unsigned long ptr_value, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->left_justified)
	{
		count += write(1, "0x", 2);
		count += ft_puthex(ptr_value, flags);
		count += ft_pad_char(32, flags->width - (ft_hex_len(ptr_value) + 2));
	}
	else
	{
		count += ft_pad_char(32, flags->width - (ft_hex_len(ptr_value) + 2));
		count += write(1, "0x", 2);
		count += ft_puthex(ptr_value, flags);
	}
	return (count);
}

int	ft_putptr_format(void *ptr, t_flags *flags)
{
	unsigned long	ptr_value;
	int				count;

	count = 0;
	ptr_value = (unsigned long)ptr;
	if (flags->width > ft_hex_len(ptr_value) + 2)
	{
		count += ft_ptr_justify(ptr_value, flags);
	}
	else
	{
		count += write(1, "0x", 2);
		count += ft_puthex(ptr_value, flags);
	}
	return (count);
}
