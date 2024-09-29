
#include <SDL.h>

#include <vector>
#include <iostream>
#include <cmath>

#include <Application.hpp>


using namespace std;
using namespace Plotbishtu::UI;

vector<string> split_helper(vector<string> result, string str, string delimeter) {
	size_t pos = str.find(delimeter);
	if (pos == string::npos) {
		result.push_back(str);
		return result;
	}

	result.push_back(str.substr(0, pos));
	
	return split_helper(result, str.substr(pos+1, str.length()), delimeter);
}

vector<string> split(string str, string delimeter) {
	return split_helper(vector<string>{}, str, delimeter);
}


int main() {

	Plotbishtu::UI::Application app = Plotbishtu::UI::Application("Testing", 800, 600);
	
	bool running = true;
	string input;
	vector<Point<double>> points = {};
	vector<Line<double>> lines = {};
	while(running) {
		try {
			app.pollEvent();
			app.eventChecks();
			app.renderingWindowUp();
			cout << "[" << "λ" << "]" << " ";
			getline(cin, input);
			
			if (points.size() > 0) {
				app.drawPoints(points);
				points.clear();
			}

			if (!input.empty()) {
				if (input == "exit") {
					throw(Plotbishtu::UI::WindowQuitException("Good Bye!"));
				}
				vector<string> commandParam = split(input, ":");
				if (commandParam[0] == "point") {
					vector<string> pointStrings = split(commandParam[1], ",");
					Point<double> point = {
						std::stod(pointStrings[0]),
						std::stod(pointStrings[1])
					};

					std::cout << point.x << ", " << point.y << endl;
					points.push_back(point);

					app.drawPoints(points);
				}

				if (commandParam[0] == "line") {
					vector<string> lineStrings = split(commandParam[1], ";");
					vector<string> point1String = split(lineStrings[0], ",");
					vector<string> point2String = split(lineStrings[1], ",");

					Point<double> point1 = {
						std::stod(point1String[0]),
						std::stod(point1String[1])
					};

					Point<double> point2 = {
						std::stod(point2String[0]),
						std::stod(point2String[1])
					};

					std::cout << point1.x << ", " << point1.y << " ; " << point2.x << point2.y << endl;
					Line<double> line = {
						point1,
						point2
					}; 
					lines.push_back(line);
					
					app.drawLines(lines);

					// for (Line<double> line : lines) {
					// 	app.drawLine(line);
					// }
				}
			}

		} catch (const Plotbishtu::UI::WindowQuitException& exp) {
			cout << exp.what() << endl;
			app.~Application();
			points.clear();
			running = false;
		}
	}

    return 0;
}
