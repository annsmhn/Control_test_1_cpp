#include "control_w_1_base.h"

int main() {
    setlocale(LC_ALL,"");
    Person person;
    // Установка имени и адреса
    person.setInfo("Иван Иванов", "ул. Ленина, д. 1");
    // Вывод имени и адреса на экран
    person.displayInfo();
    return 0;
}