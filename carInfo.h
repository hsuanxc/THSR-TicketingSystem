#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>

using std::cout; using std::cerr;
using std::endl; using std::string;
using namespace std;
using std::ifstream; using std::ostringstream;
using std::istringstream;

/*put element into array*/
template <typename S>
ostream& operator<<(ostream& os,
	const vector<S>& vector)
{
	for (auto element : vector) {
		os << "" << element << "";
	}
	return os;
}

/*read the file*/
string readFileIntoString(const string& path) {
	auto ss = ostringstream{};
	ifstream input_file(path);
	if (!input_file.is_open()) {
		cerr << "Could not open the file - '"
			<< path << "'" << endl;
		exit(EXIT_FAILURE);
	}
	ss << input_file.rdbuf();
	return ss.str();
}

string** load_carInfo()
{
	string filename("car.csv");
	string file_contents;
	string delimiter = ",";
	string** car = NULL;
	car = new string*[195];
	for (int i = 0;i < 195;i++) car[i] = new string[14];
	file_contents = readFileIntoString(filename);
	istringstream sstream(file_contents);
	std::vector<string> items;
	string record;
	int counter = 0;
	int i = -1, j = 0;
	while (std::getline(sstream, record)) {
		std::string token;
		size_t pos = 0;
		i++;
		j = 0;
		while ((pos = record.find(delimiter)) != std::string::npos) {
			token = record.substr(0, pos);
			car[i][j] = token;
			j++;
			record.erase(0, pos + delimiter.length());
		}
	}
	return car;
	delete[] car;
}

string** load_Std_priceInfo()
{
	string** price = NULL;
	price = new string*[14];
	for (int i = 0;i < 14;i++) price[i] = new string[14];
	string filename("stdprice.csv");
	string file_contents;
	string delimiter = ",";
	file_contents = readFileIntoString(filename);
	istringstream sstream(file_contents);
	std::vector<string> items;
	string record;
	int counter = 0;
	int i = -1, j = 0;
	while (std::getline(sstream, record)) {
		std::string token;
		size_t pos = 0;
		i++;
		j = 0;
		while ((pos = record.find(delimiter)) != std::string::npos) {
			token = record.substr(0, pos);
			price[i][j] = token;
			j++;
			record.erase(0, pos + delimiter.length());
		}
	}
	return price;
	delete[] price;
}

string** load_Bis_priceInfo()
{
	string** price = NULL;
	price = new string*[14];
	for (int i = 0;i < 14;i++) price[i] = new string[14];
	string filename("bisprice.csv");
	string file_contents;
	string delimiter = ",";
	file_contents = readFileIntoString(filename);
	istringstream sstream(file_contents);
	std::vector<string> items;
	string record;
	int counter = 0;
	int i = -1, j = 0;
	while (std::getline(sstream, record)) {
		std::string token;
		size_t pos = 0;
		i++;
		j = 0;
		while ((pos = record.find(delimiter)) != std::string::npos) {
			token = record.substr(0, pos);
			price[i][j] = token;
			j++;
			record.erase(0, pos + delimiter.length());
		}
	}
	return price;
	delete[] price;
}

string** load_Free_priceInfo()
{
	string** price = NULL;
	price = new string*[14];
	for (int i = 0;i < 14;i++) price[i] = new string[14];

	string filename("freeprice.csv");
	string file_contents;
	string delimiter = ",";
	file_contents = readFileIntoString(filename);
	istringstream sstream(file_contents);
	std::vector<string> items;
	string record;

	int counter = 0;
	int i = -1, j = 0;
	while (std::getline(sstream, record)) {
		std::string token;
		size_t pos = 0;
		i++;
		j = 0;
		while ((pos = record.find(delimiter)) != std::string::npos) {
			token = record.substr(0, pos);
			price[i][j] = token;
			j++;
			record.erase(0, pos + delimiter.length());
		}
	}
	return price;
	delete[] price;
}