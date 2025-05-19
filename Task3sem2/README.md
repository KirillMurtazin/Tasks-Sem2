# Инструкция по настройке тестов

## Установка Google Test

1. Установите vcpkg:
   ```powershell
   git clone https://github.com/Microsoft/vcpkg.git
   cd vcpkg
   .\bootstrap-vcpkg.bat
   ```

2. Установите Google Test:
   ```powershell
   .\vcpkg install gtest:x64-windows
   ```

3. Интегрируйте vcpkg с Visual Studio:
   ```powershell
   .\vcpkg integrate install
   ```

## Настройка проекта в Visual Studio

1. Откройте свойства проекта (Task3sem2)
2. Перейдите в Configuration Properties -> C/C++ -> General
3. Добавьте путь к заголовочным файлам Google Test в Additional Include Directories
4. Перейдите в Configuration Properties -> Linker -> Input
5. Добавьте gtest.lib и gtest_main.lib в Additional Dependencies

## Запуск тестов

1. Соберите проект
2. Запустите tests.cpp 

# Task3sem2

## Сборка с помощью g++

### Основная программа

```sh
g++ main.cpp Point.cpp Segment.cpp -o Task3sem2.exe
```

### Тесты (Google Test должен быть установлен)

```sh
g++ tests.cpp Point.cpp Segment.cpp -o tests.exe -lgtest -lgtest_main -pthread
./tests.exe
```

## Структура проекта
- main.cpp — точка входа, пользовательский интерфейс
- Point.h/.cpp — класс Point
- Segment.h/.cpp — класс Segment
- tests.cpp — юнит-тесты (Google Test) 