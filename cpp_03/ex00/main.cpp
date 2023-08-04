#include "ClapTrap.hpp"
#include <iostream>

int	main(void) {
	ClapTrap	clapTrap1("claptrap1");
	ClapTrap	clapTrap2;

	clapTrap2.setName("claptrap2");
	std::cout << std::endl;

	clapTrap1.setAttackDamage(1);
	clapTrap2.setAttackDamage(1);
	std::cout << std::endl;

	clapTrap1.attack(clapTrap2.getName());
	clapTrap2.takeDamage(clapTrap1.getAttackDamage());
	clapTrap2.beRepaired(1);
	std::cout << std::endl;

	for (int i = 0; i < 9; i++) {
		clapTrap1.attack(clapTrap2.getName());
		clapTrap2.takeDamage(clapTrap1.getAttackDamage());
		std::cout << std::endl;
	}

	clapTrap1.attack(clapTrap2.getName());
	std::cout << std::endl;

	return(0);
}
