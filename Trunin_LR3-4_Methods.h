#ifndef TRUNIN_LR3_4_METHODS_H // Защита от повторного включения
#define TRUNIN_LR3_4_METHODS_H

#include "Trunin_LR3-4_Patient.h" // Подключаем заголовочный файл с определением класса Patient
#include <string>
#include <vector>

// Глобальный вектор объектов класса Patient
extern std::vector<Patient> patients;

// Функции проверки корректности входных данных
bool isValidYear(int year);
bool isValidPrice(double price);

void addPatient();

// Функция для отображения всех объектов класса
void showPatients();

// Функция для демонстрации функциональности всех конструкторов
void demonstrateConstructors();

// Функция для демонстрации функциональности всех методов класса
void demonstrateMethods();

// Функция для сортировки пациентов по возрасту
void sortPatientsByAge();

void inputPatient();
void displayAllPatients();

#endif // TRUNIN_LR3_4_METHODS_H

