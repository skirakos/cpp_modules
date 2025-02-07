#include <iostream>

void print_arg(char *arg)
{
	int		i;

	i = 0;
	while (arg[i])
	{
		arg[i] = toupper(arg[i]);
		std::cout << arg[i];
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		i;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		i = 1;
		while (argv[i])
		{
			print_arg(argv[i]);
			i++;
		}
	}
	return 0;
}