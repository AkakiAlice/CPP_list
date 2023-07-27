#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->_type = type;
	return ;
}

Weapon::~Weapon(void)
{
	return ;
}

void	Weapon::setType(std::string newType)
{
	this->_type = newType;
}

std::string const	Weapon::getType(void)
{
	return (this->_type);
}
