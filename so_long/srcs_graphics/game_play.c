/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:38:02 by tgrasset          #+#    #+#             */
/*   Updated: 2022/12/28 17:10:57 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

int move_right(t_var *var)
{
    ft_printf("%p\n", var->scr.addr);
    ft_printf("RIGHT\n");
    return (0);
}

int move_down(t_var *var)
{
    ft_printf("%p\n", var->scr.addr);
    ft_printf("DOWN\n");
    return (0);
}

int move_left(t_var *var)
{
    ft_printf("%p\n", var->scr.addr);
    ft_printf("LEFT\n");
    return (0);
}

int move_up(t_var *var)
{
    ft_printf("%p\n", var->scr.addr);
    ft_printf("UP\n");
    return (0);
}

int keypress(int key, t_var *var)
{
    if (key == 0xff1b)
    {
        game_quit(var);
        exit (0);
    }
    else if (key == 0x0064)
        move_right(var);
    else if (key == 0x0073)
        move_down(var);
    else if (key == 0x0061)
        move_left(var);
    else if (key == 0x0077)
        move_up(var);
    return (0);
}