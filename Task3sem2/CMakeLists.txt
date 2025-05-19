cmake_minimum_required(VERSION 3.10)
project(Task3sem2)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Определение макроса для экспорта библиотеки
add_definitions(-DGEOMETRY_LIB_EXPORTS)

# Создание статической библиотеки для классов
add_library(geometry_lib STATIC
    Point.cpp
    Point.h
    Segment.cpp
    Segment.h
    geometry_defines.h
)

# Создание динамической библиотеки для тестов
add_library(test_lib SHARED
    tests.cpp
)

# Создание исполняемого файла
add_executable(main_app main.cpp)

# Линковка библиотек
target_link_libraries(main_app PRIVATE geometry_lib)
target_link_libraries(test_lib PRIVATE geometry_lib)

# Добавление директорий с заголовочными файлами
target_include_directories(geometry_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(test_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(main_app PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}) 