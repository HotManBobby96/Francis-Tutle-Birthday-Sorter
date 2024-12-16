#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>

using namespace std;

pair<string, string> splitNameDate(const string& input) {
	size_t lastSpacePos = input.find_last_of(" "); // checking the end of the dealio  to find where it was found at 

	// if a sapce was found it spilts it in 2 
	if (lastSpacePos != string::npos) {
		string name = input.substr(0, lastSpacePos);  // before the last sapce
		string date = input.substr(lastSpacePos + 1); // after the last sapce

		return make_pair(name, date); // pair 
	}

	// If no date is found it returns the name or sum idk
	return make_pair(input, ": No fucking date found dumbass pookie bear"); // spooky halloween error ohhh
}

pair<vector<string>, vector<string>> readFileNames(string filePath, const int& lineCount) {

	string line;

	vector<string> names;
	vector<string> dates;

	ifstream file(filePath);

	if (!file.is_open()) {
		cout << "File Not found or opened" << filePath << endl;
	}

	while (getline(file, line)) {
		
		string name;
		string date;

		pair<string, string> result = splitNameDate(line);

		name = result.first;
		date = result.second;

		names.push_back(name);
		dates.push_back(date);
	}

	return make_pair(names, dates); 
}



int getLines(string filePath) {

	int lineCount = 0;
	string Line;

	ifstream file(filePath);

	if (!file.is_open()) { // ehcing if oen duh
		cout << "File not found or opened" << filePath << endl; // error handeling
		return 0;
	}

	while (getline(file, Line)) {
		lineCount++; // counting the lines
	}

	file.close();

	return lineCount; //return

}



int main() {
		// vars
		string filePath = "C:\\Users\\PCHS_BPA\\Desktop\\fracnsistuttke.txt"; // file path
		int lineCount;

		// functions 
		lineCount = getLines(filePath); // getting the dealio for the szes

		// settign up vectors

		vector<string> names;
		vector<string> dates; // cant use array due to the size being determined by runtime causeing an error 

		pair<vector<string>, vector<string>> result = readFileNames(filePath, lineCount);

		for (int i = 0; i < lineCount; i++) {
			names.push_back(result.first[i]);
			dates.push_back(result.second[i]);
		}

		for (int i = 0; i < lineCount; i++) {
			cout << names[i] << endl;
		}

		for (int i = 0; i < lineCount; i++) {
			cout << dates[i] << endl;
		}

		


		return 0;
	}

// 171 #3
//147 148 2 nd 3 apush assigment go crazyyyy
// had to write down the question numbers for class frfr