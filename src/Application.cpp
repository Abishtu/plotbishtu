#include <Application.hpp>

using namespace std;
using namespace Plotbishtu::UI;

Application::Application(string _name, int _width, int _height)
{
    this->setName(_name);
    this->setWidth(_width);
    this->setHeight(_height);

    SDL_Init(SDL_INIT_VIDEO);
    this->window = SDL_CreateWindow(this->name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->width,
                                    this->height, 0);

    this->renderer = SDL_CreateRenderer(this->window, -1, 0);
    SDL_RenderSetLogicalSize(this->renderer, this->width, this->height);
}

Application::~Application()
{
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
}

int Application::getWidth()
{
    return this->width;
}

int Application::getHeight()
{
    return this->height;
}

string Application::getName()
{
    return this->name;
}

void Application::setWidth(int _width)
{
    this->width = _width;
}

void Application::setHeight(int _height)
{
    this->height = _height;
}

void Application::setName(string _name)
{
    this->name = _name;
}

void Application::pollEvent()
{
    SDL_PollEvent(&this->event);
}

void Application::eventChecks()
{
    switch (this->event.type)
    {
        case SDL_QUIT:
            throw(WindowQuitException("Good bye"));
            break;
    }
}

void Application::drawPoints(vector<Point<double>> points)
{
    SDL_SetRenderDrawColor(this->renderer, 242, 242, 242, 255);
    SDL_RenderClear(this->renderer);
    SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 255);

    vector<SDL_FPoint> sdlPoints = vector<SDL_FPoint>{};

    for (Point<double> point : points) {
        sdlPoints.push_back({
            ((float) point.x + (float)(this->width / 2)),
            ((float) -point.y + (float)(this->height / 2))
        });
    }

    const SDL_FPoint *sdlPs = &sdlPoints[0];

    SDL_RenderDrawPointsF(this->renderer, sdlPs, (int)sdlPoints.size());

    SDL_RenderPresent(this->renderer);
}

vector<Point<double>> Plotbishtu::UI::inputDataConversion(FILE *inputStream) {
    vector< Point<double> > points;

    char *data = (char *) malloc(sizeof(char) * 1024);

    while(fgets(data, 1024, inputStream) != NULL) {
        string dataString = string(data);
        size_t pos = dataString.find(',');
        double x = stod(dataString.substr(0, pos));
        double y = stod(dataString.substr(pos+1, dataString.length()));
        Point<double> point = {
            x, y
        };
        points.push_back(point);
    }

    free(data);

    return points;
}
