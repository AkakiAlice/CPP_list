#include "ScavTrap.hpp"
#include <iostream>

int	main(void) {
	ScavTrap	scavtrap1("Rogerinho");
	ScavTrap	scavtrap2("Maurilio");
	std::cout << std::endl;

	scavtrap1.attack(scavtrap2.getName());
	scavtrap2.takeDamage(scavtrap2.getAttackDamage());
	std::cout << scavtrap1.getName() << " energy points: " << scavtrap1.getEnergyPoints() << std::endl;
	std::cout << std::endl;

	scavtrap1.attack(scavtrap2.getName());
	scavtrap2.takeDamage(scavtrap2.getAttackDamage());
	std::cout << scavtrap1.getName() << " energy points: " << scavtrap1.getEnergyPoints() << std::endl;
	std::cout << std::endl;

	scavtrap2.beRepaired(10);
	std::cout << scavtrap2.getName() << " energy points: " << scavtrap2.getEnergyPoints() << std::endl;
	scavtrap2.guardGate();
	std::cout << std::endl;

	return(0);
}
