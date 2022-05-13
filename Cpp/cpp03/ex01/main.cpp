#include "ScavTrap.hpp"

int main(){
	// ScavTrap a;
	ScavTrap b("maroly");

	b.attack("Lebackor");
	b.takeDamage(9);
	b.beRepaired(9);
	b.guardGate();
	b.attack("Lebackor");
	b.attack("Lebackor");
	b.attack("Lebackor");
	b.attack("Lebackor");
	b.attack("Lebackor");
	b.attack("Lebackor");
	b.attack("Lebackor");
	b.attack("Lebackor");
	b.attack("Lebackor");
	b.attack("Lebackor");
	b.takeDamage(101);
	b.attack("Lebackor");
	b.beRepaired(9);
	b.guardGate();
}