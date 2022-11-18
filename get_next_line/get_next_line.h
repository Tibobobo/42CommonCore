/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrasset <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:43:05 by tgrasset          #+#    #+#             */
/*   Updated: 2022/11/18 11:41:23 by tgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

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
