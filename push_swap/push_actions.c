/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 10:38:08 by tgrasset          #+#    #+#             */
/*   Updated: 2022/12/09 10:38:10 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

int    push(t_stack **src, t_stack **dst)
{
    t_stack *stock;
    t_stack *stock2;

    stock = *src;
    if (stock == NULL)
        return (0);
    *src = stock->next;
    stock2 = *dst;
    *dst = stock;
    (*dst)->next = stock2;
    return (1);
}

void    pb(t_stack **a, t_stack **b)
{
    if (push(a, b) == 1)
        ft_printf("pb\n");
}

void    pa(t_stack **a, t_stack **b)
{
    if (push(b, a) == 1)
        ft_printf("pa\n");
}   
