#ifndef LOG_H
#define LOG_H

#include <iostream>

static struct Console_Color {
    typedef std::string str;
    static str RESET;
    static str BLACK;
    static str RED;
    static str GREEN;
    static str YELLOW;
    static str BLUE;
    static str MAGENTA;
    static str CYAN;
    static str WHITE;
    static str BOLDBLACK;
    static str BOLDRED;
    static str BOLDGREEN;
    static str BOLDYELLOW;
    static str BOLDBLUE;
    static str BOLDMAGENTA;
    static str BOLDCYAN;
    static str BOLDWHITE;
};

class Log {
public:
    template <class T>
    static void log(T t);
    template <class T>
    static void error(T t);
    template <class T>
    static void warn(T t);
};

#endif