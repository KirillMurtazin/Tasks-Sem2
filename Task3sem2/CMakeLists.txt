# Минимальная требуемая версия CMake
cmake_minimum_required(VERSION 3.10)

# Название проекта
project(Task3sem2)

# Установка стандарта C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Определение макроса для экспорта библиотеки
# Этот макрос используется в geometry_defines.h
add_definitions(-DGEOMETRY_LIB_EXPORTS)

# Создание статической библиотеки для классов Point и Segment
add_library(geometry_lib STATIC
    Point.cpp
    Point.h
    Segment.cpp
    Segment.h
    geometry_defines.h
)

# Создание динамической библиотеки для тестов
# Использует Google Test Framework
add_library(test_lib SHARED
    tests.cpp
)

# Создание исполняемого файла с примером использования
add_executable(main_app main.cpp)

# Настройка линковки библиотек
# main_app использует geometry_lib
target_link_libraries(main_app PRIVATE geometry_lib)
# test_lib использует geometry_lib
target_link_libraries(test_lib PRIVATE geometry_lib)

# Добавление директорий с заголовочными файлами
# Публичные директории доступны всем зависимым проектам
target_include_directories(geometry_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(test_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(main_app PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}) 