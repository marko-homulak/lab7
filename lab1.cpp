#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <list>
#include <Windows.h>

using namespace std;

// Функція для фарбування тексту в колір
void SetColor(int bg, int text)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}

// Структура, яка містить інформацію про продукт
struct Product {
    string name;    // Назва продукту
    int count;      // Кількість продукту на складі
};

// Список асортименту
list<Product> inventory;

// Список замовлень
map<string, int> orders;

// Додавання нового продукту до асортименту
void addProduct(string name, int count) {
    Product product;
    product.name = name;
    product.count = count;
    inventory.push_back(product);
}

// Пошук продукту за назвою у списку асортименту
list<Product>::iterator findProduct(string name) {
    for (auto it = inventory.begin(); it != inventory.end(); it++) {
        if (it->name == name) {
            return it;
        }
    }
    return inventory.end();
}

// Обробка замовлення
void processOrder(string name, int count) {
    // Пошук продукту за назвою
    auto it = findProduct(name);
    if (it == inventory.end()) {
        // Якщо продукту немає на складі, відхиляємо замовлення
        SetColor(0, 4); cout << "Продукт "; SetColor(0, 6); cout << name; SetColor(0, 4); cout << " недоступний на складі" << endl << endl; SetColor(0, 7);
    }
    else if (it->count < count) {
        // Якщо на складі недостатньо продукту, відхиляємо замовлення
        SetColor(0, 4); cout << "Недостатня кількість продукту "; SetColor(0, 6); cout << name; SetColor(0, 4); cout << " на складі" << endl << endl; SetColor(0, 7);
    }
    else {
        // Якщо продукт доступний та є на складі, обробляємо замовлення
        it->count -= count;
        orders[name] += count;
        SetColor(0, 3); cout << "Замовлення на "; SetColor(0, 2); cout << count; SetColor(0, 3); cout << " од. продукту "; SetColor(0, 2); cout << name; SetColor(0, 3); cout << " виконано" << endl << endl; SetColor(0, 7);
    }
}

// Виведення стану складу та замовлень
void showStatus() {
    SetColor(0, 3); cout << "Залишок на складі:" << endl; SetColor(0, 7);
    SetColor(0, 3); cout << "---------------------------------" << endl; SetColor(0, 7);
    SetColor(0, 3); cout << "- "; SetColor(0, 6); cout << left << setw(18) << "Продукт"; SetColor(0, 3); cout << "| "; SetColor(0, 6); cout << "Кількість "; SetColor(0, 3); cout << "|" << endl; SetColor(0, 7);
    SetColor(0, 3); cout << "---------------------------------" << endl; SetColor(0, 7);
    for (auto it = inventory.begin(); it != inventory.end(); it++) {
        SetColor(0, 3); cout << "- "; SetColor(0, 6); cout << left << setw(18) << it->name; SetColor(0, 3); cout << "| "; SetColor(0, 2); cout << left << setw(10) << it->count; SetColor(0, 3); cout << "|" << endl; SetColor(0, 7);
    }
    SetColor(0, 3); cout << "---------------------------------" << endl << endl; SetColor(0, 7);
    SetColor(0, 3); cout << "Замовлення:" << endl; SetColor(0, 7);
    SetColor(0, 3); cout << "---------------------------------" << endl; SetColor(0, 7);
    SetColor(0, 3); cout << "- "; SetColor(0, 6); cout << left << setw(18) << "Продукт"; SetColor(0, 3); cout << "| "; SetColor(0, 6); cout << "Кількість "; SetColor(0, 3); cout << "|" << endl; SetColor(0, 7);
    SetColor(0, 3); cout << "---------------------------------" << endl; SetColor(0, 7);
    for (auto it = orders.begin(); it != orders.end(); it++) {
        SetColor(0, 3); cout << "- "; SetColor(0, 6); cout << left << setw(18) << it->first; SetColor(0, 3); cout << "| "; SetColor(0, 2); cout << left << setw(10) << it->second; SetColor(0, 3); cout << "|" << endl; SetColor(0, 7);
    }
    SetColor(0, 3); cout << "---------------------------------" << endl; SetColor(0, 7);
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Додавання продуктів до асортименту
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

    SetColor(0, 3); cout << "Введіть продукт для замовлення >> ";
    SetColor(0, 6); cin >> name;
    SetColor(0, 3); cout << "Введіть кількість >> ";
    SetColor(0, 6); cin >> count;

    SetColor(0, 7); cout << endl;

    processOrder(name, count);
    showStatus();

}
