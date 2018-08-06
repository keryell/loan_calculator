/** \file Compute the cost of different loan combinations

    https://en.wikipedia.org/wiki/Amortization_calculator
*/

#include <cmath>
#include <iostream>


/** Display the loan for a yearly APR

    \param f amount to finance

    \param y yearly APR (annual percentage rate)
*/
void display_loan(double f, double y) {
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

int main() {
  // Amount to finance
  auto f = 26418.;

  for (auto y : { 0.009, 0.01, 0.02, 0.03, 0.04, 0.05, 0.06 }) {
    std::cout << "APR = " << y << std::endl;
    display_loan(f, y);
  }
}
