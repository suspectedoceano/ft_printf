/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 11:07:00 by Oceano            #+#    #+#             */
/*   Updated: 2023/02/24 10:42:39 by utente           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * ~THE '0' PAD FLAG
 * 	if '0 pad' and '-'
 * 		zero is ignored.
 *  if 'precision' 
 *  	zero is ignored
 *	
 * ~THE '-' FLAG
 *  '-' overrides '0' if both
 *
 * ~SPACE
 *  A blank should be left before a positive number
 *  A '+' overrides a space if both are used.
 *
 * ~PRECISION
 *  If the precision is given as just '.', 
 *  the precision is taken to bezero.
 *  With 'd' or 'i' precision just:
 * 		 ~ > len_nbr pad with 0
 *  	 ~ < nothing
 *
*/

static int	ft_cornercase_precision(long nbr, t_flags *flags)
{
	int	count;
	int	corner;

	corner = flags->width - flags->precision_value;
	count = 0;
	count += ft_pad_char(32, corner - (flags->plus_sign | flags->space));
	count += ft_handle_plus_space(nbr, 1, flags);
	count += ft_pad_char(48, flags->precision_value - ft_nbr_len(nbr));
	count += ft_putnbr_long_precision(nbr, ft_nbr_len(nbr));
	return (count);
}

static int	ft_rigth_justify_nbr(long nbr, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->precision_point)
	{
		if (flags->precision_value >= flags->width)
		{
			count += ft_handle_plus_space(nbr, 1, flags);
			count += ft_pad_char(48, flags->precision_value - flags->width);
			count += ft_putnbr_long_precision(nbr, ft_nbr_len(nbr));
		}
		else if (flags->precision_value < flags->width)
			count += ft_cornercase_precision(nbr, flags);
	}
	else if (!flags->precision_point)
	{
		count += ft_handle_plus_space(nbr, 1, flags);
		count += ft_pad_char(32, flags->width - ft_nbr_len(nbr));
		count += ft_putnbr_long_precision(nbr, ft_nbr_len(nbr));
	}
	return (count);
}

/*
 * [.precision] more imporant than width when major
 * [width] more imporant when [precision] < [width]
*/

static int	ft_left_justify_nbr(long nbr, t_flags *flags)
{
	int	count;
	int	corner;

	corner = flags->width - (ft_nbr_len(nbr));
	corner += (flags->plus_sign | flags->space);
	count = 0;
	if (flags->precision_point)
	{
		if (flags->precision_value > flags->width)
		{
			count += ft_handle_plus_space(nbr, 1, flags);
			count += ft_pad_char(48, flags->precision_value - flags->width);
			count += ft_putnbr_long_precision(nbr, ft_nbr_len(nbr));
		}
	}
	else if (!(flags->precision_point))
	{
		count += ft_handle_plus_space(nbr, 1, flags);
		count += ft_putnbr_long_precision(nbr, ft_nbr_len(nbr));
		count += ft_pad_char(32, flags->width - corner);
	}
	return (count);
}

int	ft_putnbr_format(long nbr, t_flags *flags)
{
	int	count;
	int	precision;

	precision = flags->precision_value - ft_nbr_len(nbr);
	count = 0;
	if (flags->width > ft_nbr_len(nbr))
	{
		if (flags->left_justified)
			count += ft_left_justify_nbr(nbr, flags);
		else if (!(flags->left_justified))
			count += ft_rigth_justify_nbr(nbr, flags);
	}
	else if (flags->width <= ft_nbr_len(nbr))
	{
		count += ft_handle_plus_space(nbr, 1, flags);
		if (flags->precision_value > ft_nbr_len(nbr))
			count += ft_pad_char('0', precision);
		count += ft_putnbr_long_precision(nbr, ft_nbr_len(nbr));
	}
	return (count);
}

int	ft_putunsigned_format(unsigned int nbr, t_flags *flags)
{
	return (ft_putnbr_format((long)nbr, flags));
}
