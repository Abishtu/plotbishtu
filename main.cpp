
#include <iostream>

#include <SDL.h>

#include <vector>

#include <Application.hpp>

using namespace std;
using namespace Plotbishtu::UI;

vector<Point<double>> getPoints(double step) {
	vector<Point<double>> points = vector<Point<double>>{};
	for (double x = 0.0; x < 700.0; x = x + step) {
		points.push_back({
			x,
			1/x
		});
	}

	return points;
}

int main() {

	Plotbishtu::UI::Application app = Plotbishtu::UI::Application("Testing", 800, 600);
	app.pollEvent();
	bool running = true;
	vector<Point<double>> points = getPoints(0.01);
	while(running) {
		try {

			app.eventChecks();

			app.drawPoints(points);

		} catch (const Plotbishtu::UI::WindowQuitException& exp) {
			cout << exp.what() << endl;
			running = false;
		}
	}

    return 0;
}