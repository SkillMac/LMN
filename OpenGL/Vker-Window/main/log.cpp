#include "log.h"

Log* Log::_instance = NULL;

Log* Log::get_instance()
{
	if (_instance == NULL) {
		_instance = new Log();
	}
	return _instance;
}

void Log::setConsoleColor(Log::ConsoleForegroundColor fc, Log::ConsoleBackGroundColor bc)
{
	SetConsoleTextAttribute(_hander, fc | bc);
}

Log::Log()
{
	_hander = GetStdHandle(STD_OUTPUT_HANDLE);
}

Log::~Log()
{
	if (_instance)
	{
		delete(_instance);
		_instance = NULL;
	}
}


