#include "ClapTrap.hpp"
#include <iostream>

int	main(void) {
	ClapTrap	clapTrap1("Rogerinho");
	ClapTrap	clapTrap2;

	clapTrap2.setName("Maurilio");
	std::cout << std::endl;

	clapTrap1.setAttackDamage(5);
	clapTrap2.setAttackDamage(10);
	std::cout << std::endl;

	clapTrap1.attack(clapTrap2.getName());
	clapTrap2.takeDamage(clapTrap1.getAttackDamage());
	clapTrap2.beRepaired(10);
	std::cout << std::endl;

	clapTrap1.attack(clapTrap2.getName());
	clapTrap2.takeDamage(clapTrap1.getAttackDamage());
	std::cout << std::endl;

	clapTrap1.attack(clapTrap2.getName());
	clapTrap2.takeDamage(clapTrap1.getAttackDamage());
	std::cout << std::endl;

	clapTrap2.attack(clapTrap1.getName());
	clapTrap1.takeDamage(clapTrap2.getAttackDamage());
	std::cout << std::endl;

	return(0);
}
