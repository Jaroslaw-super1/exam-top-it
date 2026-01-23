#include <iostream>
#include <cstring>

int main(int argc, char ** argv)
{
  if (argc != 2)
  {
    return 4;
  }
  int command = std::atoi(argv[1]);

  if (command < 0 || command > 16)
  {
    return 4;
  }

  size_t * mtx = nullptr;

  size_t size = 0;
  signed long long summ = 0;
  signed long long median = 0;
  size_t maxln = 0;
  size_t minln = 0;
  size_t negative = 0;
  size_t positive = 0;
  size_t empty = 0;
  size_t sum_negative = 0;
  size_t sum_positive = 0;

  try
  {
    mtx = new size_t[size];
  }
  catch (...)
  {
    return 1;
  }

  try
  {
    size_t a = 0;
    long long n = 0;

    while (true)
    {
      std::cin >> a;

      if (std::cin.eof())
      {
        break;
      }
      if (std::cin.fail())
      {
        delete[] mtx;
        return 2;
      }

      size_t * tmp = nullptr;

      try
      {
        tmp = new size_t[size + a];
      }
      catch(...)
      {
        delete[] mtx;
        return 1;
      }

      for (size_t i = 0; i < size; i++)
      {
        tmp[i] = mtx[i];
      }
      delete[] mtx;
      mtx = tmp;

      maxln = std::max(a, maxln);
      if (size)
      {
        minln = std::min(a, minln);
      }
      else
      {
        minln = a;
      }
      if (!a)
      {
        empty++;
      }

      size += a;

      for (size_t i = 0; i < a; i++)
      {
        std::cin >> n;

        if (std::cin.eof())
        {
          delete[] mtx;
          return 7;
        }
        if (std::cin.fail())
        {
          delete[] mtx;
          return 2;
        }

        summ += n;
        if (n < 0)
        {
          negative++;
          sum_negative += n * (-1);
        }
        else
        {
          positive++;
          sum_positive += n;
        }

        mtx[size - a + i] = n;
      }
    }
  }
  catch(...)
  {
    delete[] mtx;
  }
  delete[] mtx;

  if (!size)
  {
    return 3;
  }

  if (summ < 0)
  {
    median = ((summ * (-1)) / size) * (-1);
  }
  else
  {
    median = summ / size;
  }

  switch (command)
  {
    case 0:
      std::cout << "size: " << size << '\n';
      break;
    case 1:
      std::cout << "median: " << median << '\n';
      break;
    case 2:
      std::cout << "maxln: " << maxln << '\n';
      break;
    case 3:
      std::cout << "maxseq: " << "<NOT SUPPORT>" << '\n';
      break;
    case 4:
      std::cout << "minln: " << minln << '\n';
      break;
    case 5:
      std::cout << "minseq: " << "<NOT SUPPORT>" << '\n';
      break;
    case 6:
      std::cout << "negative: -" << negative << '\n';
      break;
    case 7:
      std::cout << "positive: " << positive << '\n';
      break;
    case 8:
      std::cout << "medianln: " << "<NOT SUPPORT>" << '\n';
      break;
    case 9:
      std::cout << "empty: " << empty << '\n';
      break;
    case 10:
      std::cout << "sum-negative: " << sum_negative << '\n';
      break;
    case 11:
      std::cout << "sum-positive: " << sum_positive << '\n';
      break;
    case 12:
      std::cout << "average: " << "<NOT SUPPORT>" << '\n';
      break;
    case 13:
      std::cout << "sigma: " << "<NOT SUPPORT>" << '\n';
      break;
    case 14:
      std::cout << "dobsov: " << "<NOT SUPPORT>" << '\n';
      break;
    case 15:
      std::cout << "all: " << "<NOT SUPPORT>" << '\n';
      break;
  }

  

  return 0;
}
