#include <iostream>

int main(int argc, char const *argv[]) {
  int i, j;
  for(i = 0; i < 7; i++)
  {
    for(j = 0; j < i + 1; j++)
    {
      std::cout << '*';
    }
    std::cout << '\n';
  }

  for(i = 0; i < 7; i++)
  {
    for(j = 7; j > i; j--)
    {
      std::cout << '*';
    }
    std::cout << '\n';
  }
  return 0;
}
