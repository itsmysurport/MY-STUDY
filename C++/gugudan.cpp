#include <iostream>

int main(int argc, char const *argv[]) {
  int i, j;
  for(i = 1; i <= 9; i++)
  {
    std::cout << i << "dan" << "\n--------\n";
    for(j = 1; j<= 9; j++)
    {
      std::cout << i << "x" << j << "=" << i * j << "\n";
    }
    std::cout << "\n";
  }
  return 0;
}
