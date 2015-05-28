#include <inputs.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	char *str;

	// start_termcaps();
	str = ft_get_inputs("Shell > ");
	while (*str)
	{
		dprintf(1, "Just printed '%s'\n", str);
		str = ft_get_inputs("Shell > ");
		free(str);
	}
	dprintf(1, "str = '%s'\n", str);
}