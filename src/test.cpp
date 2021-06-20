#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <ctime>

using namespace std::placeholders;
using namespace std;

template<class T>
class Point
{
public:
    T x;
    T y;

    Point(T x = 0, T y = 0)
    {
        this->x = x;
        this->y = y;
    }
    ~Point() {};

    bool operator < (Point p)
    {
        return (this->x < p.x) and (this->y < p.y);
    }

    bool operator > (Point p)
    {
        return (this->x > p.x) and (this->y > p.y);
    }

    bool operator == (Point p)
    {
        return (this->x == p.x) and (this->y == p.y);
    }
};

struct Cell {
    char image; // изображение пары
    bool isFind; // было ли оно уже найдено
};

class PairsGame {
    int n; // размер поля
    Cell** field; // поле
    string images; // строка с изображениями
public:
    PairsGame(int n, string images); // конструктор игры

    void ShuffleImages(); // перемешивание изображений
    void RestartGame(); // перезапуск игры

    Point<int> ReadPoint(const string& message, Point<int> exclude) const; // считывание координат
};

PairsGame::PairsGame(int n, string images) {
    this->n = n;
    this->images = images;
    this->field = new Cell * [n];

    for (int i = 0; i < n; i++) {
        this->field[i] = new Cell[n];
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

Point<int> PairsGame::ReadPoint(const string& message, Point<int> exclude) const
{
    Point<int> point(0, 0);
    cout << message;
    cin >> point.x >> point.y;

    while (point < Point<int>(1, 1) || point > Point<int>(n, n) || point == exclude) {
        cout << "Invalid coordinate, try again: ";
        cin >> point.x >> point.y;
    }

    return point;
}

bool unitTest(function<Point<int>(const string& message, Point<int> exclude)> func, const string& message, Point<int> exclude, Point<int> expected)
{
    return func(message, exclude) == expected;
}

template <class T>
struct Test
{
    string message;
    Point<T> exclude;
    Point<T> expected;

    Test(string message, Point<T> exclude, Point<T> expected)
    {
        this->message = message;
        this->exclude = exclude;
        this->expected = expected;
    };
};

int main(int argc, char* argv[])
{
    int n = 3; // размер поля
    // cout << "Enter size of field (must be even): ";
    // cin >> n; // считываем размер поля

    string totalImages = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"; // символы для изображения
    string images = totalImages.substr(0, n * n / 2); // получаем часть строки для самих пар
    
    PairsGame game(n, images + images);
    game.RestartGame();

    auto pointer = bind(&PairsGame::ReadPoint, game, _1, _2);

    vector<Test<int>> tests;
    tests.push_back(Test<int>("", Point<int>(1, 1), Point<int>(3, 3)));
    tests.push_back(Test<int>("", Point<int>(2, 2), Point<int>(1, 1)));

    for (Test<int> test : tests)
    {
        cout << unitTest(pointer, test.message, test.exclude, test.expected);
    }

    return EXIT_SUCCESS;
}