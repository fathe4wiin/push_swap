/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfathi <bfathi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 04:33:26 by bfathi            #+#    #+#             */
/*   Updated: 2026/01/11 23:02:54 by bfathi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

char	*gnl_strchr(char *str, int c);
char	*get_next_line(int fd);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_substr(char *s, unsigned int start, size_t len);
size_t	gnl_strlen(const char *str);
char	*gnl_strdup(const char *src);
void	*gnl_calloc(size_t nmemb, size_t size);
void	gnl_bzero(void *ptr, size_t num);
#endif