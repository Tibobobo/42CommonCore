/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:43:05 by tgrasset          #+#    #+#             */
/*   Updated: 2022/11/14 17:48:08 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define BUFFER_SIZE 42;

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);

#endif
