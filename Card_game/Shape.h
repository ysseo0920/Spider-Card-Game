#pragma once
#include<iostream>
#include <string>
# include <vector>
class Shape {
private:
	std::string _name;
	char _shape;
	std::vector <int> unicode = {
		9830, 9827, 9829, 9823
	};
   std::vector <std::string> charlist{
		std::string("DIAMOND"),
		std::string("CLOVER"),
		std::string("HEART"),
		std::string("SPADE")
	};
	
public:
  char get_shape();
	std::string get_name();
	void print_shape();
	Shape(int code);
	Shape(std::string something);
	Shape(char something, std::string name_); 
	

	/* UNICODE 
	♦ : 9830
	♥ : 9829;
	♣ : 9827
	♠ : 9824
	◊ : 9674
	© :	169
	
	*/
};