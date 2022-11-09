/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:10:34 by aronez            #+#    #+#             */
/*   Updated: 2022/12/04 23:10:34 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

size_t		ft_smin(size_t a, size_t b);
void		*ft_calloc(size_t num, size_t size);
char		*ft_lltoa_base(long long n, const char *base);
int			ft_ulog(unsigned long long n, int base);
void		*ft_memset(void *dest, int ch, size_t count);
char		*ft_strchr(const char *str, int ch);
size_t		ft_strlen(const char *str);
size_t		ft_strnlen(const char *str, size_t count);
char		*ft_strdup(const char *src);
char		*ft_strndup(const char *src, size_t count);
char		*ft_strsnjoin(const char **strs, size_t count);
void		ft_putchar_fd(char c, int fd);
void		ft_putstrn_fd(const char *str, size_t count, int fd);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strcat(char *dest, const char *src);
char		*ft_strcpy(char *dest, const char *src);
char		*ft_ulltoa_base(unsigned long long n, const char *base);

#endif
