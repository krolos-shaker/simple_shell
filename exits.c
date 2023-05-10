/**
 * word_counter - select the words you want to count.
 * @args: the argument string
 * Return: the concatenated string
 * By: ALX
 * exit: exit the shell
 * Created: 2023/5/10 18:16:36 by ALX
 * exit_error - print an error message to the standard.
 *exit_sh - command defined in a specific program.
 */

#include "shell.h"

int	word_counter(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

int	exit_error(char *input)
{
	printf("exit\n");
	ft_putstr_fd(join_err("bash: exit: "
	, input, \": numeric argument required\n"), 2);
	return (EXIT_ERROR);
}

int	exit_sh(char **args, int i)
{
	i = word_counter((args + 1));
	if (i == 0)
	{
		ft_putstr_fd("exit\n", 2);
		exit(EXIT_SUCCESS);
	}
	if (i >= 1)
	{
		if (!ft_str_isnum(args[1]))
			exit(exit_error(args[1]));
		else if (i == 1)
		{
			printf("exit\n");
			exit(ft_atoi(args[1]));
		}
		else
		{
			printf("exit\n");
			ft_putstr_fd(join_err("bash: exit: "
			\, NULL, "too many arguments\n"), 2);
			exit(EXIT_ERROR);
		}
	}
	return (0);
}
