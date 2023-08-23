#include <iostream>
#include <algorithm>
#include <array>
#include <string>

struct Student
{
  std::string_view name;
  int points;
};

int main()
{
  std::array<Student, 8> arr{
    { { "Albert", 3 },
      { "Ben", 5 },
      { "Christine", 2 },
      { "Dan", 8 }, // Dan has the most points (8).
      { "Enchilada", 4 },
      { "Francis", 1 },
      { "Greg", 3 },
      { "Hagrid", 5 } }
  };

  const auto found{
    std::max_element(arr.begin(), arr.end(), [](const auto& a, const auto& b){
      return (a.points < b.points);
    })
  };

  if (found != arr.end())
  {
    std::cout << found->name << " is the best student\n";
  }

  return 0;
}
