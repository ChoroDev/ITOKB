#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char **argv)
{
  setlocale(LC_ALL, "ru_RU.utf8");
  srand(time(NULL));

  const wchar_t *alphabet = L"абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
  const int lettersCount = wcslen(alphabet);
  wcout << L"Салам" << endl;

  int symbCount = 0;
  wprintf(L"Enter symobols count: ");
  wscanf(L"%d", &symbCount);

  wchar_t *pass = new wchar_t(symbCount);
  for (int i = 0; i < symbCount; i++)
  {
    const int letterNumber = rand() % lettersCount;
    wprintf(L"Next number: %d\n", letterNumber);
    pass[i] = alphabet[letterNumber];
  }
  wprintf(L"Generated password: %ls\n", pass);

  return 0;
}
