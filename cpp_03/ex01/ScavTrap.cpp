#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << this->_name << " created with default DERIVED constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << this->_name << " created with parametric DERIVED constructor" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const& src) : ClapTrap(src) {
	*this = src;
	std::cout << this->_name << " created with copy DERIVED constructor" << std::endl;
}

ScavTrap::~ScavTrap(void) {
	std::cout << this->_name << " was destroyed with DERIVED destructor" << std::endl;
}

ScavTrap&	ScavTrap::operator=(ScavTrap const & rhs) {
	if (this != &rhs) {
		this->_attackDamage = rhs._attackDamage;
		this->_energyPoints = rhs._energyPoints;
		this->_hitPoints = rhs._hitPoints;
		this->_name = rhs._name;
	}
	return (*this);
}

void	ScavTrap::guardGate(void) {
	std::cout << this->_name << " is now in Gate keeper mode" << std::endl;
}


