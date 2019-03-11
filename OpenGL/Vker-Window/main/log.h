#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <string>
#include <Windows.h>



class Log {
private:
	enum ConsoleForegroundColor
	{
		Red = FOREGROUND_INTENSITY | FOREGROUND_RED,
		Green = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
		Blue = FOREGROUND_INTENSITY | FOREGROUND_BLUE,
		Yellow = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
		Purple = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE,
		Cyan = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
		Gray = FOREGROUND_INTENSITY,
		White = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
		HighWhite = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
		Black = 0,
	};
	enum ConsoleBackGroundColor
	{
		b_Red = BACKGROUND_INTENSITY | BACKGROUND_RED,
		b_Green = BACKGROUND_INTENSITY | BACKGROUND_GREEN,
		b_Blue = BACKGROUND_INTENSITY | BACKGROUND_BLUE,
		b_Yellow = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN,
		b_Purple = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE,
		b_Cyan = BACKGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE,
		b_White = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
		b_HighWhite = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
		b_Black = 0,
	};
	static Log* _instance;
	HANDLE _hander;
	void setConsoleColor(ConsoleForegroundColor fc = White, ConsoleBackGroundColor bc = b_Black);
public:
	Log();
	~Log();
	static Log* get_instance();

	template <class T>
	void log(T str);

	template <class T>
	void error(T str);

	template <class T>
	void warn(T str);
};


template <class T>
void Log::log(T str)
{
	std::cout << "Log ==>\n\t" << str << std::endl;
}

template <class T>
void Log::error(T str)
{
	setConsoleColor(Red);
	std::cout << "Error ==>\n\t" << str << std::endl;
	setConsoleColor();
}

template <class T>
void Log::warn(T str)
{
	setConsoleColor(Yellow);
	std::cout << "Warn ==>\n\t" << str << std::endl;
	setConsoleColor();
}
#endif
