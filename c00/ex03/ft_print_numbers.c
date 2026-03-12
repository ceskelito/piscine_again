/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 10:18:52 by rceschel          #+#    #+#             */
/*   Updated: 2026/03/12 10:35:07 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_reverse_alphabet(void)
{
	char	curr;

	curr = '0';
	while (curr <= '9')
	{
		ft_putchar(curr);
		curr++;
	}
}
//
// int main( void ) {
// 	ft_print_alphabet();
// }
