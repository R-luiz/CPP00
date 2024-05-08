
#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (-1);
	}
	for (i = 1; i < ac; i++)
	{
		j = 0;
		std::string str = av[i];
		std::string::iterator it;
		while (str[j])
		{
			std::cout << static_cast<char>(std::toupper(str[j]));
			j++;
		}
	}
	std::cout << std::endl;
	return (0);
}