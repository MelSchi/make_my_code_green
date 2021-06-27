#ifndef GREEN_CODE_H
# define GREEN_CODE_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# define BUFFER_SIZE 32

int			get_next_line(int fd, char **line);
int			*count(char *line, int fd, FILE *file1, FILE *file2);

#endif