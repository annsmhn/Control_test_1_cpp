#include "control_w_1_base.h"

int main() {
    setlocale(LC_ALL,"");
    Person person;
    // ��������� ����� � ������
    person.setInfo("���� ������", "��. ������, �. 1");
    // ����� ����� � ������ �� �����
    person.displayInfo();
    return 0;
}