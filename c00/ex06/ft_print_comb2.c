/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 10:17:40 by rceschel          #+#    #+#             */
/*   Updated: 2026/03/12 13:39:43 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_quad(char a, char b, char c, char d)
{
	if (a == c && b == d)
		return ;
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, " ", 1);
	write(1, &c, 1);
	write(1, &d, 1);
	if (a == '9' && b == '8' && c == '9' && d == '9')
		return ;
	write(1, ", ", 2);
}

void	inner_cicle(int a, int b)
{
	int	c;
	int	d;

	c = '0';
	while (c <= '9')
	{
		d = '0';
		while (d <= '9')
		{
			ft_putchar_quad(a, b, c, d);
			d++;
		}
		c++;
	}

}

void	ft_print_comb(void)
{
	int	a;
	int	b;
	int	c;
	int	d;

	a = '0';
	while (a <= '9')
	{
		b = '0';
		while (b <= '8')
		{
			inner_cicle(a, b);
			b++;
		}
		a++;
	}
	write(1, "\n", 1);
}

int	main( void )
{
	ft_print_comb();
}
