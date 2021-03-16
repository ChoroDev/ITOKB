#include <iostream>
#include <time.h>

const int createPassword(const wchar_t *alphabet, const int lettersCount)
{
  int symbCount;

  wprintf(L"Enter symbols cout: ");
  wscanf(L"%d", &symbCount);
  wchar_t *pass = new wchar_t[symbCount + 1];
  for (int i = 0; i < symbCount; i++)
  {
    const int letterNumber = rand() % lettersCount;
    // wprintf(L"Next number: %d\n", letterNumber);
    pass[i] = alphabet[letterNumber];
  }
  pass[symbCount] = L'\0';
  wprintf(L"Generated password: %ls\n", pass);

  delete pass;
  return 0;
}

const int createDistribution(const wchar_t *alphabet, const int lettersCount)
{
  const int countOfTries = 660000;
  int *lettersDistribution = new int[lettersCount];

  for (int i = 0; i < countOfTries; i++)
  {
    const int letterNumber = rand() % lettersCount;
    lettersDistribution[letterNumber]++;
  }
  for (int i = 0; i < lettersCount; i++)
  {
    wprintf(L"%lc: %ld\n", alphabet[i], lettersDistribution[i]);
  }

  delete lettersDistribution;
  return 0;
}

const int calcAvgGuessTime(const wchar_t *alphabet, const int lettersCount)
{
  // step = 50000 - starting point
  // 10000000, 50000000, 100000000, 250000000, 500000000
  const long symbolCounts[5] = {10000000, 50000000, 100000000, 250000000, 500000000};
  const int countOfTries = 5;

  for (int symbCountNumber = 0; symbCountNumber < 5; symbCountNumber++)
  {
    const long symbCount = symbolCounts[symbCountNumber];
    wprintf(L"Symbols count: %ld\n", symbCount);
    for (int tryNumb = 1; tryNumb < countOfTries + 1; tryNumb++)
    {
      wchar_t *pass = new wchar_t[symbCount + 1];
      pass[symbCount] = L'\0';
      for (int i = 0; i < symbCount; i++)
      {
        const int letterNumber = rand() % lettersCount;
        // wprintf(L"Next number: %d\n", letterNumber);
        pass[i] = alphabet[letterNumber];
      }
      // wprintf(L"Password: %ls\n", pass);

      time_t start = time(0);

      for (long symbNumb = 0; symbNumb < symbCount; symbNumb++)
      {
        for (int i = 0; i < lettersCount; i++)
        {
          if (alphabet[i] == pass[symbNumb])
          {
            break;
          }
        }
      }

      time_t end = time(0);

      const long int startInt = static_cast<long int>(start);
      const long int endInt = static_cast<long int>(end);
      const long int elapsed = endInt - startInt;
      wprintf(L"Try %ld. Guessing time: %lds\n", tryNumb, elapsed);

      delete pass;
    }
  }

  return 0;
}

int main(int argc, char **argv)
{
  setlocale(LC_ALL, "");
  srand(time(NULL));

  const wchar_t *alphabet = L"абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
  const int lettersCount = wcslen(alphabet);

  // а
  // - 1

  // createPassword(alphabet, lettersCount);

  // - 2

  // createDistribution(alphabet, lettersCount);

  // - 3;

  calcAvgGuessTime(alphabet, lettersCount);

  return 0;
}
