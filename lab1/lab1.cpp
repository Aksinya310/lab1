#include <iostream>
#include <fstream>  
#include <string> 
#include <clocale>
#include <limits> // Добавлен этот заголовок

using namespace std;

struct tube {
    string title;
    float length;
    int diameter;
    bool parameter;
};

struct KS {
    string name;
    int kc;
    int kcv;
    float station;
};

int check() {
    int num;
    while (true) {
        cin >> num;
        if (cin.fail() || num <= 0 || cin.peek() != '\n') {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка. Попробуйте снова: ";
        }
        else {
            return num;
        }
    }
}

float checkfloat() {
    float num;
    while (true) {
        cin >> num;
        if (cin.fail() || num < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка. Попробуйте снова: ";
        }
        else {
            return num;
        }
    }
}

tube tube_cin() {
    tube T;
    cout << "название трубы " << endl;
    getline(cin >> ws, T.title);
    cout << "длина" << endl;
    T.length = checkfloat();
    cout << "диаметр" << endl;
    T.diameter = check();
    T.parameter = true;
    return T;
}

KS KS_cin() {
    KS K;
    cout << "название КС " << endl;
    getline(cin >> ws, K.name);
    cout << "количество цехов " << endl;
    K.kc = check();
    cout << "количество цехов в работе " << endl;
    K.kcv = check();
    while (true) {
        if (K.kcv > K.kc) {
            cout << "Количество цехов в работе не может быть больше чем всего цехов" << endl;
            K.kcv = check();
        }
        else {
            break;
        }
    }
    return K; // Добавлен возврат значения
}

// Функции show и show_2 должны быть объявлены вне других функций
void show(const tube& T) {
    cout << "название трубы " << T.title << endl;
    cout << "длина " << T.length << endl;
    cout << "диаметр " << T.diameter << endl; // Исправлена опечатка: diametre -> diameter
    if (T.parameter) {
        cout << "Труба в рабочем состоянии" << endl;
    }
    else {
        cout << "Труба не работает" << endl;
    }
}

void show_2(const KS& K) {
    cout << "название КС " << K.name << endl;
    cout << "количество цехов " << K.kc << endl; // Исправлено: KC -> kc
    cout << "количество цехов в работе " << K.kcv << endl; // Исправлено: KCV -> kcv
}

int main() {
    setlocale(LC_ALL, "RU");
    tube t;
    KS k;
    t = tube_cin();
    k = KS_cin();
    show(t);
    show_2(k);
    return 0;
}