#include <stdarg.h>
#include <stdio.h>

int			test2(va_list *ap)
{
	int		d;

	d = va_arg(*ap, int);
	printf("%d", d);
	return (0);
}

int			test(va_list ap)
{
	test2(&ap);
	return (0);
}

int			fake(char *str, ...)
{
	
	va_list ap;

	va_start(ap, str);
	test(ap);
	return (0);
}

int			main(void)
{
	char str[21] = "john le relou";

	fake(str, 12345);
	return (0);
}
