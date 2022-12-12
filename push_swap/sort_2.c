/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:35:43 by tgrasset          #+#    #+#             */
/*   Updated: 2022/12/12 19:35:46 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

void    sort_100(t_stack **a, t_stack **b)
{
    int     chunk_end;
    int     i;
    t_stack *scan;

    chunk_end = 20;
    i = 1;
    scan = *a;
    while (*a != NULL)
    {
        while (i <= chunk_end)
        {
            smart_rotate(a, chunk_end -19, chunk_end);
            smart_push(a, b);
            i++;
        }
        chunk_end = chunk_end + 20;
    }
    while ((*b)->num != get_biggest(b))
        rb(b);          //A OPTI ET MARCHE PAS
    while (*b != NULL)
        pa(a, b);
}

void    smart_rotate(t_stack **a, int start, int end)
{
    if (*a != NULL)
    {
        if (get_smartest_rotation(*a, start, end) == 1)
            while ((*a)->index < start || (*a)->index > end)
                ra(a);
        else
            while((*a)->index < start || (*a)->index > end)
                rra(a);
    }
}

void    smart_push(t_stack **a, t_stack **b)
{
    if (stack_size(*b) < 2 && *a != NULL)
    {
        pb(a, b);
        return ;
    }
    while ((*a) != NULL && (*a)->index < (*b)->index)
        rb(b);              //A OPTI ET MARCHE PAS
    if (*a != NULL)
        pb(a, b);
}

int get_smartest_rotation(t_stack *a, int c_start, int c_end)
{
    t_stack *elem;
    int     begin_count;
    int     end_count;
    int     total_count;

    elem = a;
    begin_count = 0;
    end_count = 0;
    total_count = 0;
    while (elem != NULL && (elem->index <= c_start || elem->index >= c_end))
    {
        begin_count++;
        elem = elem->next;
    }
    elem = a;
    while (elem != NULL && end_count < 20)
    {
        if (elem->index >= c_start && elem->index <= c_end)
            end_count++;
        elem = elem->next;
        total_count++;
    }
    end_count = stack_size(a) - total_count;
    if (begin_count >= end_count)
        return (1);
    else
        return (-1);
}