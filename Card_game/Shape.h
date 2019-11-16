#pragma once
# include <iostream>
# include <vector>
class Shape {
private:
	std::string _name;
	char _shape;
	
	// Unicode for each shape  + Expansin ==> Just add unicod, and string name to this Vector 
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
    char get_shape(); // get unicode of shape ==> for print  
	std::string get_name(); // get SHAPE'S NAME ==> for intener code to distinguish same string or not.
	Shape(); // Make shape : default : Diamond
	Shape(int code); // code refer vector Ex int code 1 => generate shape which have unicode 9830, string DIAMOND  
	Shape(std::string name); 
	Shape(char something, std::string name_); // somthing : unicode, name : the name of shape 
	

	/* UNICODE 
	♦ : 9830
	♥ : 9829;
	♣ : 9827
	♠ : 9824
	◊ : 9674
	© :	169
	
	*/
};