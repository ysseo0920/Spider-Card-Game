#include"Shape.h"
char Shape::get_shape() {
	return _shape;
}
std::string Shape::get_name()
{
	return _name;
}
void Shape::print_shape() {
	std::cout << _shape;
}
Shape::Shape(char some,std::string some2) {
	_shape = some;
	_name = some2;
}