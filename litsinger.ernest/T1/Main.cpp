#include<iostream>
#include"BaseTypes.hpp"
#include "Rectangle.hpp"

int main() {
	Rectangle test1(2, 2, base_types::point_t{ 0,0 });
	std::cout << test1.getArea() << " ";
	rectangle_t frameRect1 = test1.getFrameRect();
	std::cout << frameRect1.width << " " << frameRect1.height << " " << frameRect1.pos.x << " " << frameRect1.pos.y;
	test1.move({ -5, 11 });
	test1.move(1, 1);
	test1.scale(10);
	std::cout << "\n";
	return 0;
}