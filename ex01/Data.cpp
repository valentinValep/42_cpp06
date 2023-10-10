#include "Data.hpp"

Data::Data(): _data("default data")
{
	// Default constructor
}

Data::Data(const Data &src)
{
	// Copy constructor
	*this = src;
}

Data::Data(std::string data): _data(data)
{}

Data::~Data()
{
	// Destructor
}

Data	&Data::operator=(const Data &src)
{
	if (this == &src)
		return (*this);
	_data = src._data;
	return (*this);
}

std::string Data::getData() const
{
	return (_data);
}

std::ostream &operator<<(std::ostream &out, const Data &src)
{
	out << src.getData();
	return (out);
}
