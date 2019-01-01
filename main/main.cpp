#include "window.h"

int main()
{
	Dialog* dialog = Dialog::get_singleton();
	dialog->init();
	dialog->setup("LMN", 1280, 720);
	return 0;
}