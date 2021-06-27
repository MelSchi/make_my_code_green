#include "../green_code.h"

int    *count(char *line, int fd, FILE *file1, FILE *file2)
{
	int		read = 0;
	int		read_custom_lib = 0;
	int		headers = 0;
	int		lines = 0;
	int		loopf = 0;
	int		loopw = 0;
	int		*counters = malloc(4); 
	char	*lib_file;
	char	*line_lib_file;
	int		fd_custom_lib;
	char	*path;
	
	while ((read = get_next_line(fd, &line)) > 0)
	{
		if (strstr(line, "for"))
			loopf += read;
		if (strstr(line, "while"))
			loopw += read;
		lines += read;
		if ((strstr(line, "#include <") || strstr(line, "#include\t<")))
		{
			headers += read;
			fprintf(file2, "%s\n", (line + 9));
		}
		else if (strstr(line, "#include \""))
		{
			lib_file = strtok(line, "\"");
			lib_file = strtok(NULL, "\"");
			printf("Please enter the full path of your %s: ", lib_file);
			scanf("%s", path);
			fd_custom_lib = open(path, O_RDONLY);
			if (fd_custom_lib <= 0)
			{
				printf("Linked custom library %s not found\n", lib_file);
				exit (1);
			}
			while ((read_custom_lib = get_next_line(fd_custom_lib, &line_lib_file)) > 0)
			{
				if (strstr(line_lib_file, "include"))
				{
					headers++;
					fprintf(file2, "%s\n", (line_lib_file + 10));
				}
			}
		}
		else
			fprintf(file1, "%s\n", line);
		free(line);
	}
	if (read < 0)
	{
		printf("Error, run again.");
		exit (1);
	}
	if (lines > 0)
		fprintf(file1, "%s\n", line);
	counters[0] = lines;
	counters[1] = headers;
	counters[2] = loopf;
	counters[3] = loopw;
	return (counters);
}
