#include <iostream>
#include <string>

#include <Exceptions/SDLException.hpp>

using namespace std;
using namespace Plotbishtu::UI;

// Window Quit Exception

WindowQuitException::WindowQuitException(const string& msg) : m_msg(msg) {
    // ....
}

WindowQuitException::~WindowQuitException() {
    // ....
}

const char* WindowQuitException::what() const throw() {
    return m_msg.c_str();
}

// Window Exception

WindowExcpetion::WindowExcpetion(const string& msg) : m_msg(msg) {
    // ....
}

WindowExcpetion::~WindowExcpetion() {
    // ....
}

const char* WindowExcpetion::what() const throw() {
    return m_msg.c_str();
}

// Renderer Exception

RendererException::RendererException(const string& msg) : m_msg(msg) {
    // ....
}

RendererException::~RendererException() {
    // .....
}

const char* RendererException::what() const throw() {
    return m_msg.c_str();
}