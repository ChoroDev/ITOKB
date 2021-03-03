#include <iostream>

int main(int argc, char **argv)
{
  setlocale(LC_ALL, "");
  srand(time(NULL));

  const wchar_t *alphabet = L"абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
  const int lettersCount = wcslen(alphabet);

  int symbCount;

  wprintf(L"Enter symbols cout: ");
  wscanf(L"%d", &symbCount);

  // а
  // -
  wchar_t *pass = new wchar_t[symbCount + 1];
  for (int i = 0; i < symbCount; i++)
  {
    const int letterNumber = rand() % lettersCount;
    // wprintf(L"Next number: %d\n", letterNumber);
    pass[i] = alphabet[letterNumber];
  }
  pass[symbCount] = L'\0';
  wprintf(L"Generated password: %ls\n", pass);

  // -
  const int countOfTries = 66000;
  int *lettersDistribution = new int[lettersCount];
  for (int i = 0; i < countOfTries; i++)
  {
    const int letterNumber = rand() % lettersCount;
    lettersDistribution[letterNumber]++;
  }
  for (int i = 0; i < lettersCount; i++)
  {
    wprintf(L"%lc: %d\n", alphabet[i], lettersDistribution[i]);
  }

  delete pass;
  delete lettersDistribution;
  return 0;
}
