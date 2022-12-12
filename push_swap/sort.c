/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 09:56:07 by tgrasset          #+#    #+#             */
/*   Updated: 2022/12/12 09:56:08 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

void    sort(t_stack **a, t_stack **b)
{
    int size;

    size = stack_size(*a);
    if (size == 2)
        (sa(a));
    else if (size == 3)
       sort_3(a);
    else if (size == 4)
        sort_4(a, b);
    else if (size == 5)
       sort_5(a, b);
    else if (size <= 100)
        sort_100(a, b);
    /*else if (size <= 500)
        sort_500(a, b);
    else 
        sort_osef(*a, *b);*/
}

void    sort_3(t_stack **a)
{
    if ((*a)->num > (*a)->next->num && (*a)->num < (*a)->next->next->num)
        sa(a);
    else if ((*a)->next->num < (*a)->num && (*a)->next->num > (*a)->next->next->num)
    {
        sa(a);
        rra(a);
    }
    else if ((*a)->next->next->num > (*a)->next->num && (*a)->next->next->num < (*a)->num)
        ra(a);
    else if ((*a)->next->next->num > (*a)->num && (*a)->next->next->num < (*a)->next->num)
    {
        sa(a);
        ra(a);
    }
    else if ((*a)->num < (*a)->next->num && (*a)->num > (*a)->next->next->num)
        rra(a);
}

void    sort_4(t_stack **a, t_stack **b)
{
    int smallest;
    int smallest_pos;

    smallest = get_smallest(a);
    smallest_pos = get_position(a, smallest);
    if (smallest_pos == 4)
        rra(a);
    else if (smallest_pos == 2)
        ra(a);
    else if (smallest_pos == 3)
    {
        ra(a);
        ra(a);
    }
    pb(a, b);
    sort_3(a);
    pa(a, b);
}

void    sort_5(t_stack **a, t_stack **b)
{
    int smallest;
    int smallest_pos;

    smallest = get_smallest(a);
    smallest_pos = get_position(a, smallest);
    if (smallest_pos <= 3)
        while ((*a)->num != smallest)
            ra(a);
    else
        while ((*a)->num != smallest)
            rra(a);
    pb(a,b);
    sort_4(a, b);
    pa(a, b);
}