#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
	int	fd;
	int n;
	char	*line;

	if (argc == 1)
	{
		printf("NO ARG! %s\n", argv[0]);
	}
	
	if ((fd = open(argv[1], 0)) == -1)
	{
		printf("Error read\n");
		return 0;
	}
//	fd = 0;
	int j = 0;
	while ((j = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		printf("j = %d\n", j);
		free(line);
		line = NULL;
	}
	printf("%s\n", line);
	printf("j = %d\n", j);
	free(line);
	line = NULL;


	if ((n = close(fd)) == -1)
	{
		printf("Error close file\n");
		return 0;
	}

	printf("end\n");
	read(0, 0, 1);
	return 0;
}
