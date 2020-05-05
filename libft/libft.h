/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzie <suzie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:25:19 by grochefo          #+#    #+#             */
/*   Updated: 2020/05/05 19:12:39 by suzie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

#define BUFFER_SIZE 100

int         ft_atoi(const char *str);
void	    ft_bzero(void *s, size_t n);
void        *ft_calloc(size_t nmemb, size_t size);
int	        ft_isdigit(int c);
void	    *ft_memcpy(void *dest, const void *src, size_t n);
void	    ft_memdel(void **ap);
void	    *ft_memset(void *s, int c, size_t n);
char	    *ft_strcat(char *dest, const char *src);
char	    *ft_strcpy(char *dest, const char *src);
void	    ft_strdel(char **as);
char		*ft_strdup(const char *src);
char	    *ft_strjoinnplus(char *s1, char *s2, int c, size_t len2);
char	    *ft_strjoinplus(char *s1, char *s2, int c);
size_t	    ft_strlen(const char *s);
size_t	    ft_strlenn(const char *s, char c);
char	    *ft_strncat(char *dest, const char *src, size_t n);
char	    *ft_strncpy(char *dest, const char *src, size_t n);
char	    *ft_strndup(const char *src, size_t n);
char	    *ft_strnew(size_t size);
int			get_next_line(const int fd, char **line);
#endif