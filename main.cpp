
#include <SDL.h>

#include <vector>
#include <iostream>
#include <cmath>

#include <Application.hpp>


using namespace std;
using namespace Plotbishtu::UI;

vector<Point<double>> getPoints(double step) {
	vector<Point<double>> points = vector<Point<double>>{};
	for (double x = -350.0; x <= 350.0; x = x + step) {
		points.push_back({
			x,
			-(1/(x-10)) * 100
		});
	}

	return points;
}

int main() {

	Plotbishtu::UI::Application app = Plotbishtu::UI::Application("Testing", 800, 600);
	
	bool running = true;
	vector<Point<double>> points = getPoints(0.01);
	while(running) {
		try {
			app.pollEvent();
			app.eventChecks();


			app.drawPoints(points);

		} catch (const Plotbishtu::UI::WindowQuitException& exp) {
			cout << exp.what() << endl;
			running = false;
		}
	}

    return 0;
}