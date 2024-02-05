#include <iostream>
#include <vector>
#include <random>

// Function to generate random numbers
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

// Function to sort the numbers d
void selection_sort(std::vector<int> &numbers)
{
       for (int i = 0; i < numbers.size() - 1; i++)
       {
              int min_pos = i;
              for (int j = i + 1; j < numbers.size(); j++)
              {
                     if (numbers[j] < numbers[min_pos])
                     {
                            min_pos = j;
                     }
              }

              if (min_pos != i)
              {
                     int temp = numbers[i];
                     numbers[i] = numbers[min_pos];
                     numbers[min_pos] = temp;
              }
       }
}

int main()
{
       std::vector<int> unsortedNumbers = genRandom(10);
       std::cout << "Before sorting..." << std::endl;
       for (auto i : unsortedNumbers)
       {
              std::cout << i << " ";
       }
       std::cout << std::endl;

       std::cout << "After sorting..." << std::endl;

       selection_sort(unsortedNumbers);
       for (auto i : unsortedNumbers)
       {
              std::cout << i << " ";
       }

       return 0;
}