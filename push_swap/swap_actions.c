/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:45:45 by tgrasset          #+#    #+#             */
/*   Updated: 2022/12/09 09:45:48 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

int    swap(t_stack **stack)
{
    int temp;

    if (*stack == NULL || (*stack)->next == NULL)
        return (0);
    temp = (*stack)->num;
    (*stack)->num = (*stack)->next->num;
    (*stack)->next->num = temp;
    return (1);
}

void    sb(t_stack **b)
{
    if (swap(b) == 1)
        ft_printf("sb\n");
}

void    sa(t_stack **a)
{
    if (swap(a) == 1)
        ft_printf("sa\n");
}

void    ss(t_stack **a, t_stack **b)
{
    if (swap(a) == 1 && swap(b) == 1)
        ft_printf("ss\n");
}