#include "Trunin_LR3-4_Methods.h"
#include "Trunin_LR3-4_Patient.h"
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

// Инициализация глобального вектора
vector<Patient> patients;

// Функция проверки корректности года
bool isValidYear(int year) {
  return year > 0; // Год должен быть положительным
}

// Функция проверки корректности цены
bool isValidPrice(double price) {
  return price >= 0; // Цена не должна быть отрицательной
}
void EnterString(string &varLink, const string &label) {
  cout << label;
  getline(cin, varLink);
}
// Функция ввода пациента
void inputPatient() {
  Patient p;

  // Ввод ID пациента (если вы добавили поле id в Patient)
  int id;
  EnterNumber(id, "Enter patient ID: ");
  p.setId(id); // Предполагая, что вы добавили метод setId()

  // Ввод имени пациента
  string name;
  EnterString(name, "Enter patient name: ");
  p.setName(name);

  // Ввод возраста пациента
  int age;
  EnterNumber(age, "Enter patient age: ");
  p.setAge(age);

  // Ввод диагнозов
  int numDiagnoses;
  EnterNumber(numDiagnoses, "Enter number of diagnoses: ");
  vector<string> diagnoses(numDiagnoses);
  for (int i = 0; i < numDiagnoses; ++i) {
      EnterString(diagnoses[i], "Enter diagnosis " + to_string(i + 1) + ": ");
  }
  p.setDiagnoses(diagnoses);

  // Ввод оценок здоровья
  int numHealthRatings;
  EnterNumber(numHealthRatings, "Enter number of health ratings: ");
  vector<int> healthRatings(numHealthRatings);
  for (int i = 0; i < numHealthRatings; ++i) {
      EnterNumber(healthRatings[i], "Enter health rating " + to_string(i + 1) + ": ");
  }
  p.setHealthRatings(healthRatings);

  patients.push_back(p);
}

// Функция для отображения всех объектов класса
void displayAllPatients() {
  if (patients.empty()) {
    cout << "There are no patients to display." << endl;
    return;
  }
  for (const auto &patient : patients) {
    cout << patient << endl; // Используем перегруженную операцию вывода
  }
}

int getValidIndex() {
  int index;
  while (true) {
    cout << "Enter the index of a patient: ";
    string raw_input;
    cin >> raw_input;

    if (!isValidNumber(raw_input)) {
      cout << "Invalid input. Number expected." << endl;
      continue;
    }

    index = stoi(raw_input);

    if (index < 1 || index > patients.size()) {
      cout << "Invalid index." << endl;
      continue;
    }

    return index - 1;
  }
}

// Функция для демонстрации функциональности всех конструкторов
void demonstrateConstructors() {
  cout << "Demonstration of constructors:" << endl;

  // Создаем несколько объектов Patient
  Patient p1; // Конструктор по умолчанию
  Patient p2("John Doe", 25, {"Diagnosis 1"}, {100});
  Patient p3(p2);        // Конструктор копирования
  Patient p4 = p2 + 100; // Конструктор преобразования
  Patient p5("Jane Doe", 25, {"Diagnosis 2"}, {200}); // Делегирующий конструктор

  // Добавляем пациентов в вектор
  patients.push_back(p2);
  patients.push_back(p1);
  patients.push_back(p3);
  patients.push_back(p4);
  patients.push_back(p5);

  // Отображаем всех пациентов
  displayAllPatients();
}

// Функция для демонстрации функциональности всех методов класса
void demonstrateMethods() {
  cout << "Demonstrating methods:" << endl;

  if (patients.empty()) {
    cout << "No patients to demonstrate methods." << endl;
    return;
  }

  int q1_index = getValidIndex();
  int q2_index = getValidIndex();
  Patient q1 = patients[q1_index];
  Patient q2 = patients[q2_index];

  // Сравнение по году рождения
  int q3_index = getValidIndex();
  int q4_index = getValidIndex();
  Patient q3 = patients[q3_index];
  Patient q4 = patients[q4_index];

  cout << endl << "Comparing patients by year of birth: " << endl;
  if (q4 < q3) {
    cout << q3.getName() << " is older than " << q4.getName() << endl;
  } else if (q4 < q3) {
    cout << q4.getName() << " is older than " << q3.getName() << endl;
  } else {
    cout << q3.getName() << " and " << q4.getName()
         << " are from the same year" << endl;
  }

  cout << endl << "Comparing patients by average health rating: " << endl;
  int q5_index = getValidIndex();
  int q6_index = getValidIndex();
  Patient q5 = patients[q5_index];
  Patient q6 = patients[q6_index];

  if (q5 > q6) {
    cout << q5.getName() << " has a higher average health rating than "
         << q6.getName() << endl;
  } else if (q6 > q5) {
    cout << q6.getName() << " has a higher average health rating than "
         << q5.getName() << endl;
  } else {
    cout << q5.getName() << " and " << q6.getName()
         << " have the same average health rating" << endl;
  }

  cout << endl << "Displaying all patients:" << endl;
  displayAllPatients();
  cout << endl;

  cout << endl << "Sum: " << endl;
  int s1_index = getValidIndex();
  int s2_index = getValidIndex();

  Patient s1 = patients[s1_index];
  Patient s2 = patients[s2_index];
  Patient s4 = s1 + s2;
  cout << "The sum of " << s1.getName() << " and " << s2.getName() << " is "
       << s4.getName() << endl;
  cout << s4;
  patients.push_back(s4);

  cout << endl << "Displaying all patients:" << endl;
  displayAllPatients();
  cout << endl;

  cout << endl << "Postfix increment:" << endl;
  int i5_index = getValidIndex();

  Patient i5 = patients[i5_index];
  Patient i6 = i5++;
  cout << i6.getAge() << " is the same as " << i5.getAge() << endl;
  patients.push_back(i6);

  cout << endl << "Displaying all patients:" << endl;
  displayAllPatients();
  cout << endl;

  cout << endl << "Prefix increment:" << endl;
  int i7_index = getValidIndex();
  Patient i7 = patients[i7_index];
  Patient i8 = ++i7;
  cout << i8.getAge() << " is the same as " << i7.getAge() << endl;
  patients.push_back(i8);

  cout << endl << "Displaying all patients:" << endl;
  displayAllPatients();
  cout << endl;

  cout << endl << "averageHealthRating:" << endl;
  int a8_index = getValidIndex();
  Patient p8 = patients[a8_index];
  cout << p8.averageHealth() << endl;
}

void sortPatientsByYearBirth() {
  cout << "Sorting patients by year of birth:" << endl;
  std::sort(patients.begin(), patients.end(),
            [](const Patient &a, const Patient &b) { return a.getAge() < b.getAge(); });
  displayAllPatients();
}

