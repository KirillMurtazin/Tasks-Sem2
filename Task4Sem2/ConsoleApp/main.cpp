#include <iostream>
#include "LinkedList.h"

int main() {
    // Создаем список с помощью списка инициализации
    LinkedList list = {1, 2, 3, 4, 5};
    std::cout << "Начальный список: " << list << std::endl;

    // Проверяем, пуст ли список
    std::cout << "Список пуст? " << (list.isEmpty() ? "Да" : "Нет") << std::endl;

    // Добавляем новый элемент
    list.insert(6);
    std::cout << "После добавления 6: " << list << std::endl;

    // Ищем элемент
    int searchValue = 3;
    std::cout << "Есть ли " << searchValue << " в списке? " 
              << (list.find(searchValue) ? "Да" : "Нет") << std::endl;

    // Изменяем значение элемента
    int oldValue = 3;
    int newValue = 30;
    if (list.modify(oldValue, newValue)) {
        std::cout << "Изменено значение " << oldValue << " на " << newValue << std::endl;
        std::cout << "Список после изменения: " << list << std::endl;
    }

    // Удаляем элемент
    int removeValue = 2;
    if (list.remove(removeValue)) {
        std::cout << "Удален элемент " << removeValue << std::endl;
        std::cout << "Список после удаления: " << list << std::endl;
    }

    // Демонстрация конструктора копирования
    LinkedList list2 = list;
    std::cout << "Скопированный список: " << list2 << std::endl;

    // Демонстрация конструктора перемещения
    LinkedList list3 = std::move(list2);
    std::cout << "Перемещенный список: " << list3 << std::endl;
    std::cout << "Исходный список после перемещения: " << list2 << std::endl;

    return 0;
} 