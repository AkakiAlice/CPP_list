#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << this->_name << " created with default FRAGTRAP constructor" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << this->_name << " created with parametric FRAGTRAP constructor" << std::endl;
}

FragTrap::FragTrap(FragTrap const& src) : ClapTrap(src) {
	*this = src;
	std::cout << this->_name << " created with copy FRAGTRAP constructor" << std::endl;
}

FragTrap::~FragTrap(void) {
	std::cout << this->_name << " was destroyed with FRAGTRAP destructor" << std::endl;
}

FragTrap&	FragTrap::operator=(FragTrap const & rhs) {
	if (this != &rhs) {
		this->_attackDamage = rhs._attackDamage;
		this->_energyPoints = rhs._energyPoints;
		this->_hitPoints = rhs._hitPoints;
		this->_name = rhs._name;
	}
	return (*this);
}

void	FragTrap::highFiveGuys(void) {
	std::cout << "High five guys! It's " << this->_name << " here" << std::endl;
}
