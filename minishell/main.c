#include "minishell.h"
#include <string.h>

t_list *g_env;

char *get_value(char *key)
{
	char *value;
	size_t key_len;
	t_list *tmp;


	tmp = g_env;
	key_len = ft_strlen(key);
	while(tmp)
	{
		if (!ft_strncmp(key, (char*)tmp->content, key_len) &&
		((char*)(tmp->content))[key_len]	== '=')
		{
			value = ft_strdup((char*)tmp->content + key_len + 1);
			return (value);
		}
		tmp = tmp->next;
	}
	return (NULL);
}


char *dollar(char *str, int *i)
{
	int j;
	char *tmp;
	char *key;
	char *value;

	j = *i;
	tmp = ft_substr(str, 0, j);
	while(str[++(*i)] && str[*i] != ' ')
		;
	key = ft_substr(str, j + 1, *i - j - 1);
	value = get_value(key);
	if (!value)
		return NULL;
	tmp = ft_strjoin(tmp, value);
	tmp = ft_strjoin(tmp, str + *i);
	return (tmp);
}

void echo(char **arr)
{
	int size;
	int	i;
	int	n;

	size = 0;
	n = 0;
	while(arr[size])
	{
		size++;
	}
	i = 1;
	while (!ft_strncmp(arr[i], "-n", 3))
	{
		n = 1;
		i++;
	}
	while (arr[i])
	{
		printf("%s", arr[i]);
		if (i != size - 1)
			printf(" ");
		i++;
	}
	if (!n)
		printf("\n");
}

void ft_exit(int status)
{
	exit(status);
}

void error()
{
	ft_exit(1);
}

void cd(char **arr)
{
	int size;

	size = 0;
	while(arr[size])
		size++;
	if (size > 2)
		printf("arguments\n");
	else
	{
		if (chdir(arr[1]))
			printf("error\n");
	}
}
void pwd()
{
	char *str;

	str = malloc(1000);
	if (!str)
		exit(0);
	str = getcwd(str, 1000);
	if (!str)
		exit(0);
	printf("%s\n", str);
}

int valid_symbol(char c)
{
	if ((c >= 'a' && c <= 'z') || (c>= 'A' && c <= 'Z') || c == ' ' || c ==
	'_' || (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

void get_args(char *str, char **key, char **value)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '=')
		{
			*key = ft_substr(str, 0, i - 1);
			*value = ft_strdup(str + i + 1);
			break ;
		}
		i++;
	}
}

int check_key(char *str)
{
	int i;

	i = 1;
	if ((str[0] >= 'A' && str[0] <= 'Z') || (str[0] >= 'a' && str[0] <= 'z')
	|| str[0] == '_')
	{
		while (str[i])
		{
			if (!valid_symbol(str[i]))
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}


int check_str(char *str)
{
	size_t	key_len;
	char *key;
	char *value;
	t_list *tmp;

	key = NULL;
	value = NULL;
	get_args(str, &key, &value);
	if (!key || !value || !check_key(key))
		return (0);
	tmp = g_env;
	while(tmp)
	{
		key_len = ft_strlen(key);
		if (!ft_strncmp((char*)tmp->content, key, key_len) && ((char*)
		tmp->content)[key_len] == '=')
		{
			tmp->content = str;
			return (2);
		}
		tmp = tmp->next;
	}
	return (1);
}

void export(char **arr)
{
	int i;
	int size;

	size = 0;
	while(arr[size])
		size++;
	if (size == 1)
	{
		return ;
	}
	i = 1;
	while(arr[i])
	{
		if (check_str(arr[i]) == 1)
			ft_lstadd_back(&g_env, ft_lstnew(arr[i]));
		i++;
	}
}

void unset(char **arr)
{
	int i;
	size_t len;
	t_list *tmp;
	t_list *tmp1;

	i = 1;
	tmp = g_env;
	while (arr[i])
	{
		if (check_str(arr[i]) && tmp)
		{
			while(tmp->next)
			{
				len = ft_strlen(arr[i]);
				if (!ft_strncmp((char*)tmp->next->content, arr[i], len) && (
						(char*)
						tmp->next->content)[len] == '=')
				{
					tmp1 = tmp->next;
					tmp->next = tmp->next->next;
					free(tmp1->content);
					free(tmp1);
					return ;
				}
				tmp = tmp->next;
			}
		}
		i++;
	}
}

void env()
{
	t_list *tmp;

	tmp = g_env;
	while(tmp)
	{
		printf("%s\n", (char*)tmp->content);
		tmp = tmp->next;
	}
}

int get_cmd_num(const char *str)
{
	int i;
	int count;
	char	c;

	i = 0;
	count = 0;
	while(str[i])
	{
		while(str[i] == ' ')
			i++;
		if (str[i])
			count++;
		if (str[i] == '"' || str[i] == '\'')
		{
			c = str[i];
			while(str[i] != c)
				i++;
			i++;
		}
		else
			while(str[i] != ' ' && str[i] != '\0' && str[i] != '"' && str[i]
			!= '\'')
				i++;
	}
	return count;
}

char *command(char *str, int *i)
{
	char *tmp;
	char c;
	int	j;

	j = *i;
	while(str[*i] && str[*i] != ' ')
	{
		if (str[*i] == '"' || str[*i] == '\'')
		{
			c = str[(*i)++];
			while(str[*i] != c)
				(*i)++;
		}
		(*i)++;
	}
	tmp = ft_substr(str, j, *i - j);
	return (tmp);
}

char *quotes(char *str, int *i)
{
	int		j;
	char	*tmp;
	char	*tmp1;
	char	*tmp2;

	j = *i;
	(*i)++;
	while(str[(*i)] != '\'')
		++(*i);
	tmp = ft_substr(str, 0, j);
	tmp1 = ft_substr(str, j + 1, *i - j - 1);
	tmp2 = ft_strdup(str + *i + 1);
	tmp = ft_strjoin(tmp, tmp1);
	tmp = ft_strjoin(tmp, tmp2);
	free(str);
	return (tmp);
}

char *double_quotes(char *str, int *i)
{
	int j;
	char *tmp;
	char *tmp1;
	char *tmp2;

	j = *i;
	while(str[++(*i)] != '\"')
	{
		if (str[*i] == '$')
			str = dollar(str, i);
	}
	tmp = ft_substr(str, 0, j);
	tmp1 = ft_substr(str, j + 1, *i - j - 1);
	tmp2 = ft_strdup(str + *i + 1);
	tmp = ft_strjoin(tmp, tmp1);
	tmp = ft_strjoin(tmp, tmp2);
	return (tmp);
}

char *slash(char *str, int *i)
{
	char *tmp;

	tmp = ft_substr(str, 0, *i);
	ft_strjoin(tmp, str + *i + 1);
	free(str);
	++(*i);
	return (tmp);
}

void get_command(char **arr)
{
	if (!strncmp(arr[0], "echo", 5))
		echo(arr);
	else if (!strncmp(arr[0], "cd", 3))
		cd(arr);
	else if (!ft_strncmp(arr[0], "pwd", 4))
		pwd();
	else if (!ft_strncmp(arr[0], "export", 7))
		export(arr);
	else if (!ft_strncmp(arr[0], "unset", 6))
		unset(arr);
	else if (!ft_strncmp(arr[0], "env", 4))
		env();
	else if (!ft_strncmp(arr[0], "exit", 5))
		ft_exit(1);
	else
		error();
}

char *parser(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '\"')
			str = double_quotes(str, &i);
		else if (str[i] == '\'')
			str = quotes(str, &i);
		else if (str[i] == '\\')
			str = slash(str, &i);
		else if (str[i] == '$')
			str = dollar(str, &i);
		i++;
	}
	return str;
}

int get_pair(char *str)
{
	char c;

	c = *str;
	while (*(++str))
	{
		if (*str == c)
			return 1;
	}
	return 0;
}

int	check_valid(char *str)
{
	int i;
	char *s;

	i = 0;
	s = str;
	while(*s)
	{
		if (*s == '"' || *s == '\'')
			if (!get_pair(s))
				return (0);
		*s++;
	}
	return 1;
}

char **pre_parser(char *str)
{
	int i;
	int j;
	int size;
	char **arr;

	if (!check_valid(str))
	{
		ft_exit(1);
	}
	size = get_cmd_num(str);
	arr = malloc(sizeof(char*) * (size + 1));
	if (!arr)
		return NULL;
	j = 0;
	i = 0;
	while(str[i])
	{
		while(str[i] == ' ')
			i++;
		arr[j++] = command(str, &i);
	}
	arr[j] = NULL;
	return (arr);
}

t_list *get_new_env(char **env)
{
	t_list *new_env;
	int i;

	new_env = malloc(sizeof(t_list));
	i = 0;
	while(env[i])
	{
		ft_lstadd_back(&new_env, ft_lstnew(env[i]));
		i++;
	}
	return (new_env);
}

int main(int argc, char **argv, char **env)
{
	int i;
	char *str;
	char **commands;

	g_env = get_new_env(env);
	while(1)
	{
		str = readline("> ");
		add_history(str);
		commands = pre_parser(str);
		i = 0;
		while(commands[i])
		{
			commands[i] = parser(commands[i]);
			i++;
		}
		get_command(commands);
	}
}