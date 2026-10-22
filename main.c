#include <unistd.h>

void	ft_puthex_ptr(unsigned long long num)
{
	char	*base;

	base = "0123456789abcdef";
	if (num >= 16)
	{
		ft_puthex_ptr(num / 16);
		ft_puthex_ptr(num % 16);
	}
	else
	{
		write(1, &base[num], 1);
	}
}

int	ft_print_ptr(void *ptr)
{
	unsigned long long	address;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	// On cast le pointeur en entier 'unsigned long long'
	address = (unsigned long long)ptr;
	write(1, "0x", 2);
	ft_puthex_ptr(address);
	
	return (0); 
}

int main(void)
{
    ft_print_ptr("salut");
}