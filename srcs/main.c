#include "../green_code.h"

int	main(int argc, char **argv)
{
	char	*line = NULL;
	int		fd = open(argv[1], O_RDONLY);
	int		fd2;
	int		*counters = NULL;
	FILE	*file1 = fopen("./data/noheaders.c", "w");
	FILE	*file2 = fopen("./data/headers", "a");
	FILE	*file3 = fopen("report.txt", "w");

	if (!argv || fd <= 0)
	{
		printf("File not found\n");
		exit (1);
	}
	if (argc >= 1)
	{
		counters = count(line, fd, file1, file2);
		fprintf(file3, "Total lines: %d\n", counters[0] + 1);
		fprintf(file3, "Total headers: %d\n", counters[1]);
		fprintf(file3, "Total for loops: %d\n", counters[2]);
		fprintf(file3, "Total while loops: %d\n", counters[3]);
		free(counters);
	}
	close(fd);
	fclose(file1);
	fclose(file2);
	fclose(file3);
	return (0);
}
