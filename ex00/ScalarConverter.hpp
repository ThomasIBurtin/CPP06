#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>

class ScalarConverter
{
    public:
        static void convert(std::string arg);

	class error : public std::exception
	{
		public:
		const char* what() const throw()
		{
			return("ERROR");
		}
	};
    private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &src);
		~ScalarConverter();
		ScalarConverter &	operator=(ScalarConverter const &rSym);
};

#endif