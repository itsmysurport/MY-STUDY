#include <iostream>

using namespace std;
/* 함수의 중복을 설명하는 코드입니다. */

void outfunc();
void outfunc(int x);
void outfunc(int x, int y);

int main() {
    outfunc();
    outfunc(2);
    outfunc(1, 2);
}

void outfunc()
{
    int z = 1;
    cout << "No parameter : " << z << endl;
}

void outfunc(int x)
{
    cout << "One parameter : " << x << endl;
}

void outfunc(int x, int y)
{
    cout << "Two parameter : " << x + y << endl;
}
