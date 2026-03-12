/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 10:17:40 by rceschel          #+#    #+#             */
/*   Updated: 2026/03/12 12:03:23 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_triple(char a, char b, char c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
}

void	ft_print_actual_comb(int i, int j, int k)
{
	if (i == j || i == k || j == k)
		return ;
	ft_putchar_triple(i, j, k);
	if (!(i == '7' && j == '8' && k == '9'))
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = '0';
	while (i <= '7')
	{
		j = '1';
		while (j <= '8')
		{
			k = '2';
			while (k <= '9')
			{
				ft_print_actual_comb(i, j, k);
				k++;
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
}

// int	main( void )
// {
// 	ft_print_comb();
// }
