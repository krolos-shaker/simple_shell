/**
 * ft_setandfree - knowledge the value and variable
 * ft_printnotvalid - used to print an error message indicating
 * print_env4export - assuming print_env4export is defined in env_utils.h
 * @void: void can be used as a data type
 * By: ALX
 * Created: 2023/5/11 15:34:08 by ALX
 * Updated: 2023/5/11 23:41:53 by ALX
 * ft_export - created by a specific individual
 */

#include "shell.h"

void	print_env4export(void)
{
	t_env	*lst;
	char	**sorted;

	lst = g_vars.g_env;
	sorted = sortenv(lst);
	while (*sorted)
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(*sorted, 1);
		ft_putstr_fd("\n", 1);
		sorted++;
	}
	return (sorted);
}

void	ft_printnotvalid(char *str)
{
	ft_putstr_fd("minishell: export: `", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
}

void	ft_setandfree(char *variable, char *value)
{
	set_env(variable, value);
	free(variable);
	free(value);
}

void	ft_export(char **args)
{
	int		i;
	int		j;
	char	*variable;
	char	*value;

	i = 1;
	if (!args[1])
		return (print_env4export());
	while (args[i])
	{
		j = 0;
		if (!is_valid(args[i]))
		{
			ft_printnotvalid(args[i++]);
			continue;
		}
		while (args[i][j] && args[i][j] != '=')
			j++;
		variable = ft_substr(args[i], 0, j);
		value = ft_substr(args[i], j + 1, ft_strlen(args[i]) - j);
		if (!variable || !value)
			exit(1);
		ft_setandfree(variable, value);
		i++;
	}
}
