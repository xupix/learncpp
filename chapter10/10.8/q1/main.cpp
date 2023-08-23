#include <iostream>

struct Ads
{
  int adsShown{};
  // storing percentage as a decimal
  double percentageClicked{};
  double earnedPerClick{};
};

void printProfit(const Ads& ads)
{
  std::cout << ads.adsShown << " ads shown.\n";
  // displaying percentage as a percent so multiplying decimal * 100.
  std::cout << ads.percentageClicked * 100 << " percentage of ads clicked.\n";
  std::cout << ads.earnedPerClick << " earned per click.\n";

  std::cout << "total profit " << ads.adsShown * ads.earnedPerClick * ads.percentageClicked << '\n';
}

int main()
{
  Ads ads1{ 15, 0.5, 1.5};
  printProfit(ads1);

  Ads ads2{ 100, 0.25, 1.0};
  printProfit(ads2);

  return 0;
}
