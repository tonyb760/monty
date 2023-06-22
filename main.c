#include "monty.h"

/**
* process_instruction - process a single instruction
* @instruction: instruction to process
* @h: pointer to the stack
* @line: current line number
*/
void process_instruction(char *instruction, stack_t **h, unsigned int line)
{
if (strcmp(instruction, "push") == 0)
{
push(h, line);
}
else
{
op_func op = get_op_func(instruction);
if (op)
op(h, line);
else
{
free_dlist(h);
printf("L%d: unknown instruction %s\n", line, instruction);
exit(EXIT_FAILURE);
}
}
}

/**
* process_file - process the file and execute instructions
* @file_path: path of the file to process
*/
void process_file(char *file_path)
{
int fd;
unsigned int line = 1;
ssize_t n_read;
char *buffer, *token;
stack_t *h = NULL;

fd = open(file_path, O_RDONLY);
if (fd == -1)
{
printf("Error: Can't open file %s\n", file_path);
exit(EXIT_FAILURE);
}

buffer = malloc(sizeof(char) * 10000);
if (!buffer)
{
close(fd);
exit(EXIT_FAILURE);
}

n_read = read(fd, buffer, 10000);
if (n_read == -1)
{
free(buffer);
close(fd);
exit(EXIT_FAILURE);
}

token = strtok(buffer, "\n\t\a\r ;:");
while (token != NULL)
{
process_instruction(token, &h, line);

line++;
token = strtok(NULL, "\n\t\a\r ;:");
}

free_dlist(&h);
free(buffer);
close(fd);
}

/**
* main - entry into interpreter
* @argc: argc counter
* @argv: arguments
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
if (argc != 2)
{
printf("USAGE: monty file\n");
exit(EXIT_FAILURE);
}

process_file(argv[1]);

return (0);
}
