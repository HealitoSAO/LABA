#ifndef TRUNIN_LR3_4_PATIENT_H
#define TRUNIN_LR3_4_PATIENT_H

#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

bool isValidNumber(const string &input) {
  if (input.empty())
    return false; // Пустая строка не является корректным числом
  for (char c : input) {
    if (!isdigit(c))
      return false; // Разрешаем только положительные числа
  }
  return true;
}

// Функция для ввода числа
void EnterNumber(int &varLink, const string &label) {
  string raw_input;
  cout << label;
  getline(cin, raw_input);

  // Цикл для повторного запроса числа, пока не будет введено корректное
  // значение
  while (!isValidNumber(raw_input)) {
    cout << "Invalid input. " << label;
    getline(cin, raw_input);
  }

  varLink = stoi(raw_input); // Преобразуем строку в целое число
}

class Patient {
private:
  string name;  
  int age; // Возраст пациента
  vector<std::string> diagnoses; // Список диагнозов
  vector<int> healthRatings; // Список оценок общего состояния пациента

public:
  // Конструкторы
  Patient(); // Конструктор по умолчанию
  // Patient &operator=(Patient &&) = delete;
  Patient(const string &name, int age, const vector<string> &diagnoses = {},
          const vector<int> &healthRatings = {})
      : name(name), age(age), diagnoses(diagnoses), healthRatings(healthRatings) {} // Параметризованный конструктор
  Patient(const Patient &other); // Конструктор копирования
  Patient(Patient &&other) noexcept; // Конструктор перемещения
  Patient &operator=(const Patient &other); // Оператор присваивания
  ~Patient();                                // Деструктор

  // Методы get и set
  string getName() const;
  void setName(const string &name);
  int getAge() const;
  void setAge(int age);
  vector<string> getDiagnoses() const;
  void setDiagnoses(const vector<string> &diagnoses);
  vector<int> getHealthRatings() const;
  void setHealthRatings(const vector<int> &healthRatings);

  // Метод вывода информации о пациенте
  void display() const;

  // Перегруженные операции
  double averageHealth() const; // Средняя оценка общего состояния
  bool operator<(const Patient &other) const; // Сравнение по средней оценке общего состояния
  Patient operator+(const Patient &other) const; // Сложение
  Patient operator+(int additionalYear) const;
  Patient &operator++();   // Префиксный инкремент
  Patient operator++(int); // Постфиксный инкремент
  Patient &operator&=(const Patient &other); // Оператор присваивания
  // Перегруженные операции ввода и вывода
  friend ostream &operator<<(ostream &os, const Patient &patient) {
    os << "Name: " << patient.name << ", Age: " << patient.age
       << ", Diagnoses: ";
    for (const auto &diagnosis : patient.diagnoses) {
      os << diagnosis << " ";
    }
    return os;
  }
  friend istream &operator>>(istream &is, Patient &patient) {
    cout << "Enter name: ";
    is >> ws; // Пропуск пробелов перед вводом
    getline(is, patient.name);
    cout << "Enter age: ";
    EnterNumber(patient.age, "Enter age: ");
    cout << "Enter number of diagnoses: ";
    string raw_count;
    is >> raw_count;
    // Цикл для повторного запроса количества, пока не будет введено корректное
    // значение
    while (!isValidNumber(raw_count)) {
      cout << "Invalid input. Enter number of diagnoses: ";
      is >> raw_count;
    }
    size_t count = stoi(raw_count);
    patient.diagnoses.resize(count);
    for (size_t i = 0; i < count; ++i) {
      cout << "Enter diagnosis " << i + 1 << ": ";
      is >> ws; // Пропуск пробелов перед вводом
      getline(is, patient.diagnoses[i]);
    }
    return is;
  }
};

#endif // TRUNIN_LR3_4_PATIENT_H