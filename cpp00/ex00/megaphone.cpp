#include <iostream>
#include <string>

bool	is_all_space(char *str)
{
	while (*str)
	{
		if (!isspace(*str))
			return (0);
		str++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	(void)argc;
	int j, flag = 1;

	for (int i = 1; argv[i]; i++)
	{
		if (is_all_space(argv[i]))
			continue;
		j = 0;
		flag = 0;
		while (isspace(argv[i][j]))
			j++;
		for (; argv[i][j]; j++)
			std::cout << (char)toupper(argv[i][j]);
	}
	if (flag == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return (0);
}
