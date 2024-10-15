/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 14:23:52 by mel-jira          #+#    #+#             */
/*   Updated: 2024/01/03 10:21:50 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_helper(int n)
{
	if (n > 9)
	{
		ft_putnbr_helper(n / 10);
	}
	ft_putchar(n % 10 + 48);
}

void	ft_putnbr(int n)
{
	ft_putnbr_helper(n);
	write(1, "\n", 1);
}
