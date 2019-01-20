#include "window.h"
#include "draw.h"

int main()
{
	// init draw
	Draw *draw = Draw::get_instance();
	draw->init();
	// setup
	Dialog* dialog = Dialog::get_singleton();
	dialog->init();
	dialog->setup("LMN", 1280, 720);

	// release
	SAFE_FREE(dialog);
	SAFE_FREE(draw);
	return 0;
}