/**
 * set_env - prints an input string
 * @str: the string to be printed
 * @value: knowledge are highly value
 * error.c
 * By: ALX
 * Created: 2023/5/11 12:00:20 by ALX
 * Updated: 2023/5/11 14:39:04 by ALX
 */

#include "shell.h"

void	set_env(char *str, char *value)
{
	t_env	*lst;
	int		flag;

	lst = g_vars.g_env;
	flag = 0;
	while (lst)
	{
		if (!ft_strcmp(lst->variable, str))
		{
			flag = 1;
			lst->value = ft_strjoin(ft_strjoin(str, "="), value);
			if (!lst->value)
				exit(1);
			return;
		}
		lst = lst->next;
	}
	if (!flag)
		add_to_env(&g_vars.g_env, ft_strdup(str),
			ft_strjoin(ft_strjoin(str, "="), value));
}

int	is_valid(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[j++])
	{
		if (str[j] == '=')
			i++;
	}
	if (ft_isdigit(str[0]) || ft_strchr(str, '-')
		|| ft_strchr(str, '.') || i > 1 || !ft_strcmp("==", str))
		return (0);
	return (1);
}

int	ft_sizeofenv(t_env *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

char	**ft_sort_tab(char **tab)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[j])
		{
			if (ft_strcmp(tab[i], tab[j]) < 0)
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

char	**sortenv(t_env *lst)
{
	int		i;
	char	**tab;
	char	**sorted;

	i = 0;
	tab = malloc(sizeof(char *) * (ft_sizeofenv(lst) + 1));
	add_to_r(tab, &g_vars.rubbish);
	if (!tab)
		exit(1);
	while (lst)
	{
		tab[i] = ft_strdup(lst->value);
		if (!tab[i])
			exit(1);
		i++;
		lst = lst->next;
	}
	tab[i] = NULL;
	sorted = ft_sort_tab(tab);
	return (sorted);
}
