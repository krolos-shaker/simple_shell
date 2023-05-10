/**
 * ft_env - exits the shell
 * char : the string to be printed
 * @args : Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * By: ALX
 * Created: 2023/5/10 15:20:15 by ALX
 * Updated: 2023/5/10 17:21:04 by ALX
 */

#include "shell.h"

void	ft_env(char **args)
{
	t_env	*lst;
	int		ac;

	ac = word_counter(args + 1);
	if (ac == 0)
	{
		lst = g_vars.g_env;
		while (lst)
		{
			printf("%s\n", lst->value);
			lst = lst->next;
		}
		g_vars.status_sign = 0;
	}
	else
	{
		ft_putstr_fd(join_err("Simple_shell: "
		, args[1],  \": No such file or directory\n"), 2);
		g_vars.status_sign = 127;
	}
}
