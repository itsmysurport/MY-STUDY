#include <iostream>

int main(int argc, char const *argv[]) {
  char ch = 'A';
  while(ch <= 'Z')
  {
    if(ch > 'K')  break;
    std::cout << ch++ << '\n';
  }
  return 0;
}
