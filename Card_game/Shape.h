#pragma once
#include<iostream>
#include<string>
class Shape {
private:
	std::string _name;
	char _shape;
public:
  char get_shape();
	std::string get_name();
	void print_shape();
	Shape(char something, std::string name_);
};