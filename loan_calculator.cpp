#include <cmath>
#include <iostream>

int main() {
  // Yearly APR interest of 0.9%
  auto y = 0.009;
  // Amount to finance
  auto f = 26418.;
  // Monthly rate in a rough approximation
  auto i = y/12;
  // Number of month for the loan
  for (auto n = 12; n <= 72; n += 12) {
    auto a = f*(i + i/(std::pow(1 + i, n) - 1));
    std::cout << "For " << n << "months:"<< std::endl;
    std::cout << "\tmonthly payment of " << a
	      << ", total cost of " << a*n << std::endl;
    std::cout << "\toverhead of the loan: " << a*n - f
	      << ", fraction of the loan: " << a*n/f - 1 << std::endl;
  }
}
