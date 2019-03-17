#include "window.h"
#include "draw.h"
#include "main.h"
#include "log.h"

int setup()
{
	// init draw
	Draw *draw = Draw::get_instance();
	draw->init();
	// setup
	Dialog* dialog = Dialog::get_singleton();
	dialog->init();
	dialog->setup("Vker", 1280, 720);
    
	// release
	return 0;
}
