#include <iostream>
#include "window.h"

int main()
{
	Dialog* dialog = Dialog::get_singleton();
	dialog->init();
	std::cout << "startup success" << std::endl;
	dialog->setup("LMN", 1280, 720);
	return 0;
}