#pragma once

#include <string>
#include <iostream>

class Data
{
private:
	std::string		_data;
public:
	Data(); // Default constructor
	Data(const Data &src); // Copy constructor
	Data(std::string data);
	~Data(); // Destructor
	Data	&operator=(const Data &src); // Assignment operator

	std::string		getData() const;
};

std::ostream	&operator<<(std::ostream &out, const Data &src); // Output operator
