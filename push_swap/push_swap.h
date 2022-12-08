/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:45:24 by tgrasset          #+#    #+#             */
/*   Updated: 2022/12/08 12:43:03 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}					t_stack;
long int	ft_atol(const char *nptr);
int			valid_args(char	**arg);
int			no_doubles(char **arg);
int			arg_error(void);
t_stack		*init_stack_a(t_stack *a, int ac, char **av);
t_stack		*new_elem(int num);

#endif
