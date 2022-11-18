/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:56:01 by tgrasset          #+#    #+#             */
/*   Updated: 2022/11/18 16:20:37 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H

# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*keep_remainder(char *storage);
char	*extract_line(char *storage);
char	*read_and_store(char *storage, int fd);
char	*join_and_free(char *s1, char *s2);
char	*ft_strchr(char *s, char c);
size_t	ft_strlen(char *s);
char	*empty_str(void);

#endif
