#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

const int getModulo(int g, int power, int P)
{
  int modulo = 1;
  while (power)
  {
    if (power & 1)
    {
      modulo = (int)(modulo * 1ll * g % P);
      power--;
    }
    else
    {
      g = (int)(g * 1ll * g % P);
      power >>= 1;
    }
  }
  return modulo;
}

string get1024BitsStringNumber()
{
  string number = "1";
  const int charBytesLength = sizeof(char) * 8;
  const int numbersCount = 1024 / charBytesLength;
  for (int i = 1; i < numbersCount; i++)
  {
    number += to_string(rand() % 10);
  }
  cout << number << endl;
  return number;
}

int main(int argc, char **argv)
{
  setlocale(LC_ALL, "");
  srand(time(NULL));

  // - 1
  get1024BitsStringNumber();

  return 0;
}
