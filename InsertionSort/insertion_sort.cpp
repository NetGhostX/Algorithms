#include <iostream>
#include <random>
#include <vector>

std::vector<int> genRandom(int size)
{
       std::random_device rd;
       std::mt19937 gen(rd()); // Seed the generator

       std::uniform_int_distribution<> distrib(1, 100); // Define the range

       std::vector<int> numbers;
       int N = 10; // Number of random numbers to generate
       for (int i = 0; i < N; ++i)
       {
              int random_number = distrib(gen);
              numbers.push_back(random_number);
       }
       return numbers;
}

void insert_sort(std::vector<int>& numbers)
{
       for (int i = 1; i < numbers.size(); i++)
       {
              int key = numbers[i]; //
              int j = i - 1;
              while( j >= 0  && numbers[j] > key)
              {
                     numbers[j + 1 ] = numbers[j];
                     j = j -1;
              }
              numbers[j + 1 ] = key;
       }
}

int main()
{
    std::vector<int> randomNumbers = genRandom(10);
    std::cout << "Before sorting:" << std::endl;
    for (int num : randomNumbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    insert_sort(randomNumbers);

    std::cout << "After sorting:" << std::endl;
    for (int num : randomNumbers)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
