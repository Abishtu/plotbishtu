#include <SDL.h>
#include <string>
#include <vector>
#include <iostream>

#include <Exceptions/SDLException.hpp>

using namespace std;

#ifndef _WINDOW_HPP_
#define _WINDOW_HPP_



namespace Plotbishtu {
    namespace UI {
        template<typename T>
        struct Point {
            T x;
            T y;
        };

        template<typename Y>
        struct Line {
            Point<Y> start;
            Point<Y> end;
        };

        class Application {
            private:
                SDL_Window *window;
                SDL_Renderer *renderer;
                SDL_Event event;

                int width;
                int height;

                string name;
            public:
                Application(string _name, int _width, int _height);
                ~Application();

                int getWidth();
                int getHeight();
                string getName();

                void setWidth(int _width);
                void setHeight(int _height);
                void setName(string _name);

                void pollEvent();
                void eventChecks();

                void renderingWindowUp();

                void drawPoints(vector<Point<double>> points);
                void drawLines(vector<Line<double>> lines);

                void drawPoint(Point<double> point);
                void drawLine(Line<double> line);

        };

        vector<Point<double>> inputDataConversion(FILE *inputStream);
    }
}

#endif