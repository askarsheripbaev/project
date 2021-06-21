#include <iostream>
#include <string>
#include "lib.hpp"

using namespace std;

  /**
  *\param totalImages символы для изображения
  *\param images получаем часть строки для самих пар
  *
  **/
int main() {
    int n;       //размер поля
    cout << "Enter size of field (must be even): ";
    cin >> n;    //считывает размер поля

    string totalImages = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"; 
    string images = totalImages.substr(0, n * n / 2);

    PairsGame game(n, images + images); // создаём игру
    game.Play(); // запускаем игру
}