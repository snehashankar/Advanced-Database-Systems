#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<string> split(const string &s, char delim) {
	stringstream ss(s);
	string item;
	vector<string> tokens;
	while (getline(ss, item, delim)) {
		tokens.push_back(item);
	}
	return tokens;
}

int main()
{	
	/* Important: Change these paths as per your need*/
	ifstream in("C:/Sneha/Studies/UCLA/Classes/Q3Spring2018/CS240A/Project/KNN/data/Hill_Valley_without_noise_Training.data");
	ifstream in_test("C:/Sneha/Studies/UCLA/Classes/Q3Spring2018/CS240A/Project/KNN/data/Hill_Valley_without_noise_Testing.data");

	/* Important: Change this path as per your need*/
	ofstream out;
	out.open("C:/Sneha/Studies/UCLA/Classes/Q3Spring2018/CS240A/Project/output.txt");

	std::string line;
	int id = 1;
	stringstream trainLabels;
	while (std::getline(in, line)) {
		std::cout << line << std::endl;
		vector<string> tokens = split(line,',');
		string newLine;
		for (int i = 1; i <= tokens.size(); i++) {
			newLine = "train(" + to_string(id);
			newLine += "," + to_string(i);
			newLine+="," + tokens[i-1] + ")";
			if (i == tokens.size()) {
				trainLabels << "labels(" + to_string(id);
				trainLabels <<"," + tokens[i-1]+")\n";
			}
			else
				out << newLine+"\n";
		}
		id++;
	}

	out << "\n\n";
	out << trainLabels.rdbuf() <<"\n\n";

	stringstream testLabels;
	id = 1;
	while (std::getline(in_test, line)) {
		std::cout << line << std::endl;
		vector<string> tokens = split(line, ',');
		string newLine;
		for (int i = 1; i <= tokens.size(); i++) {
			//newLine = "";
			newLine = "test(" + to_string(id);
			newLine += "," + to_string(i);
			newLine += "," + tokens[i-1] + ")";
			if (i == tokens.size()) {
				testLabels << "test_labels(" + to_string(id);
				testLabels << "," + tokens[i - 1] + ")\n";
			}
			else
				out << newLine + "\n";
		}
		id++;
	}
	out << "\n\n" << testLabels.rdbuf() << "\n\n";

	out.close();
}