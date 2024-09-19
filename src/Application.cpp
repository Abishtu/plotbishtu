#include <Application.hpp>

using namespace std;
using namespace Plotbishtu::UI;

Application::Application(string _name, int _width, int _height) {
    this->setName(_name);
    this->setWidth(_width);
    this->setHeight(_height);

    SDL_Init(SDL_INIT_VIDEO);
    this->window = SDL_CreateWindow(
        this->name.c_str(),
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        this->width, this->height,
        0
    );

    this->renderer = SDL_CreateRenderer(this->window, -1, 0);
    SDL_RenderSetLogicalSize(this->renderer, this->width, this->height);
}

Application::~Application() {
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

int Application::getWidth() {
    return this->width;
}

int Application::getHeight() {
    return this->height;
}

string Application::getName() {
    return this->name;
}

void Application::setWidth(int _width) {
    this->width = _width;
}

void Application::setHeight(int _height) {
    this->height = _height;
}

void Application::setName(string _name) {
    this->name = _name;
}

void Application::pollEvent() {
    SDL_PollEvent(&this->event);
}

void Application::eventChecks() {
    switch(this->event.type) {
        case SDL_QUIT:
            throw WindowQuitException("Good bye");
            break;
    }
}

void Application::drawPoints(vector<Point<double>> points) {
    SDL_SetRenderDrawColor(this->renderer, 242, 242, 242, 255);
    SDL_RenderClear(this->renderer);
    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);

    for (Point<double> point : points) {
        SDL_RenderDrawPointF(this->renderer, (float) point.x, (float) point.y);
    }

    SDL_RenderPresent(this->renderer);
}