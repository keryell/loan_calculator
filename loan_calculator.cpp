#include <cmath>
#include <iostream>

int main() {
  // Number of month for the loan
  auto n = 36;
  // Yearly APR interest of 0.9%
  auto y = 0.009;
  // Amount to finance
  auto f = 26418.;
  // Monthly rate in a rough approximation
  auto i = y/12;
  auto a = f*(i + i/(std::pow(1 + i, n) - 1));
  std::cout << "Monthly payment of " << a << std::endl;
  std::cout << "Total cost of " << a*n << std::endl;
  std::cout << "Overhead of the loan " << a*n - f << std::endl;
  std::cout << "Overhead fraction of the loan " << a*n/f - 1 << std::endl;  
}
