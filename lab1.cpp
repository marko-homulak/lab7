#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <list>
#include <Windows.h>

using namespace std;

// ������� ��� ���������� ������ � ����
void SetColor(int bg, int text)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}

// ���������, ��� ������ ���������� ��� �������
struct Product {
    string name;    // ����� ��������
    int count;      // ʳ������ �������� �� �����
};

// ������ �����������
list<Product> inventory;

// ������ ���������
map<string, int> orders;

// ��������� ������ �������� �� �����������
void addProduct(string name, int count) {
    Product product;
    product.name = name;
    product.count = count;
    inventory.push_back(product);
}

// ����� �������� �� ������ � ������ �����������
list<Product>::iterator findProduct(string name) {
    for (auto it = inventory.begin(); it != inventory.end(); it++) {
        if (it->name == name) {
            return it;
        }
    }
    return inventory.end();
}

// ������� ����������
void processOrder(string name, int count) {
    // ����� �������� �� ������
    auto it = findProduct(name);
    if (it == inventory.end()) {
        // ���� �������� ���� �� �����, ��������� ����������
        SetColor(0, 4); cout << "������� "; SetColor(0, 6); cout << name; SetColor(0, 4); cout << " ����������� �� �����" << endl << endl; SetColor(0, 7);
    }
    else if (it->count < count) {
        // ���� �� ����� ����������� ��������, ��������� ����������
        SetColor(0, 4); cout << "���������� ������� �������� "; SetColor(0, 6); cout << name; SetColor(0, 4); cout << " �� �����" << endl << endl; SetColor(0, 7);
    }
    else {
        // ���� ������� ��������� �� � �� �����, ���������� ����������
        it->count -= count;
        orders[name] += count;
        SetColor(0, 3); cout << "���������� �� "; SetColor(0, 2); cout << count; SetColor(0, 3); cout << " ��. �������� "; SetColor(0, 2); cout << name; SetColor(0, 3); cout << " ��������" << endl << endl; SetColor(0, 7);
    }
}

// ��������� ����� ������ �� ���������
void showStatus() {
    SetColor(0, 3); cout << "������� �� �����:" << endl; SetColor(0, 7);
    SetColor(0, 3); cout << "---------------------------------" << endl; SetColor(0, 7);
    SetColor(0, 3); cout << "- "; SetColor(0, 6); cout << left << setw(18) << "�������"; SetColor(0, 3); cout << "| "; SetColor(0, 6); cout << "ʳ������ "; SetColor(0, 3); cout << "|" << endl; SetColor(0, 7);
    SetColor(0, 3); cout << "---------------------------------" << endl; SetColor(0, 7);
    for (auto it = inventory.begin(); it != inventory.end(); it++) {
        SetColor(0, 3); cout << "- "; SetColor(0, 6); cout << left << setw(18) << it->name; SetColor(0, 3); cout << "| "; SetColor(0, 2); cout << left << setw(10) << it->count; SetColor(0, 3); cout << "|" << endl; SetColor(0, 7);
    }
    SetColor(0, 3); cout << "---------------------------------" << endl << endl; SetColor(0, 7);
    SetColor(0, 3); cout << "����������:" << endl; SetColor(0, 7);
    SetColor(0, 3); cout << "---------------------------------" << endl; SetColor(0, 7);
    SetColor(0, 3); cout << "- "; SetColor(0, 6); cout << left << setw(18) << "�������"; SetColor(0, 3); cout << "| "; SetColor(0, 6); cout << "ʳ������ "; SetColor(0, 3); cout << "|" << endl; SetColor(0, 7);
    SetColor(0, 3); cout << "---------------------------------" << endl; SetColor(0, 7);
    for (auto it = orders.begin(); it != orders.end(); it++) {
        SetColor(0, 3); cout << "- "; SetColor(0, 6); cout << left << setw(18) << it->first; SetColor(0, 3); cout << "| "; SetColor(0, 2); cout << left << setw(10) << it->second; SetColor(0, 3); cout << "|" << endl; SetColor(0, 7);
    }
    SetColor(0, 3); cout << "---------------------------------" << endl; SetColor(0, 7);
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // ��������� �������� �� �����������
    addProduct("iPhone_14_Pro_Max", 6);
    addProduct("iPhone_14_Pro", 10);
    addProduct("iPhone_14_Plus", 0);
    addProduct("iPhone_14", 5);
    addProduct("iPhone_SE_3nd", 16);
    addProduct("iPhone_13_Pro_Max", 1);
    addProduct("iPhone_13_Pro", 0);
    addProduct("iPhone_13_mini", 2);
    addProduct("iPhone_13", 7);
    addProduct("iPhone_12_Pro_Max", 0);
    addProduct("iPhone_12_Pro", 6);
    addProduct("iPhone_12_mini", 1);
    addProduct("iPhone_12", 0);
    addProduct("iPhone_11_Pro_Max", 12);
    addProduct("iPhone_11_Pro", 8);
    addProduct("iPhone_11", 1);
    addProduct("iPhone_SE_2nd", 3);
    addProduct("iPhone_XS_Max", 0);
    addProduct("iPhone_XS", 0);
    addProduct("iPhone_XR", 2);
    addProduct("iPhone_X", 5);
    addProduct("iPhone_8_Plus", 10);
    addProduct("iPhone_8", 0);
    addProduct("iPhone_7_Plus", 0);
    addProduct("iPhone_7", 4);
    addProduct("iPhone_6s_Plus", 1);
    addProduct("iPhone_6s", 0);
    addProduct("iPhone_6_Plus", 0);
    addProduct("iPhone_6", 0);
    addProduct("iPhone_SE_1st", 0);
    // -----------------------------------

    string name;
    int count;

    SetColor(0, 3); cout << "������ ������� ��� ���������� >> ";
    SetColor(0, 6); cin >> name;
    SetColor(0, 3); cout << "������ ������� >> ";
    SetColor(0, 6); cin >> count;

    SetColor(0, 7); cout << endl;

    processOrder(name, count);
    showStatus();

}
