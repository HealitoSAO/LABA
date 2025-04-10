#include "Trunin_LR3-4_Patient.h"
#include "Trunin_LR3-4_Methods.h"
#include <iostream>
#include <numeric>

// Конструктор по умолчанию
Patient::Patient() : name(""), age(0), diagnoses(), healthRatings() {}

// Параметризованный конструктор
// Patient::Patient(const std::string &name, int age,
//                  const std::vector<std::string> &diagnoses,
//                  const std::vector<int> &healthRatings)
//     : name(name), age(age), diagnoses(diagnoses), healthRatings(healthRatings) {}

// Конструктор копирования
Patient::Patient(const Patient &other)
    : name(other.name), age(other.age), diagnoses(other.diagnoses),
      healthRatings(other.healthRatings) {}

// Конструктор перемещения
Patient::Patient(Patient &&other) noexcept
    : name(std::move(other.name)), age(other.age),
      diagnoses(std::move(other.diagnoses)),
      healthRatings(std::move(other.healthRatings)) {
  other.age = 0; // Обнуляем перемещенные данные
}

// Оператор присваивания
Patient &Patient::operator=(const Patient &other) {
  if (this != &other) {
    name = other.name;
    age = other.age;
    diagnoses = other.diagnoses;
    healthRatings = other.healthRatings;
  }
  return *this;
}

// Деструктор
Patient::~Patient() {}

// Методы get и set
std::string Patient::getName() const { return name; }
void Patient::setName(const std::string &name) { this->name = name; }
int Patient::getAge() const { return age; }
void Patient::setAge(int age) { this->age = age; }
std::vector<std::string> Patient::getDiagnoses() const { return diagnoses; }
void Patient::setDiagnoses(const std::vector<std::string> &diagnoses) {
  this->diagnoses = diagnoses;
}
std::vector<int> Patient::getHealthRatings() const { return healthRatings; }
void Patient::setHealthRatings(const std::vector<int> &healthRatings) {
  this->healthRatings = healthRatings;
}

// Метод вывода информации о пациенте
void Patient::display() const {
  std::cout << "Name: " << name << ", Age: " << age
            << ", Diagnoses: ";
  for (const auto &diagnosis : diagnoses) {
    std::cout << diagnosis << " ";
  }
  std::cout << ", Health Ratings: ";
  for (const auto &rating : healthRatings) {
    std::cout << rating << " ";
  }
  std::cout << std::endl;
}

// Перегруженные операции
bool Patient::operator<(const Patient &other) const {
  return age > other.age; // Сравнение по возрасту
}

double Patient::averageHealth() const {
  if (healthRatings.empty())
    return 0.0;
  return std::accumulate(healthRatings.begin(), healthRatings.end(), 0.0) /
         healthRatings.size(); // Средняя оценка общего состояния
}

// bool Patient::operator>(const Patient &other) const {
//   return averageHealth() > other.averageHealth(); // Сравнение по средней
//                                                   // оценке общего состояния
// }

Patient Patient::operator+(const Patient &other) const {
  // Создаем новый объект Patient с суммой параметров
  std::vector<std::string> combinedDiagnoses = diagnoses;
  combinedDiagnoses.insert(combinedDiagnoses.end(), other.diagnoses.begin(),
                           other.diagnoses.end());
  std::vector<int> combinedHealthRatings = healthRatings;
  combinedHealthRatings.insert(combinedHealthRatings.end(),
                               other.healthRatings.begin(),
                               other.healthRatings.end());
  return Patient(name + " & " + other.name, age + other.age,
                 combinedDiagnoses, combinedHealthRatings);
}
Patient Patient::operator+(int additionalYear) const {
  // Создаем новый объект Patient с увеличенным годом
  Patient result;
  result.name = name;
  result.age = age + additionalYear;
  result.diagnoses = diagnoses;
  result.healthRatings = healthRatings;
  return result;
}

Patient &Patient::operator++() {
  // Префиксный инкремент: увеличиваем год на 1
  age++;
  return *this;
}

Patient Patient::operator++(int) {
  // Постфиксный инкремент: возвращаем копию текущего объекта, затем увеличиваем
  // год
  Patient temp = *this;
  age++;
  return temp;
}

Patient &Patient::operator&=(const Patient &other) {
  if (this != &other) {
    name = other.name;
    age = other.age;
    diagnoses = other.diagnoses;
    healthRatings = other.healthRatings;
  }
  return *this;
}
