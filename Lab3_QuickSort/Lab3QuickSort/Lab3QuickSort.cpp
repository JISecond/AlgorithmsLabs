
#include <fstream>
#include <chrono>
#include "QuickSort.h"
#include <iostream>



int main() {
    
  
    srand(time(NULL));

       std::ofstream f("SortTime.txt");

    for (int size = 1; size <= 100; ++size)
    {
        std::chrono::nanoseconds time1 = std::chrono::nanoseconds(0);
        std::chrono::nanoseconds time2 = std::chrono::nanoseconds(0);

        for (int j = 0; j < 100; ++j)
        {

            int* array1 = new int[size];
            int* array2 = new int[size];

            for (int i = 0; i < size; ++i)
                array1[i] = rand()%100;


            for (int i = size - 1, k = 1; i >= 0; i--, k++)
                array2[i] = k;
            
         

            auto start = std::chrono::high_resolution_clock::now();
            QuickSort(array1, array1 + size - 1, [](int a, int b) { return a < b; });
            auto end = std::chrono::high_resolution_clock::now();

            time1 += (end - start);

            start = std::chrono::high_resolution_clock::now();
            InsertionSort(array2, array2 + size - 1, [](int a, int b) { return a < b; });
            end = std::chrono::high_resolution_clock::now();

            time2 += (end - start);

            delete[] array1;
            delete[] array2;
        }

        time1 /= 100;
        time2 /= 100;

        if (f.is_open())
            f << size << " \t " << time1.count() << " \t " << time2.count() << "\n";


        
    }

   
    

    f.close();
    return 0;

 

}