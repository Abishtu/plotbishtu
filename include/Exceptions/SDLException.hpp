#include <iostream>
#include <string>

using namespace std;

#ifndef _SDLEXCPETIONS_HPP_
#define _SDLEXCEPTIONS_HPP_
namespace Plotbishtu {
    namespace UI {
        class WindowQuitException : public exception {
            public:
                const string m_msg;

                WindowQuitException(const string& msg);

                ~WindowQuitException();

                virtual const char* what() const throw(); 
        };

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
        };
    }

    namespace PreProcessing {
        class InputStreamParseException : public exception {
            public:
                const string m_msg;

                InputStreamParseException(const string& msg);

                ~InputStreamParseException();

                virtual const char* what() const throw();
        };
    }
}

#endif