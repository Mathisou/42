#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int	main()
{
	std::cout << std::endl << "* \033[32mMateriaSource\033[0m --------- *" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << std::endl << "* \033[32mAMateria\033[0m -------------- *" << std::endl;
	AMateria* tmp_ice;
	tmp_ice = src->createMateria("ice");
	AMateria* tmp_cure;
	tmp_cure = src->createMateria("cure");
	// AMateria* tmp3;
	// tmp3 = src->createMateria("cure");
	// AMateria* tmp4;
	// tmp4 = src->createMateria("cure");
	// AMateria* tmp5;
	// tmp5 = src->createMateria("cure");

	std::cout << std::endl << "* \033[32mICharacter\033[0m ------------ *" << std::endl;
	ICharacter* me = new Character("\033[34mjean-luc\033[0m");
	ICharacter* bob = new Character("\033[33mbob\033[0m");
	me->equip(tmp_ice);
	me->equip(tmp_cure);
	// me->equip(tmp3);
	// me->equip(tmp4);
	// me->equip(tmp5);
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << std::endl << "* \033[32mDestructors\033[0m ----------- *" << std::endl;
	delete bob;
	delete me;
	delete src;

	std::cout << std::endl << "* \033[32mAMateria\033[0m ------------- *" << std::endl;
	AMateria *tab = new Ice[4];

	std::cout << std::endl << "* \033[32mCharacter\033[0m ------------- *" << std::endl;
	Character mireille("\033[34mlebackor\033[0m");
	Character matthieu("\033[33mlucie\033[0m");
	mireille.equip(&tab[0]);
	mireille.equip(&tab[1]);
	mireille.equip(&tab[2]);
	mireille.equip(&tab[3]);
	mireille.unequip(0);
	mireille.unequip(1);
	mireille.unequip(2);
	mireille.unequip(3);
	mireille.unequip(0);
	mireille.use(0, matthieu);
	mireille.use(1, matthieu);

	std::cout << std::endl << "* \033[32mDestructors\033[0m ----------- *" << std::endl;
	delete [] tab; // --> TRACE TRAP ERROR
	
	return (0);
}