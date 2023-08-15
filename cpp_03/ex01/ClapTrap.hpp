#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {
public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const & src);
	~ClapTrap(void);

	ClapTrap&	operator=(ClapTrap const & rhs);

	void		attack(const std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	void		setAttackDamage(int attackDamage);
	void		setName(std::string name);
	int			pointsChecker(void);
	std::string	getName(void);
	int			getAttackDamage(void);
	int			getEnergyPoints(void);

protected:
	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;
};

#endif
