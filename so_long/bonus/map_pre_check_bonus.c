/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pre_check_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:44:00 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/02 17:41:19 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "../libft/libft.h"

void	ft_error(int num)
{
	if (num == 1)
	{
		ft_putstr_fd("Error\nso_long must be executed with map path only\n", 2);
		exit(1);
	}
	if (num == 2)
	{
		ft_putstr_fd("Error\nMap must be a valid .ber file\n", 2);
		exit(1);
	}
	if (num == 3)
	{
		ft_putstr_fd("Error\nMap couldn't be read or file doesn't exist\n", 2);
		exit(1);
	}
	if (num == 4)
	{
		ft_putstr_fd("Error\nMap content invalid\n", 2);
		exit(1);
	}
	if (num == 5)
	{
		ft_putstr_fd("Error\nMap is impossible to finish\n", 2);
		exit(1);
	}
}

static int	valid_extension(char *file)
{
	int	i;

	i = 0;
	while (file[i] != '\0')
		i++;
	i--;
	if (ft_strlen(file) < 5 || file[i] != 'r' || file[i - 1] != 'e'
		|| file[i - 2] != 'b' || file[i - 3] != '.' || file[i - 4] == '/')
		return (0);
	return (1);
}

void	map_pre_check(int ac, char **av)
{
	if (ac != 2)
		ft_error(1);
	if (valid_extension(av[1]) == 0)
		ft_error(2);
}
