#include <iostream>
#include <string>

using namespace std;

#ifndef _SDLEXCPETIONS_HPP_
#define _SDLEXCEPTIONS_HPP_
namespace SDL {
    class WindowExcpetion : public exception {
        public:
            const string m_msg;

            WindowExcpetion(const string& msg);

            ~WindowExcpetion();

            virtual const char* what() const throw();
    };

    class RendererException : public exception {
        public:
            const string m_msg;

            RendererException(const string& msg);

            ~RendererException();

            virtual const char* what() const throw();
    }
}

#endif