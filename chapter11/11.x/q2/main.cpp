#include <iostream>
#include <algorithm>
#include "clearCin.h"

struct Student
{
  std::string firstName{};
  int grade{};
};

Student getStudent();
bool higherScoreStudent(Student a, Student b);
void printStudents(const std::vector<Student>& students);

int main()
{
  std::cout << "How many students do you want to enter? ";
  int numStudents;
  std::cin >> numStudents;
  handleCinBuffer();

  std::vector<Student> students(numStudents);
  for (int i { 0 }; i < numStudents; ++i)
  {
    students.at(i) = getStudent();
  }

  std::sort(students.begin(), students.end(), higherScoreStudent);
  printStudents(students);

  return 0;
}

Student getStudent()
{
  std::cout << "Enter a first name: ";
  std::string firstName{};
  std::cin >> firstName;
  handleCinBuffer();

  int grade{ -1 };
  while( grade < 0 || grade > 100)
  {
    std::cout << "Enter a grade: ";
    std::cin >> grade;
    handleCinBuffer();
  }

  return Student { firstName, grade };
}

bool higherScoreStudent(const Student& a, const Student& b)
{
  return a.grade > b.grade;
}

void printStudents(const std::vector<Student>& students)
{
  for(int i{ 0 }; i < students.size(); ++i)
  {
    std::cout << students.at(i).firstName << " got a grade of " << students.at(i).grade << '\n';
  }
}
