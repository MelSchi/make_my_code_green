#include <stdio.h>
 #include <stdlib.h>

int	ft_atoi (const char *nptr);

int	main(void)
{
	const char	input[] = "				 -12345ac6789";
	int			res;
	int			res_orig;

	res = ft_atoi(input);
	printf("Before: %s\n", input);
	printf("After: %d\n", res);
	printf("Orig_atoi: %d\n", res_orig);
	if (res == res_orig)
		printf("same!\n");
	return (0);
}
