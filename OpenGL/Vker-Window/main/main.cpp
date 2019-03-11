#include "window.h"
#include "draw.h"
#include "log.h"

int main()
{
    Log::get_instance()->error<std::string>("haha");
    Log::get_instance()->log<std::string>("log");
    Log::get_instance()->warn<std::string>("warn");
	// init draw
	Draw *draw = Draw::get_instance();
	draw->init();
	// setup
	Dialog* dialog = Dialog::get_singleton();
	dialog->init();
	dialog->setup("LMN", 1280, 720);
    
	// release
	return 0;
}
