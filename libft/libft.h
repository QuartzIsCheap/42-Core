
#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                                                                          ///
///                             Math Functions                               ///
///                                                                          ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

//! @brief Returns the smallest int.
int			ft_min(int a, int b);
//! @brief Returns the smallest size_t.
size_t		ft_smin(size_t a, size_t b);
//! @brief Returns the smallest long.
long		ft_lmin(long a, long b);
//! @brief Returns the smallest long long.
long long	ft_llmin(long long a, long long b);

//! @brief Returns the largest int.
int			ft_max(int a, int b);
//! @brief Returns the largest size_t.
size_t		ft_smax(size_t a, size_t b);
//! @brief Returns the largest long.
long		ft_lmax(long a, long b);
//! @brief Returns the largest long long.
long long	ft_llmax(long long a, long long b);

//! @brief Returns the absolute value of an int. Returns INT_MAX if n is
//! INT_MIN.
int			ft_abs(int n);
//! @brief Returns the absolute value of a long. Returns LONG_MAX if n is
//! LONG_MIN.
long		ft_labs(long n);
//! @brief Returns the absolute value of a long long. Returns LLONG_MAX if n is
//! LLONG_MIN.
long long	ft_llabs(long long n);

//! @brief Computes the base-10 logarithm of the given number. An input in
//! [-(base-1), base-1] gives 0, etc. The value of base must be more than one.
int			ft_log(long long n, int base);
//! @brief Computes the base-10 logarithm of the given number. An input in
//! [0, base-1] gives 0, etc. The value of base must be more than one.
int 		ft_ulog(unsigned long long n, int base);

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                                                                          ///
///                             Char Functions                               ///
///                                                                          ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

//! @brief Checks if the given character is an upper-case letter.
int			ft_isupper(int ch);
//! @brief Checks if the given character is a lower-case letter.
int			ft_islower(int ch);
//! @brief Checks if the given character is a letter.
int			ft_isalpha(int ch);

//! @brief Checks if the given character is a digit.
int			ft_isdigit(int ch);
//! @brief Checks if the given character is a hexadecimal digit (lower and
//! upper-case).
int			ft_isxdigit(int ch);

//! @brief Checks if the given character is alphanumeric.
int			ft_isalnum(int ch);
//! @brief Checks if the given character is a control character.
int			ft_iscntrl(int ch);
//! @brief Checks if the given character is a space.
int			ft_isspace(int ch);
//! @brief Checks if the given character is a space or a tab.
int			ft_isblank(int ch);
//! @brief Checks if the given character is a punctuation (!"#$%&'()*+,-./:;<=>?
//! @[\]^_`{|}~) character.
int			ft_ispunct(int ch);

//! @brief Checks if the given character has a graphical representation.
int			ft_isgraph(int ch);
//! @brief Checks if the given character can be displayed.
int			ft_isprint(int ch);

//! @brief Checks if the given character is within the ASCII table.
int			ft_isascii(int ch);

//! @brief Converts the character to upper-case if it is a lower-case letter.
int			ft_toupper(int ch);
//! @brief Converts the character to lower-case if it is an upper-case letter.
int			ft_tolower(int ch);

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                                                                          ///
///                    String-Alpha Conversions Functions                    ///
///                                                                          ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

//! @brief Converts the char stream into an integer stored as an int.
int			ft_atoi(const char *str);
//! @brief Converts the char stream into an integer stored as a long.
long		ft_atol(const char *str);
//! @brief Converts the char stream into an integer stored as a long long.
long long	ft_atoll(const char *str);

//! @brief Allocates a null-terminated string containing the base-10 sequence of
//! the digits of n.
char		*ft_itoa(int n);
//! @brief Allocates a null-terminated string containing the base-10 sequence of
//! the digits of n.
char		*ft_lltoa(long long n);
//! @brief Allocates a null-terminated string containing the representation of
//! a number in a given base. If the base contains +, -, several times the same
//! character, or has less than two characters, it is considered invalid and
//! the function returns NULL.
char		*ft_lltoa_base(long long n, const char *base);
//! @brief Allocates a null-terminated string containing the representation of
//! a number in a given base. If the base contains +, -, several times the same
//! character, or has less than two characters, it is considered invalid and
//! the function returns NULL.
char		*ft_ulltoa_base(unsigned long long n, const char *base);

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                                                                          ///
///                           String Copy Functions                          ///
///                                                                          ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

//! @brief Copies the contents of src to dest, including the null terminator.
char		*ft_strcpy(char *dest, const char *src);
//! @brief Copies up to count chars from src to dest, stopping at the null
//! terminator.
char		*ft_strncpy(char *dest, const char *src, size_t count);
/**
 * Copies the null-terminated byte string src in the buffer dest of size size.
 * If there is not enough room for the entirety of src (null terminator
 * included) in dest, stops one byte before size and null-terminates.
 * @brief Copies src into the buffer dest of size size.
 * @param dest A buffer of size size.
 * @param src A null-terminated string.
 * @param size The length of dest in bytes.
 * @return Returns the length of the string that should have been created, equal
 * to the length of src.
 */
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
//! @brief Copies the contents of the null-terminated string src into a newly
//! allocated buffer.
char		*ft_strdup(const char *src);
//! @brief Copies up to count characters from the byte string src into  a newly
//! allocated buffer.
char		*ft_strndup(const char *src, size_t count);

//! @brief Appends src to dest, starting at the null terminator at the end of dest.
char		*ft_strcat(char *dest, const char *src);
//! @brief Appends up to count chars from src to dest, starting at the null
//! terminator at the end of dest.
char		*ft_strncat(char *dest, const char *src, size_t count);
/**
 * Appends the null-terminated byte string src to the end of the null-terminated
 * buffer dest of size size. If there is not enough room for the entirety of src
 * (null terminator included) in dest, stops one byte before size and
 * null-terminates. If dest is not null-terminated within size bytes, returns
 * without doing anything, and dest remains as is.
 * @brief Appends src to the buffer dest of size size.
 * @param dest A null-terminated buffer of size size.
 * @param src A null-terminated string.
 * @param size The length of dest in bytes.
 * @return If there is no null terminator within size bytes in dest, returns
 * size. Otherwise returns the length of the string that should have been
 * created, equal to the combined lengths of dest and src.
 */
size_t		ft_strlcat(char *dest, const char *src, size_t size);

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                                                                          ///
///                       String Exploration Functions                       ///
///                                                                          ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

//! @brief Counts the number of characters until the first null character.
size_t		ft_strlen(const char *str);
//! @brief Counts the number of characters until the first null character,
//! stopping at count characters.
size_t		ft_strnlen(const char *str, size_t count);
//! @brief Returns an integer, the sign of which corresponding to the difference
//! of the characters that differ in the strings.
int			ft_strcmp(const char *lhs, const char *rhs);
//! @brief Returns an integer the sign of which corresponds to the comparison of
//! the first different characters. The exploration stops at count characters.
int			ft_strncmp(const char *lhs, const char *rhs, size_t count);
/**
 * Finds the first occurrence of ch in the given null-terminated string. If the
 * character is not present, returns NULL. Otherwise returns a pointer to the
 * character occurrence in the string.
 * @brief Finds the first occurrence of a character in a string.
 * @param str A null-terminated string of characters.
 * @param ch A character that must be in the range of the ASCII table.
 * @return NULL if the character is not found, otherwise a pointer into str.
 */
char		*ft_strchr(const char *str, int ch);
/**
 * Finds the first occurrence of ch in the given string, stopping at the first
 * null-terminator or after scanning count characters. If the character was not
 * found, returns NULL. Otherwise returns a pointer to the first occurrence in
 * the string.
 * @brief Finds the first occurrence of a character in a sized string.
 * @param str A byte string of characters.
 * @param ch A character to look for.
 * @param count The maximum number of characters to scan.
 * @return NULL if the character is not found, otherwise a pointer into str.
 */
char		*ft_strnchr(const char *str, int ch, size_t count);
/**
 * Finds the last occurrence of ch in the given null-terminated string. If the
 * character is not present, returns NULL. Otherwise returns a pointer to the
 * character occurrence in the string.
 * @brief Finds the last occurrence of a character in a string.
 * @param str A null-terminated string of characters.
 * @param ch A character that must be in the range of the ASCII table.
 * @return NULL if the character is not found, otherwise a pointer into str.
 */
char		*ft_strrchr(const char *str, int ch);

//! @brief Finds the first occurrence of substr in str, and returns the first
//! matching char's address in str, or NULL if nothing was found.
char		*ft_strstr(const char *str, const char *substr);
//! @brief Finds the first occurrence of substr in the first len bytes of str,
//! and returns the first matching char's address in str, or NULL if nothing was
//! found.
char		*ft_strnstr(const char *str, const char *substr, size_t len);

//! @brief Allocates and fills a null-terminated string containing the results
//! of applying the passed function to the characters in str.
char		*ft_strmapi(const char *str, char (*f)(size_t, char));
//! @brief Calls the given function on each of the characters in str.
void		ft_striteri(char *str, void (*f)(size_t, char *));

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                                                                          ///
///                  String Splitting and Joining Functions                  ///
///                                                                          ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

/**
 * Allocates a string of size len. Copies at most len bytes from of str to this
 * new string starting at start. Stops early if a null-terminator is
 * encountered. Behavior is undefined if start and len are such that the read of
 * str overflows.
 * @brief Creates a substring of str of size len, starting at start.
 * @param str A string from which a substring is extracted.
 * @param start The starting index of the substring's contents.
 * @param len The length of the substring.
 * @return NULL if the allocation fails, otherwise a null-terminated string.
 */
char		*ft_substr(const char *str, size_t start, size_t len);
//! @brief Allocates a new string of the combined size of the null-terminated
//! strings s1 and s2, and fills it with their contents. Returns NULL if the
//! allocation fails.
char		*ft_strjoin(const char *s1, const char *s2);
//! @brief Joins count null-terminated strings together into a single
//! null-terminated string. Returns NULL if the allocation fails.
char		*ft_strsnjoin(const char **strs, size_t count);

//! @brief Allocates a copy of str with the characters in set removed from its
//! beginning and its end.
char		*ft_strtrim(const char *str, const char *set);

//! @brief Allocates and fills a null-terminated array of the substring in str
//! delimited by the character c and the edges of str. Returns NULL if the
//! allocation fails.
char		**ft_split(const char *str, char c);

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                                                                          ///
///                     Memory Area Management Functions                     ///
///                                                                          ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

//! @brief Sets the bytes in the buffer b of size len to zero.
void		ft_bzero(void *b, size_t len);
//! @brief Finds the first occurrence of the byte ch in the first count bytes of
//! ptr.
void		*ft_memchr(const void *ptr, int ch, size_t count);
//! @brief Compares the first count bytes in the two buffer, and returns the
//! first non-zero difference.
int			ft_memcmp(const void *lhs, const void *rhs, size_t count);
//! @brief Copies the character ch in the count first unsigned chars in buffer
//! dest.
void		*ft_memset(void *dest, int ch, size_t count);
//! @brief Copies count bytes from buffer src to buffer dest.
void		*ft_memcpy(void *dest, const void *src, size_t count);
//! @brief Copies count bytes from buffer src to buffer dest, which can overlap.
void		*ft_memmove(void *dest, const void *src, size_t count);

//! @brief Allocates memory for num objects of size size and zeros out memory.
void		*ft_calloc(size_t num, size_t size);

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                                                                          ///
///                     File Descriptor Output Functions                     ///
///                                                                          ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

//! @brief Writes a char to a file descriptor.
void		ft_putchar_fd(char c, int fd);
//! @brief Writes a null-terminated string to a file descriptor.
void		ft_putstr_fd(const char *str, int fd);
//! @brief Writes a string of maximum length count to a file descriptor.
void		ft_putstrn_fd(const char *str, size_t count, int fd);
//! @brief Writes a null-terminated str and a newline to a file descriptor.
void		ft_putendl_fd(const char *str, int fd);
//! @brief Writes an integer to a file descriptor.
void		ft_putnbr_fd(int n, int fd);
//! @brief Writes an integer to a file descriptor.
void		ft_putllnbr_fd(long long n, int fd);

////////////////////////////////////////////////////////////////////////////////
///                                                                          ///
///                                                                          ///
///                              The Holy Printf                             ///
///                                                                          ///
///                                                                          ///
////////////////////////////////////////////////////////////////////////////////

/**
 *
 * @param format
 * @param ...
 * @return
 */
int			ft_printf(const char *format, ...);

#endif //LIBFT_H
