#include <iostream>
#include <sstream>
#include <cerrno>
#include <cstdlib>

int parser(char *argv) {
	std::string arg(argv);
	if ((arg == "-inff") || (arg == "+inff") || (arg == "nanf"))
		return (3);
	if ((arg == "-inf") || (arg == "+inf") || (arg == "nan"))
		return (3);
	if (!argv[1] && std::isprint(argv[0]) && !std::isdigit(argv[0]))
		return (1);
	int i = 0;
	if (argv[0] == '-') 
		i++;
	while (isdigit(argv[i]))
		i++;
	if (!argv[i])
		return (2);
	if (argv[i] == '.')
		i++;
	else 
		return (0);
	while (isdigit(argv[i]))
		i++;
	if (!argv[i])
		return (4);
	else if (argv[i] == 'f')
		return (4);
	return (0);
}

void if_char(char to_out) {
	std::cout << "char: '" << to_out << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(to_out) << std::endl;
	std::cout << "float: " << static_cast<int>(to_out) << ".0f";
	std::cout << std::endl;
	std::cout << "double: " << static_cast<int>(to_out) << ".0";
	std::cout << std::endl;
}

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "wrong numbers of arguments!" << std::endl;
		return (0);
	}
	int parsing = parser(argv[1]);
	if (!parsing) {
		std::cout << "wrong argument!" << std::endl;
		return (0);
	}
	if (parsing == 1)
		if_char(argv[1][0]);
	else if (parsing == 3) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		double result = strtod(argv[1], NULL);
		float res = static_cast<float>(result);
		std::cout << "float: " << res << "f" << std::endl;
		std::cout << "double: " << result << std::endl;
	}
	else {
		double result = strtod(argv[1], NULL);
		if (errno == ERANGE) {
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return (0);
		}
		int res = static_cast<int>(result);
		if (((result > 0) && (res < 0)) || ((result < 0) && (res > 0))
			|| (result < static_cast<double>(-2147483648))) {
			res = 0;
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
		}
		else {
			if (isascii(res)) {
				if (isprint(res))
					std::cout << "char: " << static_cast<char>(res) << std::endl;
				else 
					std::cout << "char: Non displayable" << std::endl; 
			}
			else
				std::cout << "char: impossible" << std::endl;
			std::cout << "int: " << res << std::endl;
		}
		float r = static_cast<float>(result); {
			float rest = 0;
			if (res)
				rest = r - res;
			if (rest || (r == static_cast<float>(strtod("+INF", NULL)))
				|| (r == static_cast<float>(strtod("-INF", NULL)))
				|| (r == static_cast<float>(strtod("NAN", NULL))))
				std::cout << "float: " << r << "f" << std::endl; 
			else
				std::cout << "float: " << r << ".0f" << std::endl; 
		}
		double rest = 0;
		if (res)
			rest = result - res;
		if (rest || (result == (strtod("+INF", NULL))) || (result == (strtod("+INF", NULL)))
			|| (result == (strtod("+INF", NULL))))
			std::cout << "double: " << result << std::endl;
		else
			std::cout << "double: " << result << ".0" << std::endl;
	}
	return (0);
}