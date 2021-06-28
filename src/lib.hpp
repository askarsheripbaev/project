#include <string>

using namespace std;

/**
 *ячейка
 *\param image изображение пары
 *\param isfind было ли оно уже найдено
**/
struct Cell {
    char image;
    bool isFind;
};

/**
 * клетка
**/
struct Point {
    int x;
    int y;
};
/**
 * пометка ячейки
 *
**/
class PairsGame {
    int n;                ///< размер поля
    Cell **field;         // поле
    string images;        // строка с изображениями
    
    void ShuffleImages(); 
    void RestartGame();   
     /**
     * пометка ячейки
     *\param point точка для отметки
     *\param isFind было ли оно уже найдено
     **/
    void MarkCell(Point point, bool isFind = true);
    
    void PrintLine() const;            // вывод линии
    void PrintTime(int seconds) const; // вывод времени

    /**
     * Считывание координат
     * \param message, откуда считываются координаты
     * \param exclude точка исключения?
     * \return считанную точку
     * */
    Point ReadPoint(const string& message, Point exclude) const;
public:
    PairsGame(int n, string images); 

    void Print(bool ignoreFlags = false) const; // вывод поля
    void Play();                                // игра

    ~PairsGame();                               // деструктор
};