#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Pipe
{
	string name1;
	double length;
	double diameter;
	bool sign;
};

struct CS
{
	string name2; 
	int number_workshop;
	int in_work;
	double effectiveness;
}; 
template <typename T>
T GetCorrectNumber(T min, T max) {
	int x;
	while ((cin >> x).fail() || cin.peek() != '\n' || x < min || x > max) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "\nДанные введены неверно" << endl;
	}
	return x;
}