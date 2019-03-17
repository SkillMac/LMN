#include "log.h"

Log* Log::_instance = NULL;

Log* Log::get_instance()
{
	if (_instance == NULL) {
		_instance = new Log();
	}
	return _instance;
}

#ifdef WINDOWS
void Log::setConsoleColor(Log::ConsoleForegroundColor fc, Log::ConsoleBackGroundColor bc)
{
	SetConsoleTextAttribute(_hander, fc | bc);
}
#endif

Log::Log()
{
#ifdef WINDOWS
	_hander = GetStdHandle(STD_OUTPUT_HANDLE);
#endif
}

Log::~Log()
{
	if (_instance)
	{
		delete(_instance);
		_instance = NULL;
	}
}


