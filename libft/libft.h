/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grochefo <grochefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:25:19 by grochefo          #+#    #+#             */
/*   Updated: 2020/02/20 18:24:48 by grochefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

char		*ft_strjoinplus(char *s1, char *s2, int c);
char		*ft_strdup(const char *src);
char		*ft_strnew(size_t size);
char		*ft_strcpy(char *dest, const char *src);
void		*ft_calloc(size_t nmemb, size_t size);
size_t		ft_strlen(const char *s);
char		*ft_strcat(char *dest, const char *src);
void		ft_strdel(char **as);
void		ft_memdel(void **ap);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *s, int c, size_t n);
int			get_next_line(int fd, char **line);
size_t		ft_strlenn(const char *s, char c);
char		*ft_strjoinspe(char *s1, char *s2);
void		ft_strncpy(char *dest, char *src, char c);
#endif