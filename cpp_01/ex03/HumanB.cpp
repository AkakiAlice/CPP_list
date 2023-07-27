#include "HumanB.hpp"

HumanB::HumanB(std::string name):_name(name), _weapon(NULL)
{
	return ;
}

HumanB::~HumanB(void)
{
	return ;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack(void)
{
	std::cout << this->_name << " attacks with their ";
	if (this->_weapon != NULL)
		std::cout << this->_weapon->getType();
	else
		std::cout << "own hands";
	std::cout << std::endl;
}
