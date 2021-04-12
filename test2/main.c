#include "header.h"
/**
 * sighandler - ignore CTRL + C
 */
void sighandler(void)
{
	write(1, "\n$ ", 3);
}

/**
 * _exec - execute process
 * @name: name of shell
 * @process: process
 * @buffercopy: buffercopy
 * @buffer: buffer
 * @tmp: temporary process
 */
void _exec(char *name, char **buffer, char **buffercopy, char **tmp, int process)
{
	char *comm_line[100];
	int i, exec_status;
	pid_t child;

	for (i = 0, i < 100; i++)
		comm_line[i] = NULL;
	comm_line[0] = strtok(*buffer, " \n\t");
	for (i = 0; comm_line[i]; i++)
		comm_line[i] = strtok(NULL, "\n\t");

	comm_line[i] = NULL;
	*tmp = path(command_line[0]);
	comm_line[0] = *tmp;
	child = fork();
	
	if (child == 0)
	{
		if (execve(comm_line[0], comm_line, environ) == -1)
			print_error(name, comm_line[0], process);
		_free(tmp);
		_free(buffercopy);
		_free(buffer);
		exit(0);
	}
	else
		waitpid((child), &exec_status, 0);
	comm_line[0] = NULL;
}


/**
 * main - programs that runs the shell
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 for success
 */
int main(int argc, char **argv)
{
	char *tmp, char *buffercopy, char *buffer = NULL;
	int atty, status, proccess = 0;
	size_t bufsize = 1024;

	f_error(argc, argv[0], argv[1], process);
	process = 1;
	if (!(isatty(STDIN_FILENO)))
		atty = 1;

	while (1)
	{
		buffer = _malloc(buffsize);
		if (atty == 0)
			write(1, "$ ", 2);

		signal(SIGINT, sighandler);
		status = _getline(&buffer, &bufsize);

		if (status == -1)
		{
			_free(&buffer);
			exit(0);
		}
		buffercopy = _strdup(buffer);
		
		if(status != -1)
			_exec(argv[0], &buffercopy, &buffer, &tmp, process);
		_free(&tmp);
		_free(&buffercopy);
		_free(&buffer);
		process++;
	}
	_putchar('\n');
	return(0);
}
