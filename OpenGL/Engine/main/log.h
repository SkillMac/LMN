#pragma once

#include <iostream>
#include <string>

#ifdef WINDOWS
#include <Windows.h>
#endif

class Log {
private:
#ifdef WINDOWS
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
    HANDLE _hander;
	void setConsoleColor(ConsoleForegroundColor fc = White, ConsoleBackGroundColor bc = b_Black);
#elif defined __linux__
    struct Color
    {
        std::string RESET = "\033[0m";
        std::string BLACK = "\033[30m"; /* Black */
        std::string RED = "\033[31m"; /* Red */
        std::string GREEN ="\033[32m"; /* Green */
        std::string YELLOW ="\033[33m"; /* Yellow */
        std::string BLUE ="\033[34m"; /* Blue */
        std::string MAGENTA ="\033[35m"; /* Magenta */
        std::string CYAN ="\033[36m"; /* Cyan */
        std::string WHITE ="\033[37m"; /* White */
        std::string BOLDBLACK ="\033[1m\033[30m"; /* Bold Black */
        std::string BOLDRED ="\033[1m\033[31m"; /* Bold Red */
        std::string BOLDGREEN ="\033[1m\033[32m"; /* Bold Green */
        std::string BOLDYELLOW ="\033[1m\033[33m"; /* Bold Yellow */
        std::string BOLDBLUE ="\033[1m\033[34m"; /* Bold Blue */
        std::string BOLDMAGENTA ="\033[1m\033[35m"; /* Bold Magenta */
        std::string BOLDCYAN ="\033[1m\033[36m"; /* Bold Cyan */
        std::string BOLDWHITE ="\033[1m\033[37m"; /* Bold White */
    }color;
#endif
	static Log* _instance;
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
#ifdef WINDOWS
	setConsoleColor(Red);
	std::cout << "Error ==>\n\t" << str << std::endl;
	setConsoleColor();
#elif defined __linux__
    std::cout << color.RED << "Error ==>\n\t" << str << color.RESET << std::endl;
#endif
}

template <class T>
void Log::warn(T str)
{
#ifdef WINDOWS
	setConsoleColor(Yellow);
	std::cout << "Warn ==>\n\t" << str << std::endl;
	setConsoleColor();
#elif defined __linux__
    std::cout << color.YELLOW << "Warn ==>\n\t" << str << color.RESET << std::endl;
#endif
}
