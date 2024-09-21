
#include <SDL.h>

#include <vector>
#include <iostream>
#include <cmath>

#include <Application.hpp>


using namespace std;
using namespace Plotbishtu::UI;

int main() {

	Plotbishtu::UI::Application app = Plotbishtu::UI::Application("Testing", 800, 600);
	
	bool running = true;
	vector<Point<double>> points 
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