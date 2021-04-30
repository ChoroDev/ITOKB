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
  return number;
}

string multiplyLargeNumbers(string a, string b)
{
  const int firstLength = a.length();
  const int secondLength = b.length();

  int *aNumber = new int[firstLength];
  int *bNumber = new int[secondLength];
  int *res = new int[firstLength + secondLength];

  int i, j, tmp;
  for (i = 0; i < firstLength + secondLength; i++)
  {
    res[i] = 0;
  }

  for (i = firstLength - 1, j = 0; i >= 0; i--, j++)
  {
    aNumber[j] = a[i] - '0';
  }
  for (i = secondLength - 1, j = 0; i >= 0; i--, j++)
  {
    bNumber[j] = b[i] - '0';
  }

  for (i = 0; i < secondLength; i++)
  {
    for (j = 0; j < firstLength; j++)
    {
      res[i + j] += bNumber[i] * aNumber[j];
    }
  }
  for (i = 0; i < firstLength + secondLength; i++)
  {
    tmp = res[i] / 10;
    res[i] = res[i] % 10;
    res[i + 1] = res[i + 1] + tmp;
  }
  for (i = firstLength + secondLength; i >= 0; i--)
  {
    if (res[i] > 0)
      break;
  }
  const int newLength = i;
  string resString = "";
  for (i = newLength; i >= 0; i--)
  {
    resString += to_string(res[i]);
  }

  delete aNumber;
  delete bNumber;
  delete res;

  return resString;
}

string minusOne(string number)
{
  const int numLength = number.length();
  for (int i = numLength - 1; i > 0; i--)
  {
    int digit = number[i] - '0';
    if (digit > 0)
    {
      number.replace(i, 1, to_string(digit - 1));
      break;
    }
    else
    {
      number.replace(i, 1, "9");
    }
  }
  if (number[0] == '0')
  {
    string newNumber = "";
    for (int i = 1; i < numLength; i++)
    {
      newNumber += number[i];
    }
    return newNumber;
  }
  else
  {
    return number;
  }
}

string removeLeadingZeros(string str)
{
  while (str.size() > 1 && str[0] == '0')
  {
    str.erase(0, 1);
  }
  return str;
}

bool gt(string a, string b)
{
  a = removeLeadingZeros(a);
  b = removeLeadingZeros(b);
  return a.size() == b.size() ? a < b : a.size() < b.size();
}

void reduceDividend(string &a, const string &b)
{
  for (string::size_type cur_pos = 0; cur_pos < b.size(); ++cur_pos)
  {
    string::size_type a_cur_pos = a.size() - 1 - cur_pos;
    string::size_type b_cur_pos = b.size() - 1 - cur_pos;

    char &cur_a_dig_ref = a[a_cur_pos];
    const char &cur_b_dig_ref = b[b_cur_pos];

    if (cur_a_dig_ref >= cur_b_dig_ref)
    {
      cur_a_dig_ref -= cur_b_dig_ref - '0';
    }
    else
    {
      (cur_a_dig_ref -= cur_b_dig_ref - '0') += 10;
      for (int i = 1;; ++i)
      {
        if (a[a_cur_pos - i] == '0')
        {
          a[a_cur_pos - i] = '9';
        }
        else
        {
          --a[a_cur_pos - i];
          break;
        }
      }
    }
    removeLeadingZeros(a);
  }
  removeLeadingZeros(a);
}

string incrementNumber(string number)
{
  for (string::size_type i = number.size() - 1;; --i)
  {
    if (number[i] < '9')
    {
      ++number[i];
      return number;
    }
    else
    {
      number[i] = '0';
      if (i == 0)
      {
        number.insert(0, "1");
        return number;
      }
    }
  }
}

string divideLargeNumbers(string a, string b)
{
  string res = "0";
  string divisor = b;
  while (divisor.size() < a.size())
  {
    divisor += '0';
  }
  while (true)
  {
    while (!gt(a, divisor))
    {
      reduceDividend(a, divisor);
      res = incrementNumber(res);
    }
    if (divisor.size() <= b.size())
    {
      break;
    }
    divisor.erase(divisor.size() - 1);
    res += '0';
    res = removeLeadingZeros(res);
  }
  return res;
}

int main(int argc, char **argv)
{
  setlocale(LC_ALL, "");
  srand(time(NULL));

  string fileNames[10] = {"rsa309.txt", "rsa310.txt", "rsa320.txt", "rsa330.txt", "rsa340.txt", "rsa350.txt", "rsa360.txt", "rsa370.txt", "rsa380.txt", "rsa1024.txt"};
  const int idx1 = rand() % 10;
  int idx2 = rand() % 10;
  while (idx2 == idx1)
  {
    idx2 = rand() % 10;
  }
  const string fileName1 = fileNames[idx1];
  const string fileName2 = fileNames[idx2];

  string p;
  string q;
  ifstream sourceFile;
  sourceFile.open(fileName1);
  getline(sourceFile, p);
  sourceFile.close();
  sourceFile.open(fileName2);
  getline(sourceFile, q);
  sourceFile.close();

  // - 1

  cout << "p(" << p.length() << "): " << p << endl;
  cout << "q(" << q.length() << "): " << q << endl;

  const string n = multiplyLargeNumbers(p, q);
  cout << "n: " << n << endl;

  const string pMinus1 = minusOne(p);
  cout << "p - 1: " << pMinus1 << endl;
  const string qMinus1 = minusOne(q);
  cout << "q - 1: " << qMinus1 << endl;

  const string fi = multiplyLargeNumbers(pMinus1, qMinus1);
  cout << "fi: " << fi << endl;

  cout << divideLargeNumbers(qMinus1, pMinus1) << endl;

  return 0;
}
