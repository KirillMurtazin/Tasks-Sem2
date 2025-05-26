#include <gtest/gtest.h>
#include "LinkedList.h"

// Тест конструктора по умолчанию
TEST(LinkedListTest, DefaultConstructor) {
    LinkedList list;
    EXPECT_TRUE(list.isEmpty());
    EXPECT_EQ(list.getSize(), 0);
}

// Тест конструктора со списком инициализации
TEST(LinkedListTest, InitializerListConstructor) {
    LinkedList list = {1, 2, 3, 4, 5};
    EXPECT_FALSE(list.isEmpty());
    EXPECT_EQ(list.getSize(), 5);
    EXPECT_TRUE(list.find(1));
    EXPECT_TRUE(list.find(5));
}

// Тест конструктора копирования
TEST(LinkedListTest, CopyConstructor) {
    LinkedList original = {1, 2, 3};
    LinkedList copy(original);
    
    EXPECT_EQ(copy.getSize(), original.getSize());
    EXPECT_TRUE(copy.find(1));
    EXPECT_TRUE(copy.find(2));
    EXPECT_TRUE(copy.find(3));
}

// Тест конструктора перемещения
TEST(LinkedListTest, MoveConstructor) {
    LinkedList original = {1, 2, 3};
    LinkedList moved(std::move(original));
    
    EXPECT_EQ(moved.getSize(), 3);
    EXPECT_TRUE(moved.find(1));
    EXPECT_TRUE(moved.find(2));
    EXPECT_TRUE(moved.find(3));
    EXPECT_TRUE(original.isEmpty());
}

// Тест оператора присваивания копированием
TEST(LinkedListTest, CopyAssignment) {
    LinkedList original = {1, 2, 3};
    LinkedList copy;
    copy = original;
    
    EXPECT_EQ(copy.getSize(), original.getSize());
    EXPECT_TRUE(copy.find(1));
    EXPECT_TRUE(copy.find(2));
    EXPECT_TRUE(copy.find(3));
}

// Тест оператора присваивания перемещением
TEST(LinkedListTest, MoveAssignment) {
    LinkedList original = {1, 2, 3};
    LinkedList moved;
    moved = std::move(original);
    
    EXPECT_EQ(moved.getSize(), 3);
    EXPECT_TRUE(moved.find(1));
    EXPECT_TRUE(moved.find(2));
    EXPECT_TRUE(moved.find(3));
    EXPECT_TRUE(original.isEmpty());
}

// Тест вставки элементов
TEST(LinkedListTest, Insert) {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    
    EXPECT_EQ(list.getSize(), 3);
    EXPECT_TRUE(list.find(1));
    EXPECT_TRUE(list.find(2));
    EXPECT_TRUE(list.find(3));
}

// Тест удаления элементов
TEST(LinkedListTest, Remove) {
    LinkedList list = {1, 2, 3, 4, 5};
    
    // Удаление первого элемента
    EXPECT_TRUE(list.remove(1));
    EXPECT_EQ(list.getSize(), 4);
    EXPECT_FALSE(list.find(1));
    
    // Удаление последнего элемента
    EXPECT_TRUE(list.remove(5));
    EXPECT_EQ(list.getSize(), 3);
    EXPECT_FALSE(list.find(5));
    
    // Удаление элемента из середины
    EXPECT_TRUE(list.remove(3));
    EXPECT_EQ(list.getSize(), 2);
    EXPECT_FALSE(list.find(3));
    
    // Попытка удаления несуществующего элемента
    EXPECT_FALSE(list.remove(10));
    EXPECT_EQ(list.getSize(), 2);
}

// Тест поиска элементов
TEST(LinkedListTest, Find) {
    LinkedList list = {1, 2, 3, 4, 5};
    
    EXPECT_TRUE(list.find(1));
    EXPECT_TRUE(list.find(3));
    EXPECT_TRUE(list.find(5));
    EXPECT_FALSE(list.find(6));
    EXPECT_FALSE(list.find(0));
}

// Тест модификации элементов
TEST(LinkedListTest, Modify) {
    LinkedList list = {1, 2, 3, 4, 5};
    
    // Модификация существующего элемента
    EXPECT_TRUE(list.modify(3, 30));
    EXPECT_TRUE(list.find(30));
    EXPECT_FALSE(list.find(3));
    
    // Попытка модификации несуществующего элемента
    EXPECT_FALSE(list.modify(10, 100));
    EXPECT_FALSE(list.find(100));
}

// Тест преобразования в строку
TEST(LinkedListTest, ToString) {
    LinkedList list = {1, 2, 3};
    std::string expected = "1 -> 2 -> 3";
    EXPECT_EQ(list.toString(), expected);
}

// Тест на пустой список
TEST(LinkedListTest, IsEmpty) {
    LinkedList list;
    EXPECT_TRUE(list.isEmpty());
    
    list.insert(1);
    EXPECT_FALSE(list.isEmpty());
    
    list.remove(1);
    EXPECT_TRUE(list.isEmpty());
}

// Тест получения размера
TEST(LinkedListTest, GetSize) {
    LinkedList list;
    EXPECT_EQ(list.getSize(), 0);
    
    list.insert(1);
    EXPECT_EQ(list.getSize(), 1);
    
    list.insert(2);
    EXPECT_EQ(list.getSize(), 2);
    
    list.remove(1);
    EXPECT_EQ(list.getSize(), 1);
    
    list.remove(2);
    EXPECT_EQ(list.getSize(), 0);
}