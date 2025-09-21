#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Pipe
{
	string name;
	double length;
	double diameter;
	bool sign;
};

struct CS
{
	string name; 
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
int menu()
{
	int number;
	while (true)
	{
		cout << "Выберите пункт из меню" << endl;
		cout << "Меню:" << endl;
		cout << "1. Добавить трубу" << endl;
		cout << "2. Добавить КС" << endl;
		cout << "3. Просмотр всех объектов" << endl;
		cout << "4. Редактировать трубу" << endl;
		cout << "5. Редактировать КС" << endl;
		cout << "6. Сохранить" << endl;
		cout << "7. Загрузить" << endl;
		cout << "0. Выход" << endl;
		number = GetCorrectNumber(0, 7);
		cout << "\n";
		break;
	}
	return number;
}
void Add_pipe(Pipe& p)
{
	cout << "Добавление трубы" << endl;
	cout << "Введите название: ";
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	getline(cin, p.name);
	cout << "Введите длину: ";
	p.length = GetCorrectNumber(0.0, DBL_MAX);
	cout << "Введите диаметр: ";
	p.diameter = GetCorrectNumber(0.0, DBL_MAX);
	p.sign = true;
	cout << "\n";
}