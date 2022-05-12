#include "Point.hpp"

int		main()
{
	Point point1(1, 2);
	Point point2(2, 3);
	Point point3(2.5, 3.5);
	Point point4(2, 6);
	Point point5(0, 0);
	Point point6(1.598464, 2.95435);
	Point point7(2, -50.56563);
	Point point8(2.5541, -30.5);
	Point point9(92, -1656561);
	Point point10(-954.32, -70.2658490);

	std::cout << std::endl << "*" << "\033[34m a(1, 1) b(4, 3) c(2, 6) \033[0m-------------------- *" << std::endl;
	Point a(1, 1);
	Point b(4, 3);
	Point c(2, 6);

	std::cout << "point  1: ";
	if (bsp(a, b, c, point1) == true)
		std::cout << "\033[1;32mIN\033[0m" << std::endl;
	else
		std::cout << "\033[1;31mOUT\033[0m" << std::endl;
	std::cout << "point  2: ";
	if (bsp(a, b, c, point2) == true)
		std::cout << "\033[1;32mIN\033[0m" << std::endl;
	else
		std::cout << "\033[1;31mOUT\033[0m" << std::endl;
	std::cout << "point  3: ";
	if (bsp(a, b, c, point3) == true)
		std::cout << "\033[1;32mIN\033[0m" << std::endl;
	else
		std::cout << "\033[1;31mOUT\033[0m" << std::endl;
	std::cout << "point  4: ";
	if (bsp(a, b, c, point4) == true)
		std::cout << "\033[1;32mIN\033[0m" << std::endl;
	else
		std::cout << "\033[1;31mOUT\033[0m" << std::endl;
	std::cout << "point  5: ";
	if (bsp(a, b, c, point5) == true)
		std::cout << "\033[1;32mIN\033[0m" << std::endl;
	else
		std::cout << "\033[1;31mOUT\033[0m" << std::endl;
	std::cout << "point  6: ";
	if (bsp(a, b, c, point6) == true)
		std::cout << "\033[1;32mIN\033[0m" << std::endl;
	else
		std::cout << "\033[1;31mOUT\033[0m" << std::endl;
	std::cout << "point  7: ";
	if (bsp(a, b, c, point7) == true)
		std::cout << "\033[1;32mIN\033[0m" << std::endl;
	else
		std::cout << "\033[1;31mOUT\033[0m" << std::endl;
	std::cout << "point  8: ";
	if (bsp(a, b, c, point8) == true)
		std::cout << "\033[1;32mIN\033[0m" << std::endl;
	else
		std::cout << "\033[1;31mOUT\033[0m" << std::endl;
	std::cout << "point  9: ";
	if (bsp(a, b, c, point9) == true)
		std::cout << "\033[1;32mIN\033[0m" << std::endl;
	else
		std::cout << "\033[1;31mOUT\033[0m" << std::endl;
	std::cout << "point 10: ";
	if (bsp(a, b, c, point10) == true)
		std::cout << "\033[1;32mIN\033[0m" << std::endl;
	else
		std::cout << "\033[1;31mOUT\033[0m" << std::endl;

	std::cout << std::endl << "*" << "\033[34m d(10, 10) e(100, -80) f(-100, -80) \033[0m--------- *" << std::endl;
	Point d(10, 10);
	Point e(100, -80);
	Point f(-100, -80);

	std::cout << "point  1: ";
	if (bsp(d, e, f, point1) == true)
		std::cout << "\033[1;32mIN\033[0m" << std::endl;
	else
		std::cout << "\033[1;31mOUT\033[0m" << std::endl;
	std::cout << "point  2: ";
	if (bsp(d, e, f, point2) == true)
		std::cout << "\033[1;32mIN\033[0m" << std::endl;
	else
		std::cout << "\033[1;31mOUT\033[0m" << std::endl;
	std::cout << "point  3: ";
	if (bsp(d, e, f, point3) == true)
		std::cout << "\033[1;32mIN\033[0m" << std::endl;
	else
		std::cout << "\033[1;31mOUT\033[0m" << std::endl;
	std::cout << "point  4: ";
	if (bsp(d, e, f, point4) == true)
		std::cout << "\033[1;32mIN\033[0m" << std::endl;
	else
		std::cout << "\033[1;31mOUT\033[0m" << std::endl;
	std::cout << "point  5: ";
	if (bsp(d, e, f, point5) == true)
		std::cout << "\033[1;32mIN\033[0m" << std::endl;
	else
		std::cout << "\033[1;31mOUT\033[0m" << std::endl;
	std::cout << "point  6: ";
	if (bsp(d, e, f, point6) == true)
		std::cout << "\033[1;32mIN\033[0m" << std::endl;
	else
		std::cout << "\033[1;31mOUT\033[0m" << std::endl;
	std::cout << "point  7: ";
	if (bsp(d, e, f, point7) == true)
		std::cout << "\033[1;32mIN\033[0m" << std::endl;
	else
		std::cout << "\033[1;31mOUT\033[0m" << std::endl;
	std::cout << "point  8: ";
	if (bsp(d, e, f, point8) == true)
		std::cout << "\033[1;32mIN\033[0m" << std::endl;
	else
		std::cout << "\033[1;31mOUT\033[0m" << std::endl;
	std::cout << "point  9: ";
	if (bsp(d, e, f, point9) == true)
		std::cout << "\033[1;32mIN\033[0m" << std::endl;
	else
		std::cout << "\033[1;31mOUT\033[0m" << std::endl;
	std::cout << "point 10: ";
	if (bsp(d, e, f, point10) == true)
		std::cout << "\033[1;32mIN\033[0m" << std::endl;
	else
		std::cout << "\033[1;31mOUT\033[0m" << std::endl;

	return (0);
}