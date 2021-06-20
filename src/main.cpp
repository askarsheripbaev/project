#include <iostream>
#include <string>
#include "lib.hpp"

using namespace std;

int main() {
    int n; // размер поля
    cout << "Enter size of field (must be even): ";
    cin >> n; // считываем размер поля

    string totalImages = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"; // символы для изображения
    string images = totalImages.substr(0, n * n / 2); // получаем часть строки для самих пар

    PairsGame game(n, images + images); // создаём игру
    game.Play(); // запускаем игру
}