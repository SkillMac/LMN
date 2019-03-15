#include "window.h"
#include "draw.h"
#include "log.h"

int main()
{
    Log::get_instance()->error<std::string>("error test");
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
