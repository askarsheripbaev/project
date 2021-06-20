#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

// конструктор игры
PairsGame::PairsGame(int n, string images) {
    this->n = n;
    this->images = images;
    this->field = new Cell*[n]; // выделяем память под поле

    for (int i = 0; i < n; i++) {
        this->field[i] = new Cell[n]; // выделяем память под элементы
    }
}

// перемешиваний "изображений"
void PairsGame::ShuffleImages() {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % i;

        // меняем символы местами
        char tmp = images[i];
        images[i] = images[j];
        images[j] = tmp; 
    }
}

// перезапуск игры
void PairsGame::RestartGame() {
    ShuffleImages(); // перемешиваем изображения

    for (int i = 0; i < n; i++) {
        field[i] = new Cell[n]; // выделяем память под элементы

        for (int j = 0; j < n; j++) {
            field[i][j].image = images[i * n + j];
            field[i][j].isFind = false;
        }
    }
}

// вывод линии
void PairsGame::PrintLine() const {
    cout << "+";

    for (int i = 0; i < n; i++)
        cout << "---+";

    cout << endl;
}

// вывод времени
void PairsGame::PrintTime(int time) const {
    int hours = time / 3600; // часы
    int minutes = (time / 60) % 60; // минуты
    int seconds = time % 60; // секунды

    cout << "Ellapsed time: ";
    cout << setfill('0') << hours << ":" << setw(2) << minutes << ":" << setw(2) << seconds << setfill(' ') << endl;
}

// вывод поля
void PairsGame::Print(bool ignoreFlags) const {
    PrintLine();

    for (int i = 0; i < n; i++) {
        cout << "|";

        for (int j = 0; j < n; j++) {
            if (ignoreFlags || field[i][j].isFind) {
                cout << " " << field[i][j].image << " |"; // выводим элементы матрицы
            }
            else {
                cout << " ?" << " |"; // выводим элементы матрицы
            }
        }

        cout << endl; // переходим на новую строку
        PrintLine(); // выводим линию
    }
}

// считывание координат
Point PairsGame::ReadPoint(const string& message, Point exclude) const {
    Point point;
    cout << message;
    cin >> point.x >> point.y; // считываем координаты

    while (point.x < 1 || point.y < 1 || point.x > n || point.y > n || field[point.y - 1][point.x - 1].isFind || (point.x == exclude.x && point.y == exclude.y)) {
        cout << "Invalid coordinate, try again: ";
        cin >> point.x >> point.y; // считываем координаты заново
    }

    return point; // возвраащем координаты
}

// пометка ячейки
void PairsGame::MarkCell(Point point, bool isFind) {
    field[point.y - 1][point.x - 1].isFind = isFind;
}

// игра
void PairsGame::Play() {
    RestartGame(); // перезапускаем игру
    cout << "Remeber pairs!" << endl;
    Print(true); // выводим карточки
    system("pause"); // задерживаем экран

    int findCount = 0; // количество найденных пар
    int totalPairs = n*n / 2; // общее количество пар

    clock_t t0 = clock(); // начинаем замер времени

    while (findCount < totalPairs) {
        system("cls"); // очищаем экран
        Print(); // выводим поле

        Point p1 = ReadPoint("Enter coordinate of first cell: ", { 0, 0 }); // считываем координаты первой клетки
        Point p2 = ReadPoint("Enter coordinate of second cell: ", p1); // считываем координаты второй клетки

        // помечаем карточки как разгаданные
        MarkCell(p1);
        MarkCell(p2);

        if (field[p1.y - 1][p1.x - 1].image == field[p2.y - 1][p2.x - 1].image) {
            findCount++; // увеличиваем количество найденных пар
            continue;
        }
        
        system("cls"); // очищаем экран
        Print(); // выводим поле
        system("pause"); // делаем паузу

        // снимаем пометку на карточках
        MarkCell(p1, false);
        MarkCell(p2, false);
    }

    clock_t t1 = clock(); // завершаем замер времени
    PrintTime((t1 - t0) / CLOCKS_PER_SEC); // выводим затраченное время
}

// деструктор
PairsGame::~PairsGame() {
    for (int i = 0; i < n; i++)
        delete[] field[i];

    delete[] field;
}