#include <string>

using namespace std;

//ячейка
struct Cell {
    /// изображение пары
    char image;
    bool isFind; // было ли оно уже найдено
};

// клетка
struct Point {
    int x;
    int y;
};

class PairsGame {
    int n; ///< размер поля
    Cell **field; // поле
    string images; // строка с изображениями
    
    void ShuffleImages(); // перемешивание изображений
    void RestartGame(); // перезапуск игры
     /**
     * * пометка ячейки
     * \param point точка для отметки
     * \param isFind
     * */
    void MarkCell(Point point, bool isFind = true); //

    void PrintLine() const; // вывод линии
    void PrintTime(int seconds) const; // вывод времени

    /**
     * Считывание координат
     * \param message, откуда считываются координаты
     * \param exclude точка исключения?
     * \return считанную точку
     * */
    Point ReadPoint(const string& message, Point exclude) const;
public:
    PairsGame(int n, string images); // конструктор игры

    void Print(bool ignoreFlags = false) const; // вывод поля
    void Play(); // игра

    ~PairsGame(); // деструктор
};