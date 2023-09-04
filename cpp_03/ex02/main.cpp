#include "FragTrap.hpp"
#include <iostream>

int	main(void) {
	FragTrap	fragTrap1("Rogerinho");
	FragTrap	fragTrap2("Maurilio");
	std::cout << std::endl;

	fragTrap1.attack(fragTrap2.getName());
	fragTrap2.takeDamage(fragTrap2.getAttackDamage());
	std::cout << fragTrap1.getName() << " energy points: " << fragTrap1.getEnergyPoints() << std::endl;
	std::cout << std::endl;

	fragTrap1.attack(fragTrap2.getName());
	fragTrap2.takeDamage(fragTrap2.getAttackDamage());
	std::cout << fragTrap1.getName() << " energy points: " << fragTrap1.getEnergyPoints() << std::endl;
	std::cout << std::endl;

	fragTrap2.beRepaired(10);
	std::cout << fragTrap2.getName() << " energy points: " << fragTrap2.getEnergyPoints() << std::endl;
	fragTrap2.highFiveGuys();
	std::cout << std::endl;

	return(0);
}
