/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <tgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:13:52 by tgrasset          #+#    #+#             */
/*   Updated: 2023/01/03 10:58:32 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

void    display_moves(t_var *var)
{
    char    *temp;
    char    *temp2;
    char    *info;
    
    temp = ft_strdup("MOVES : ");
    temp2 = ft_itoa(var->move);
    info = ft_strjoin(temp, temp2);
    mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->info.mlx_img, 0, 0);
    mlx_string_put(var->mlx_ptr, var->win_ptr, 30, 10, 0x509B66, info);
    free(info);
    free(temp);
    free(temp2);
}