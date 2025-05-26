#pragma once

/**
 * @file geometry_defines.h
 * @brief Определения для экспорта/импорта библиотеки
 * @author Имя
 * @version 1.0
 * Этот файл содержит макросы для правильного экспорта/импорта
 * классов библиотеки при использовании в других проектах.
 */

#ifdef GEOMETRY_LIB_EXPORTS
#define GEOMETRY_API __declspec(dllexport)
#else
#define GEOMETRY_API __declspec(dllimport) 