#pragma once
#include <initializer_list>
#include <string>

class LinkedList {
private:
    /**
     * @brief Структура, представляющая узел списка
     */
    struct Node {
        int data;        ///< Данные узла (целое число)
        Node* next;      ///< Указатель на следующий узел
        Node(int value) : data(value), next(nullptr) {} ///< Конструктор узла
    };
    
    Node* head;         ///< Указатель на начало списка
    size_t size;        ///< Размер списка

public:
    /**
     * @brief Конструктор по умолчанию
     * Создает пустой список
     */
    LinkedList();

    /**
     * @brief Конструктор копирования
     * @param other Список, который нужно скопировать
     */
    LinkedList(const LinkedList& other);

    /**
     * @brief Конструктор перемещения
     * @param other Список, ресурсы которого нужно переместить
     */
    LinkedList(LinkedList&& other) noexcept;

    /**
     * @brief Деструктор
     * Освобождает всю память, занятую списком
     */
    ~LinkedList();

    /**
     * @brief Оператор присваивания копированием
     * @param other Список, который нужно скопировать
     * @return Ссылка на текущий список
     */
    LinkedList& operator=(const LinkedList& other);

    /**
     * @brief Оператор присваивания перемещением
     * @param other Список, ресурсы которого нужно переместить
     * @return Ссылка на текущий список
     */
    LinkedList& operator=(LinkedList&& other) noexcept;

    /**
     * @brief Конструктор со списком инициализации
     * @param list Список инициализации с целыми числами
     */
    LinkedList(std::initializer_list<int> list);
    
    /**
     * @brief Оператор вывода в поток
     * @param os Поток вывода
     * @param list Список для вывода
     * @return Ссылка на поток вывода
     */
    friend std::ostream& operator<<(std::ostream& os, const LinkedList& list);

    /**
     * @brief Оператор ввода из потока
     * @param is Поток ввода
     * @param list Список для ввода
     * @return Ссылка на поток ввода
     */
    friend std::istream& operator>>(std::istream& is, LinkedList& list);
    
    /**
     * @brief Проверяет, пуст ли список
     * @return true, если список пуст, false в противном случае
     */
    bool isEmpty() const;

    /**
     * @brief Вставляет элемент в конец списка
     * @param value Значение для вставки
     */
    void insert(int value);

    /**
     * @brief Удаляет элемент по значению
     * @param value Значение элемента для удаления
     * @return true, если элемент был удален, false если элемент не найден
     */
    bool remove(int value);

    /**
     * @brief Ищет элемент по значению
     * @param value Значение для поиска
     * @return true, если элемент найден, false в противном случае
     */
    bool find(int value) const;

    /**
     * @brief Изменяет значение элемента
     * @param oldValue Старое значение элемента
     * @param newValue Новое значение элемента
     * @return true, если элемент был изменен, false если элемент не найден
     */
    bool modify(int oldValue, int newValue);

    /**
     * @brief Преобразует список в строку
     * @return Строковое представление списка
     */
    std::string toString() const;

    /**
     * @brief Возвращает размер списка
     * @return Количество элементов в списке
     */
    size_t getSize() const;
}; 