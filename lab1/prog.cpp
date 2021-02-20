#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char **argv)
{
  const char *alphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";

  int symbCount = 0;
  cout << "Enter symbols count: ";
  cin >> symbCount;

  srand(time(NULL));
  cout << "random number 1: " << rand() % strlen(alphabet) << endl;
  cout << "random number 2: " << rand() % strlen(alphabet) << endl;

  for (int i = 1; i < 6; i++)
  {
    const char *what = "asd";
  }

  return 0;
}
