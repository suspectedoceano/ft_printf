/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Oceano <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 12:07:58 by Oceano            #+#    #+#             */
/*   Updated: 2023/02/24 10:29:20 by utente           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * get the figures
 * in a digit
*/
int	ft_nbr_len(long nbr)
{
	if (nbr < 0)
		return (ft_nbr_len(nbr *= -1) + 1);
	else if (0 == nbr || (nbr > 0 && nbr < 10))
		return (1);
	else
		return (ft_nbr_len(nbr / 10) + 1);
}

/*
 * recursion that puts a long
 * returning the chars written
 * can handle how many bytes to write
 * '-' is considered a char(byte)
*/
int	ft_putnbr_long_precision(long nbr, int bytes)
{
	int	count;

	count = 0;
	if (!bytes)
		return (0);
	else if (nbr < 0 && bytes)
	{
		write(1, "-", 1);
		return (ft_putnbr_long_precision(nbr *= -1, bytes - 1) + 1);
	}
	else if (0 == nbr && bytes)
		return (write(1, "0", 1));
	else if ((nbr > 0 && nbr < 10) && bytes)
		return (ft_putchar(nbr + 48));
	else
	{
		count += ft_putnbr_long_precision(nbr / 10, bytes);
		if (bytes - (ft_nbr_len(nbr) - 1) > 0)
			bytes -= (ft_nbr_len(nbr) - 1);
		else
			return (count);
		ft_putnbr_long_precision(nbr % 10, bytes);
		return (count + 1);
	}
}
