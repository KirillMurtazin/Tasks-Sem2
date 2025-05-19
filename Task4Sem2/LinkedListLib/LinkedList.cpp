#include "LinkedList.h"
#include <iostream>
#include <sstream>

// Конструктор по умолчанию
LinkedList::LinkedList() : head(nullptr), size(0) {}

// Конструктор копирования
LinkedList::LinkedList(const LinkedList& other) : head(nullptr), size(0) {
    // Копируем все элементы из другого списка
    Node* current = other.head;
    while (current != nullptr) {
        insert(current->data);
        current = current->next;
    }
}

// Конструктор перемещения
LinkedList::LinkedList(LinkedList&& other) noexcept : head(other.head), size(other.size) {
    // Перехватываем ресурсы другого списка
    other.head = nullptr;
    other.size = 0;
}

// Конструктор со списком инициализации
LinkedList::LinkedList(std::initializer_list<int> list) : head(nullptr), size(0) {
    // Добавляем все элементы из списка инициализации
    for (int value : list) {
        insert(value);
    }
}

// Деструктор
LinkedList::~LinkedList() {
    // Освобождаем всю память, занятую списком
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    size = 0;
}

// Оператор присваивания перемещением
LinkedList& LinkedList::operator=(const LinkedList&& other) {
     if (this != &other) {  // Проверка на самоприсваивание
        delete head;  // Освобождаем текущие ресурсы
        head = other.head;  // Перехватываем ресурсы
        size = other.size;
    return *this;
}

// Оператор присваивания копированием
LinkedList& LinkedList::operator=(LinkedList& other) noexcept {
       if (this != &other) {  // Проверка на самоприсваивание
        LinkedList temp(other);  // Создаем временную копию
        std::swap(head, temp.head);  // Обмениваем указатели
        std::swap(size, temp.size);  // Обмениваем размеры
    }
    return *this;
}

// Оператор вывода
std::ostream& operator<<(std::ostream& os, const LinkedList& list) {
    os << list.toString();
    return os;
}

// Оператор ввода
std::istream& operator>>(std::istream& is, LinkedList& list) {
    int value;
    while (is >> value) {
        list.insert(value);
    }
    return is;
}

// Проверка на пустой список
bool LinkedList::isEmpty() const {
    return head == nullptr;
}

// Вставка элемента в конец списка
void LinkedList::insert(int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    size++;
}

// Удаление элемента по значению
bool LinkedList::remove(int value) {
    if (head == nullptr) {
        return false;
    }

    // Если удаляем первый элемент
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
        return true;
    }

    // Ищем элемент для удаления
    Node* current = head;
    while (current->next != nullptr) {
        if (current->next->data == value) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            size--;
            return true;
        }
        current = current->next;
    }
    return false;
}

// Поиск элемента по значению
bool LinkedList::find(int value) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Изменение значения элемента
bool LinkedList::modify(int oldValue, int newValue) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == oldValue) {
            current->data = newValue;
            return true;
        }
        current = current->next;
    }
    return false;
}

// Преобразование списка в строку
std::string LinkedList::toString() const {
    std::stringstream ss;
    Node* current = head;
    while (current != nullptr) {
        ss << current->data;
        if (current->next != nullptr) {
            ss << " -> ";
        }
        current = current->next;
    }
    return ss.str();
}

// Получение размера списка
size_t LinkedList::getSize() const {
    return size;
} 