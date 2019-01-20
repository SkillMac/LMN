#include "log.h"

std::string Console_Color::RESET = "\033[0m";
std::string Console_Color::BLACK = "\033[30m"; /* Black */
std::string Console_Color::RED = "\033[31m"; /* Red */
std::string Console_Color::GREEN = "\033[32m"; /* Green */
std::string Console_Color::YELLOW = "\033[33m"; /* Yellow */
std::string Console_Color::BLUE = "\033[34m"; /* Blue */
std::string Console_Color::MAGENTA = "\033[35m"; /* Magenta */
std::string Console_Color::CYAN = "\033[36m"; /* Cyan */
std::string Console_Color::WHITE = "\033[37m"; /* White */
std::string Console_Color::BOLDBLACK = "\033[1m\033[30m"; /* Bold Black */
std::string Console_Color::BOLDRED = "\033[1m\033[31m"; /* Bold Red */
std::string Console_Color::BOLDGREEN = "\033[1m\033[32m"; /* Bold Green */
std::string Console_Color::BOLDYELLOW = "\033[1m\033[33m"; /* Bold Yellow */
std::string Console_Color::BOLDBLUE = "\033[1m\033[34m"; /* Bold Blue */
std::string Console_Color::BOLDMAGENTA = "\033[1m\033[35m"; /* Bold Magenta */
std::string Console_Color::BOLDCYAN = "\033[1m\033[36m"; /* Bold Cyan */
std::string Console_Color::BOLDWHITE = "\033[1m\033[37m"; /* Bold White */

template <class T>
void Log::log(T str) {
    std::cout << "Log ==>" << str << std::endl;
}
template <class T>
void Log::error(T str) {
    std::cout << Console_Color::RED << "Error ==>" << str << Console_Color::RESET << std::endl;
}
template <class T>
void Log::warn(T str) {
    std::cout << Console_Color::YELLOW << "Warn ==>" << str << Console_Color::RESET << std::endl;
}