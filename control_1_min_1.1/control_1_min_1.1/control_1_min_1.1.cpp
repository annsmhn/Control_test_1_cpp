#include <iostream>
#include <windows.h>
#include <thread>

using namespace std;

class MovingPoint {
private:
    int x, y;
    int color;

//функция, которая возвращает дескриптор стандартного выходного потока<=>число, через которое Windows отслеживает, куда выводить информацию
//формально - указатель на окно консоли, но применять к нему типичные для указателей операции нельзя
    HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    void setCursorPosition(int x, int y) {

        //определяет новое положение курсора <=>структура, которая определяет координаты элемента в экранном буфере консоли
        COORD coord;
        coord.X = x;
        coord.Y = y;

        //Функция из Windows API, которая устанавливает позицию курсора в окне консоли
        SetConsoleCursorPosition(hConsoleOutput, coord);
    }
    void setColor(int color) {
        //второй параметр соответсвует изначально закодированному в функцию цвету
        SetConsoleTextAttribute(hConsoleOutput, color);
    }
public:
    // Конструктор по умолчанию
    MovingPoint() : x(0), y(0), color(7) {} // Белый цвет
    // Обычный конструктор
    MovingPoint(int startX, int startY, int clr) : x(startX), y(startY), color(clr) {}

    void moveToBottomRight() {

        //используем структуру для записи информации о состоянии консольного окна
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(hConsoleOutput, &csbi);

        // srWindow хранит координаты видимой области окна
        int width = csbi.srWindow.Right;
        int height = csbi.srWindow.Bottom;
        for (int row = y; row <= height; row++) {
            for (int i = 0; i < width; i++)
            {
                setCursorPosition(x+i, row);
                setColor(color);
                cout << "*";
                this_thread::sleep_for(chrono::milliseconds(10));
                setCursorPosition(x + i, row);
                cout << " ";
                if ((row == height)&&(i== width)) {
                    return;
                }
            }
        }
        setColor(7); // Сброс цвета, иначе весь оставшийся текст в консоли будет в цвете, который задан
    }
};
int main() {

    MovingPoint customPoint(0, 0, 2);
    customPoint.moveToBottomRight();

    return 0;
}