#include "Zombie.hpp"

int	main(void)
{
	int	N = 10;
	Zombie*	zombies = zombieHorde(N, "zombie");

	for (int i = 0; i < N; i++)
		zombies[i].announce();
	std::cout << std::endl;
	delete [] zombies;
	return (0);
}
