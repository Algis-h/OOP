#include <iostream>
#include "homework_2.h"



int main(int argc, char const *argv[])
{
	// Task 1

	Person human("Василий", 22, "Муж", 75);
	human.print();
	Student peter("Петр", 25, "Муж", 76, 3);
	peter.print();
	Student ivan("Иван", 19, "Муж", 36, 1);
	ivan.print();

	
	// Task 2

	std::cout << "------------------------------" << "\n";
	
	Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
	return 0;
}