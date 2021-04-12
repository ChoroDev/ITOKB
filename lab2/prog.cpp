#include <iostream>
#include <string>
#include <cmath>
#include <limits.h>

using namespace std;

char **createEncryptionTable(const int rowsCount, const int colsCount, string strToEncryptClean)
{
  char **encryptionTable = new char *[rowsCount];
  for (int row = 0; row < rowsCount; row++)
  {
    encryptionTable[row] = new char[colsCount];
    for (int col = 0; col < colsCount; col++)
    {
      encryptionTable[row][col] = strToEncryptClean[row * colsCount + col];
    }
  }

  cout << "Encryption table:" << endl;
  for (int row = 0; row < rowsCount; row++)
  {
    for (int col = 0; col < colsCount; col++)
    {
      cout << encryptionTable[row][col] << " ";
    }
    cout << endl;
  }
  return encryptionTable;
}

string encrypt(const int colsCount, string strToEncrypt)
{
  const int rowsCount = ceil((double)strToEncrypt.length() / colsCount);
  const int traillingSpacesCount = rowsCount * colsCount - strToEncrypt.length();
  for (int i = 0; i < traillingSpacesCount; i++)
  {
    strToEncrypt += ' ';
  }
  char **encryptionTable = createEncryptionTable(rowsCount, colsCount, strToEncrypt);

  string encrypted = "";
  for (int col = colsCount - 1; col >= 0; col--)
  {
    for (int row = 0; row < rowsCount; row++)
    {
      if (encryptionTable[row][col] != ' ')
      {
        encrypted += encryptionTable[row][col];
      }
    }
  }
  return encrypted;
}

char **createDecryptionTable(const int rowsCount, const int colsCount, string strToDecrypt)
{
  char **decryptionTable = new char *[rowsCount];
  for (int row = 0; row < rowsCount; row++)
  {
    decryptionTable[row] = new char[colsCount];
  }
  for (int col = colsCount - 1; col >= 0; col--)
  {
    for (int row = 0; row < rowsCount; row++)
    {
      if (row * colsCount + col < strToDecrypt.length())
      {
        decryptionTable[row][col] = strToDecrypt[row * colsCount + col];
      }
    }
  }

  cout << "Decryption table:" << endl;
  for (int row = 0; row < rowsCount; row++)
  {
    for (int col = 0; col < colsCount; col++)
    {
      cout << decryptionTable[row][col] << " ";
    }
    cout << endl;
  }
  return decryptionTable;
}

string decrypt(const int colsCount, string strToDecrypt)
{
  const int rowsCount = ceil((double)strToDecrypt.length() / colsCount);
  char **decryptionTable = createDecryptionTable(rowsCount, colsCount, strToDecrypt);
  string decrypted = "";
  for (int row = 0; row < rowsCount; row++)
  {
    for (int col = 0; col < colsCount; col++)
    {
      if (decryptionTable[row][col] != ' ')
      {
        decrypted += decryptionTable[row][col];
      }
    }
  }
  return decrypted;
}

// const void bruteForce(const string sourceStr)
// {
//   const string encrypted = encrypt(5, sourceStr);
//   for (int i = 2; i < 11; i++)
//   {
//     const string decrypted = decrypt(i, encrypted);
//     cout << "Decrypted: " << decrypted << endl;
//     if (sourceStr.compare(decrypted) == 0)
//     {
//       return;
//     }
//   }
//   return;
// }

int main(int argc, char **argv)
{
  setlocale(LC_ALL, "");
  srand(time(NULL));

  const int colsCount = 5;

  string strToEncrypt;
  cout << "Enter string (only latin):" << endl;
  getline(cin, strToEncrypt);

  string strToEncryptClean = strToEncrypt;
  for (int i = 0; i < strToEncryptClean.length(); i++)
  {
    if (strToEncryptClean[i] == ' ')
    {
      strToEncryptClean.erase(i, 1);
      i--;
    }
  }

  // - 1

  const string encrypted = encrypt(colsCount, strToEncryptClean);
  cout << "Encrypted: " << encrypted << endl;

  const string decrypted = decrypt(colsCount, encrypted);
  cout << "Decrypted: " << decrypted << endl;

  // - 2

  // bruteForce(strToEncryptClean);

  return 0;
}
