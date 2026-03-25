/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 20:17:58 by rceschel          #+#    #+#             */
/*   Updated: 2026/03/25 20:34:49 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdbool.h>
#include <stddef.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define FILENAME_MISSING "File name missing.\n"
#define CANNOT_READ "Cannot read file.\n"
#define TOO_MANY_ARG "Too many arguments.\n"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	throw_argc_error(int ac)
{
	if (ac < 2)
	{
		write(STDERR_FILENO, FILENAME_MISSING, ft_strlen(FILENAME_MISSING));
		return (1);
	}
	else if (ac > 2)
	{
		write(STDERR_FILENO, TOO_MANY_ARG, ft_strlen(TOO_MANY_ARG));
		return (1);
	}
	return (0);
}

int	throw_cannot_read_error(int fd)
{
	if (fd == -1)
	{
		write(STDERR_FILENO, CANNOT_READ, ft_strlen(CANNOT_READ));
		return (1);
	}
	return (0);
}

#define BUFF_SIZE 42

int	main(int ac, char *av[])
{
	int	fd;
	int	buff[BUFF_SIZE];
	int	bytes_read;

	if (throw_argc_error(ac))
		return (0);
	fd = open(av[1], O_RDONLY);
	bytes_read = read(fd, buff, BUFF_SIZE);
	if (throw_cannot_read_error(bytes_read))
		return (0);
	while (bytes_read > 0 && buff[0])
	{
		write(STDOUT_FILENO, buff, BUFF_SIZE);
		bytes_read = read(fd, buff, BUFF_SIZE);
	}
}
