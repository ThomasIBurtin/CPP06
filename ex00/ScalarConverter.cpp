#include "ScalarConverter.hpp"

void charConvert(std::string arg)
{
    std::cout << "char: " << arg << std::endl;
    std::cout << "int: " << static_cast<int>(arg[0]) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(arg[0]) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(arg[0]) << std::endl;
}

void intConvert(std::string arg)
{
    int n = std::stoi(arg);

    if (std::isprint(static_cast<char>(n)) == 0)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(n) << std::endl;
	std::cout << "int: " << n << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(n) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(n) << std::endl;
}

void floatConvert(std::string arg)
{
    float n = std::stof(arg);

    if (std::isprint(static_cast<char>(n)) == 0)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(n) << std::endl;
    std::cout << "int: " << static_cast<int>(n) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << n << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(n) << std::endl;

}

void doubleConvert(std::string arg)
{
    double n = std::stod(arg);

    if (std::isprint(static_cast<char>(n)) == 0)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(n) << std::endl;
    std::cout << "int: " << static_cast<int>(n) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(n) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << n << std::endl;
}

void		minInfConvert() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << INT_MIN << std::endl;
	std::cout << "float: " << __FLT_MIN__ << std::endl;
	std::cout << "double: " << __DBL_MIN__ << std::endl;
}

void		maxInfConvert() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << INT_MAX << std::endl;
	std::cout << "float: " << __FLT_MAX__ << std::endl;
	std::cout << "double: " << __DBL_MAX__ << std::endl;
}

void		nanConvert() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << 0 << std::endl;
	std::cout << "float: " << 0 << std::endl;
	std::cout << "double: " << 0 << std::endl;
}

void ScalarConverter::convert(std::string arg)
{
    if (std::isprint(arg[0]) && !std::isdigit(arg[0]))
    {
		if (arg.length() == 1)
			charConvert(arg);
		else if (arg == "-inf" || arg == "-inff")
			minInfConvert();
		else if (arg == "+inf" || arg == "+inff")
			maxInfConvert();
		else if (arg == "nan" || arg == "nanf")
			nanConvert();
		else
			throw ScalarConverter::error();
	}
	else if (arg[arg.length() - 1] == 'f')
    {
		long unsigned int	i = 0;
		while (i < arg.length() - 1 && (std::isdigit(arg[i]) || arg[i] == '.'))
			i++;
		if (i == arg.length() - 1)
			floatConvert(arg);
		else
			throw ScalarConverter::error();
	}
	else if (arg.find('.') != std::string::npos) {
		long unsigned int	i = 0;
		while (std::isdigit(arg[i]) || arg[i] == '.')
			i++;
		if (i == arg.length())
			doubleConvert(arg);
		else
			throw ScalarConverter::error();
	}
	else if (std::isdigit(arg[0])) {
		long unsigned int	i = 0;
		while (std::isdigit(arg[i]))
			i++;
		if (i == arg.length())
			intConvert(arg);
		else
			throw ScalarConverter::error();
	}
	else
		throw ScalarConverter::error();
}