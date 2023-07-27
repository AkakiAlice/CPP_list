#include "Zombie.hpp"

int	main(void)
{
	std::cout << "Creating zombie with newZombie() function:" << std::endl;
	Zombie*	renan = newZombie("Renan");
	renan->announce();
	std::cout << std::endl;

	std::cout << "Creating zombie with Constructor:" << std::endl;
	Zombie	maurilio = Zombie("Maurilio");
	maurilio.announce();
	std::cout << std::endl;

	std::cout << "Creating zombie with randomChump() function:" << std::endl;
	randomChump("Rogerinho");
	std::cout << std::endl;

	delete renan;
	return (0);
}
