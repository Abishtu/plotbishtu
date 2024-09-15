#include <iostream>
#include <string>

#include <Exceptions/SDLException.hpp>

using namespace std;
using namespace SDL;

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