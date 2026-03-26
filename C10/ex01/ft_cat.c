/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rceschel <rceschel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 20:17:58 by rceschel          #+#    #+#             */
/*   Updated: 2026/03/26 12:08:58 by rceschel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <libgen.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFF_SIZE 42

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_perror(char *name, char *file)
{
	char	*err_str;

	err_str = strerror(errno);
	write(STDERR_FILENO, name, ft_strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, file, ft_strlen(file));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, err_str, ft_strlen(err_str));
	write(STDERR_FILENO, "\n", 1);
}

int	print_file_contet(int fd)
{
	int	bytes_read;
	int	buff[BUFF_SIZE];

	bytes_read = read(fd, buff, BUFF_SIZE - 1);
	if (bytes_read == -1)
		return (1);
	while (bytes_read > 0 && buff[0])
	{
		write(STDOUT_FILENO, buff, bytes_read);
		bytes_read = read(fd, buff, BUFF_SIZE - 1);
		if (bytes_read == -1)
			return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	fd;
	int	i;

	if (argc < 2)
	{
		print_file_contet(STDIN_FILENO);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
			ft_perror(basename(argv[0]), argv[i]);
		else if (print_file_contet(fd) != 0)
			ft_perror(basename(argv[0]), argv[i]);
		i++;
	}
}
