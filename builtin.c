/**
 * builtin - exits the shell
 * constant function prototype.
 * By: ALX
 * Status: Always 0
 * Created: 2023/5/10 12:01:20 by ALX
 * Updated: 2023/5/10 14:26:01 by ALX
 * builtin - prints an input string
 * @cmd: the string to be printed
 * @status: the string to be printed
 */

#include "shell.h"

void builtin(char **cmd, int *status)
{
	if (!ft_strcmp(cmd[0], "exits"))
		exits_sh(cmd, 0);
	else if (!ft_strcmp(cmd[0], "pwd"))
		pwd();
	else if (!ft_strcmp(cmd[0], "echo"))
		echo(cmd);
	else if (!ft_strcmp(cmd[0], "environ"))
		ft_environ(cmd);
	else if (!ft_strcmp(cmd[0], "cd"))
		cd(cmd);
	else if (!ft_strcmp(cmd[0], "export"))
		ft_export(cmd);
	else if (!ft_strcmp(cmd[0], "unset"))
		g_vars.g_env = unset(cmd);
	*status = 0;
}
