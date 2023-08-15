#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) {
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	this->_name = "nameless";
	std::cout << this->_name << " created with default BASE constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name) {
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	this->_name = name;
	std::cout << this->_name << " created with parametric BASE constructor" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src) {
	*this = src;
	std::cout << this->_name << " created with copy BASE constructor" << std::endl;
}

ClapTrap::~ClapTrap(void) {
	std::cout << this->_name << " was destroyed with BASE destructor" << std::endl;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const & rhs) {
	if (this != &rhs) {
		this->_attackDamage = rhs._attackDamage;
		this->_energyPoints = rhs._energyPoints;
		this->_hitPoints = rhs._hitPoints;
		this->_name = rhs._name;
	}
	return (*this);
}

int	ClapTrap::pointsChecker(void) {
	if (this->_hitPoints == 0) {
		std::cout << this->_name << " has no hit points!" << std::endl;
		return (0);
	}
	if (this->_energyPoints == 0) {
		std::cout << this->_name << " has no energy points!" << std::endl;
		return (0);
	}
	return (1);
}

void	ClapTrap::attack(const std::string& target) {
	if (this->pointsChecker()) {
		--this->_energyPoints;
		std::cout << this->_name << " attacks " << target;
		std::cout << ", causing " << this->_attackDamage;
		std::cout << " points of damage!" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->pointsChecker()) {
		this->_hitPoints += amount;
		--this->_energyPoints;
		std::cout << this->_name << " repairs itself ";
		std::cout << "and gets " << amount << " hit points back,";
		std::cout << " now it has " << this->_hitPoints << " hit points!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->pointsChecker()) {
		this->_hitPoints -= amount;
		std::cout << this->_name << " was attacked ";
		std::cout << "and lost " << amount << " hit points,";
		std::cout << " now it has " << this->_hitPoints << " hit points!" << std::endl;
	}
}

void	ClapTrap::setAttackDamage(int attackDamage) {
	std::cout << "Set " << this->_name << "'s attack damage to " << attackDamage << std::endl;
	this->_attackDamage = attackDamage;
}

std::string ClapTrap::getName(void) {
	return (this->_name);
}

int ClapTrap::getAttackDamage(void) {
	return (this->_attackDamage);
}

int ClapTrap::getEnergyPoints(void) {
	return (this->_energyPoints);
}

void ClapTrap::setName(std::string name) {
	std::cout << "Rename " << this->_name << " to " << name << std::endl;
	this->_name = name;
}
