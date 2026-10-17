#ifndef FT_PRINT_H
# define FT_PRINT_H

#include <stdarg.h>
#include <unistd.h>

//printf functions
int		ft_printf(const char *format, ...);
int		ft_checker(va_list ap, char sign);

int		ft_putstr_fd(char *s, int fd);
int		ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *s);
int		ft_putnbr_fd(int n, int fd);
int 	ft_hex(unsigned int  number);

#endif