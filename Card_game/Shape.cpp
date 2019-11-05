#include"Shape.h"
#include <iostream>
#include <string>
# include <vector>

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
Shape::Shape(std::string some) {

	for (int i = 0; i < some.size(); i++) {
		some[i] = toupper(some[i]); //소문자를 대문자로 교환.
	}
	for (int i = 0; i < charlist.size; i++) {


		if (some._Equal(charlist.at(i))) {
			Shape(unicode.at(i), some);

		};


	}
}
