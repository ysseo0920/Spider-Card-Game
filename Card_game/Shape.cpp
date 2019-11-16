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

Shape::Shape() : Shape::Shape("Diamond") {

}



Shape::Shape(char some, std::string some2) {
	_shape = some;
	_name = some2;
}

Shape::Shape(int i) {

	_shape = unicode.at(i);
	_name = charlist.at(i);

}

Shape::Shape(std::string some) {

	_shape = 'a';
	_name = "aa";

	for (int i = 0; i < some.size(); i++) {
		some[i] = toupper(some[i]); //소문자를 대문자로 교환.
	}
	int flag = 0;
	for (int i = 0; i < charlist.size(); i++) {


		if (some._Equal(charlist.at(i))) {
			_shape = unicode.at(i);
			_name = some;
			flag = 1;
			break;
		};
		
		
	}
	if (flag == 0) {
		delete[] this;
	}

}
