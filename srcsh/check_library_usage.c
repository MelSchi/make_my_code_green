#include "../green_code.h"

int	main()
{
	char	*hline = NULL;
	char	*rline = NULL;
	int		fdh = open("./data/headers", O_RDONLY);
	int		fdr;
	int		found = 0;
	int		nounused = 0;
	FILE	*file2 = fopen("report.txt", "a");

	if ( fdr < 0 || fdh < 0 || !file2)
	{
		printf("Error opening the file");
		exit (1);
	}
	while (get_next_line(fdh, &hline) > 0)
	{
		fdr = open("./data/results.txt", O_RDONLY);
		while (get_next_line(fdr, &rline) > 0)
		{
			if (strstr(rline, hline))
				found = 1;
		}
		close (fdr);
		if (found == 0)
		{
			fprintf(file2, "Library %s is unused\n", hline);
			nounused = 1;
		}
		found = 0;
	}
	if (nounused == 0)
		fprintf(file2, "No unused library\n");

	close(fdh);
	fclose(file2);
}
