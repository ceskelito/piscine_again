/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 10:18:52 by rceschel          #+#    #+#             */
/*   Updated: 2026/03/12 10:34:57 by rceschel         ###   ########.fr       */
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

	curr = 'z';
	while (curr >= 'a')
	{
		ft_putchar(curr);
		curr--;
	}
}
//
// int main( void ) {
// 	ft_print_alphabet();
// }
