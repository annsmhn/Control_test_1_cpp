//#pragma warning(suppress : 4996)
#include <iostream>
#include <conio.h>

//gotoxy() не определена
//putwchar версия с расширенными символами
#include <windows.h>

using namespace std;

class Point {
    int x, y;
public:
    Point(int a = 0, int b = 0) { x = a; y = b; }
    int getX(){ return x; }
    int getY(){ return y; }
};
class Rect {
    Point lt, rb; // lt - левая верхняя, rb - правая нижняя
    HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    void Draw_Horizontal_Line(int a, int b, int a1) {
        COORD pos;
        pos.X = a;
        pos.Y = b;
        for (int i = a + 1; i < a1; i++)
        {
            pos.X = i;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
            putwchar(196);
        }
    };
    void Draw_Vertical_Line(int a, int b, int b1) {
        COORD pos;
        pos.X = a;
        pos.Y = b;
        for (int i = b + 1; i < b1; i++)
        {
            pos.Y = i;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
            putwchar(179);
        }
    };
public:
    Rect(Point a, Point b) : lt(a), rb(b) {}
    void Draw() {
        COORD left_top, right_bottom, right_top, left_bottom;
        left_top.X = lt.getX();
        left_top.Y = lt.getY();
        right_bottom.X = rb.getX();
        right_bottom.Y = rb.getY();
        right_top.X = rb.getX();
        right_top.Y = lt.getY();
        left_bottom.X = lt.getX();
        left_bottom.Y = rb.getY();
        SetConsoleCursorPosition(hConsoleOutput, left_top);
        putwchar(218); // верхний левый угол
        SetConsoleCursorPosition(hConsoleOutput, right_top);
        putwchar(191); // верхний правый угол
        SetConsoleCursorPosition(hConsoleOutput, left_bottom);
        putwchar(192); // нижний левый угол
        Draw_Horizontal_Line(left_top.X, left_top.Y, right_top.X);
        Draw_Vertical_Line(left_top.X, left_top.Y, right_bottom.Y);
        Draw_Vertical_Line(right_top.X, right_top.Y, right_bottom.Y);
        Draw_Horizontal_Line(left_bottom.X, left_bottom.Y, right_bottom.X);
        SetConsoleCursorPosition(hConsoleOutput, right_bottom);
        putwchar(217); // нижний правый угол
    }
 };

// Пример main:
int main() {
    Point p;
    Rect r(Point(1, 5), Point(32, 15));
    r.Draw();
    return 0;
}