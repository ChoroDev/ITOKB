#include <iostream>
#include <time.h>

const int createPassword(const wchar_t *alphabet, const int lettersCount)
{
  int symbCount;

  wprintf(L"Enter symbols count: ");
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
  int *lettersDistribution = new int[lettersCount];

  for (int i = 0; i < lettersCount * 10000; i++)
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
  const int countOfTries = 5;
  const int symbolCounts[countOfTries] = {2, 3, 4, 5, 6};

  for (int symbCountNumber = 0; symbCountNumber < countOfTries; symbCountNumber++)
  {
    const long symbCount = symbolCounts[symbCountNumber];
    wprintf(L"Symbols count: %ld\n", symbCount);
    for (int tryNumb = 1; tryNumb < countOfTries + 1; tryNumb++)
    {
      // Password generation here
      wchar_t *pass = new wchar_t[symbCount + 1];
      pass[symbCount] = L'\0';
      for (int i = 0; i < symbCount; i++)
      {
        const int letterNumber = rand() % lettersCount;
        pass[i] = alphabet[letterNumber];
      }
      wprintf(L"Password: %ls. ", pass);

      // Brute force
      time_t start = time(0);

      int *bfSymbNumbers = new int[symbCount];
      for (int i = 0; i < symbCount; i++)
      {
        bfSymbNumbers[i] = 0;
      }

      int bfSymbNumbersSum = 0;
      bool increaseNext = false;
      bool isPassBruteForced = false;
      do
      {
        for (int i = 0; i < symbCount; i++)
        {
          if (increaseNext)
          {
            bfSymbNumbers[i]++;
          }
          if (bfSymbNumbers[i] > lettersCount - 1)
          {
            bfSymbNumbers[i] = 0;
            increaseNext = true;
          }
          else if (i == 0)
          {
            bfSymbNumbers[i]++;
          }
          else
          {
            increaseNext = false;
          }
        }
        int similarCount = 0;
        for (int i = 0; i < symbCount; i++)
        {
          if (alphabet[bfSymbNumbers[i]] == pass[i])
          {
            similarCount++;
          }
        }
        if (similarCount == symbCount)
        {
          break;
        }
        bfSymbNumbersSum++;
      } while (true);

      time_t end = time(0);

      // Time calculation
      const long int startInt = static_cast<long int>(start);
      const long int endInt = static_cast<long int>(end);
      const long int elapsed = endInt - startInt;
      wprintf(L"Guessing time: %lds\n", elapsed);

      delete pass;
      delete bfSymbNumbers;
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
