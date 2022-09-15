#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

size_t		ft_smin(size_t a, size_t b);
long long	ft_llabs(long long n);
void		*ft_calloc(size_t num, size_t size);
char		*ft_lltoa_base(long long n, const char *base);
int 		ft_log(long long n, int base);
void		*ft_memset(void *dest, int ch, size_t count);
char		*ft_strchr(const char *str, int ch);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *src);
char		*ft_strndup(const char *src, size_t count);
char		*ft_strsnjoin(const char **strs, size_t count);
void		ft_putstr_fd(const char *str, int fd);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strcat(char *dest, const char *src);
char		*ft_strcpy(char *dest, const char *src);

#endif
