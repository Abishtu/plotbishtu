
#include <iostream>

#include <SDL.h>

#include <vector>

using namespace std;

template<typename T>
struct Point {
    T x;
    T y;
};

int main() {
    bool quit = false;
    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow(
        "SDL2 Test",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640, 480,
        0
    );
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    float scale = 10.0;
    // bool complete = false;
    vector<Point<double>> points = {
        {147.883, (-34.7524)},
		{147.883, (-34.7527)},
		{147.883, (-34.7529)},
		{147.882, (-34.7531)},
		{147.882, (-34.7531)},
		{147.882, (-34.7532)},
		{147.882, (-34.7533)},
		{147.881, (-34.7534)},
		{147.881, (-34.7534)},
		{147.88, (-34.7533)},
		{147.88, (-34.7533)},
		{147.879, (-34.7529)},
		{147.878, (-34.7527)},
		{147.878, (-34.7525)},
		{147.878, (-34.7523)},
		{147.877, (-34.7521)},
		{147.877, (-34.7517)},
		{147.877, (-34.7514)},
		{147.877, (-34.7511)},
        {121.666, -31.1843},
		{121.667, -31.1846},
		{121.667, -31.1847},
		{121.667, -31.1849},
		{121.672, -31.1872},
		{121.673, -31.188},
		{121.674, -31.1881},
		{121.675, -31.1886},
		{121.675, -31.1887},
		{121.676, -31.1889},
		{121.676, -31.1889},
		{121.676, -31.1889},
		{121.676, -31.1889},
		{121.677, -31.1889},
		{121.677, -31.1888},
		{121.677, -31.1886},
		{121.678, -31.1883},
		{121.678, -31.1882},
		{121.679, -31.188},
		{121.679, -31.1878},
		{121.679, -31.1875},
		{121.679, -31.1872},
		{121.679, -31.1869},
		{121.68, -31.1866},
		{121.68, -31.1862},
		{121.68, -31.1859},
		{121.68, -31.1855},
		{121.68, -31.1852},
		{121.679, -31.1849},
		{121.679, -31.1846},
		{121.679, -31.1843},
		{121.679, -31.184},
		{121.678, -31.1838},
		{121.678, -31.1836},
		{121.675, -31.1821},
		{121.671, -31.1803},
		{121.671, -31.1801},
		{121.67, -31.18},
		{121.67, -31.1798},
		{121.669, -31.1797},
		{121.669, -31.1797},
		{121.668, -31.1796},
		{121.668, -31.1796},
		{121.667, -31.1797},
		{121.667, -31.1797},
		{121.667, -31.1798},
		{121.666, -31.18},
		{121.659, -31.1818},
		{121.659, -31.182},
		{121.659, -31.1821},
		{121.658, -31.1822},
		{121.658, -31.1822},
		{121.657, -31.1822},
		{121.655, -31.1823},
		{121.654, -31.1824},
		{121.654, -31.1824},
		{121.653, -31.1823},
		{121.653, -31.1822},
		{121.65, -31.1817},
		{121.649, -31.1814},
		{121.649, -31.1813},
		{121.648, -31.1813},
		{121.648, -31.1813},
		{121.647, -31.1813},
		{121.647, -31.1813},
		{121.647, -31.1814},
		{121.646, -31.1815},
		{121.646, -31.1817},
		{121.645, -31.1819},
		{121.645, -31.1821},
		{121.644, -31.1824},
		{121.644, -31.1826},
		{121.644, -31.1829},
		{121.643, -31.1832},
		{121.643, -31.1836},
		{121.643, -31.184},
		{121.643, -31.1846},
		{121.643, -31.1854},
		{121.643, -31.1858},
		{121.643, -31.1861},
		{121.643, -31.1865},
		{121.642, -31.1868},
		{121.642, -31.1871},
		{121.642, -31.1874},
		{121.642, -31.1876},
		{121.639, -31.1889},
		{121.639, -31.1892},
		{121.638, -31.1894},
		{121.638, -31.1896},
		{121.637, -31.1897},
		{121.636, -31.1897},
		{121.633, -31.1898},
		{121.632, -31.1898},
		{121.631, -31.1898},
		{121.63, -31.1897},
		{121.63, -31.1896},
		{121.629, -31.1893},
		{121.628, -31.189},
		{121.628, -31.1886},
		{121.627, -31.1881},
		{121.627, -31.1876},
		{121.626, -31.1869},
		{121.626, -31.1866},
		{121.625, -31.1865},
		{121.625, -31.1862},
        {145.246, -37.813},
		{145.246, -37.8132},
		{145.244, -37.8136},
		{145.244, -37.8138},
		{145.243, -37.8139},
		{145.243, -37.814},
		{145.242, -37.814},
		{145.242, -37.8141},
		{145.242, -37.8141},
		{145.241, -37.8141},
		{145.241, -37.8142},
		{145.24, -37.8142},
		{145.24, -37.8141},
		{145.239, -37.814},
		{145.238, -37.8139},
		{145.237, -37.8139},
		{145.236, -37.8138},
		{145.235, -37.8138},
		{145.235, -37.8137},
		{145.235, -37.8137},
		{145.235, -37.8138},
		{145.234, -37.8138},
		{145.234, -37.8139},
		{145.234, -37.8139},
		{145.233, -37.8141},
		{145.232, -37.8145},
		{145.232, -37.8146},
    };

    SDL_RenderSetLogicalSize(renderer, 640, 480);

    while(!quit) {
        SDL_PollEvent(&event);

        switch (event.type) {
            case SDL_QUIT:
                quit = true;
                break;
        }

        SDL_SetRenderDrawColor(renderer, 242, 242, 242, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

        for (Point<double> point : points) {
            Point<double> point1 = {(point.x + (640/2))/scale, (point.y + (480/2))/scale};

            cout << (float) point1.x << ", " << point1.y << endl;
            SDL_RenderSetScale(renderer, scale, scale);
            SDL_RenderDrawPointF(renderer, ((float) point1.x), ((float) point1.y));
        }
        // complete = true;
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}