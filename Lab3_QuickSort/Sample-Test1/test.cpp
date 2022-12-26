#include "pch.h"
#include "../Lab3QuickSort/QuickSort.h"
	
		TEST(Sort, SmallIntSortAscend)
		{
			int const size = 10;
			int a[size];

			srand(time(NULL));
			for (int i = 0; i < size; i++) {
				a[i] = rand() % 100;
			}

			QuickAndInsertionSort(&a[0], &a[size - 1], [](auto a, auto b) { return a < b; });

			for (int i = 0; i < size - 1; i++)
				ASSERT_TRUE(a[i] <= a[i + 1]);
		}

		TEST(Sort, EqualIntSort)
		{
			int const size = 100;
			int a[size];

			srand(time(NULL));
			int value = rand() % 100;
			for (int i = 0; i < size; i++) {
				a[i] = value;
			}

			QuickSort(&a[0], &a[size - 1], [](auto a, auto b) { return a < b; });

			for (int i = 0; i < size - 1; i++)
				ASSERT_TRUE(a[i] <= a[i + 1]);
		}


		TEST(Sort, largeIntSortAscend)
		{
			int const size = 100;
			int a[size];

			srand(time(NULL));
			for (int i = 0; i < size; i++) {
				a[i] = rand() % 100;
			}

			QuickAndInsertionSort(&a[0], &a[size - 1], [](auto a, auto b) { return a < b; });

			for (int i = 0; i < size - 1; i++)
				ASSERT_TRUE(a[i] <= a[i + 1]);
		}

	

		TEST(Sort, SmallIntSortDescend)
		{
			int const size = 10;
			int a[size];

			srand(time(NULL));
			for (int i = 0; i < size; i++) {
				a[i] = rand() % 100;
			}

			QuickAndInsertionSort(&a[0], &a[size - 1], [](auto a, auto b) { return a > b; });

			for (int i = 0; i < size - 1; i++)
				ASSERT_TRUE(a[i] >= a[i + 1]);
		}

		TEST(Sort, largeIntSortDescend)
		{
			int const size = 100;
			int a[size];

			srand(time(NULL));
			for (int i = 0; i < size; i++) {
				a[i] = rand() % 100;
			}

			QuickAndInsertionSort(&a[0], &a[size - 1], [](auto a, auto b) { return a > b; });

			for (int i = 0; i < size - 1; i++)
				ASSERT_TRUE(a[i] >= a[i + 1]);
		}

		TEST(Sort, SmallFloatSortAscend)
		{
			int const size = 10;
			float a[size];

			srand(time(NULL));
			for (int i = 0; i < size; i++) {
				a[i] = rand() % 100;
			}

			QuickAndInsertionSort(&a[0], &a[size - 1], [](auto a, auto b) { return a < b; });

			for (int i = 0; i < size - 1; i++)
				ASSERT_TRUE(a[i] <= a[i + 1]);
		}

		TEST(Sort, largeFloatSortAscend)
		{
			int const size = 100;
			float a[size];

			srand(time(NULL));
			for (int i = 0; i < size; i++) {
				a[i] = rand() % 100;
			}

			QuickAndInsertionSort(&a[0], &a[size - 1], [](auto a, auto b) { return a < b; });

			for (int i = 0; i < size - 1; i++)
				ASSERT_TRUE(a[i] <= a[i + 1]);
		}

	
		TEST(Sort, SmallFloatSortDescend)
		{
			int const size = 10;
			float a[size];

			srand(time(NULL));
			for (int i = 0; i < size; i++) {
				a[i] = rand() % 100;
			}

			QuickAndInsertionSort(&a[0], &a[size - 1], [](auto a, auto b) { return a > b; });

			for (int i = 0; i < size - 1; i++)
				ASSERT_TRUE(a[i] >= a[i + 1]);
		}

		TEST(Sort, largeFloatSortDescend)
		{
			int const size = 100;
			float a[size];

			srand(time(NULL));
			for (int i = 0; i < size; i++) {
				a[i] = rand() % 100;
			}

			QuickAndInsertionSort(&a[0], &a[size - 1], [](auto a, auto b) { return a > b; });

			for (int i = 0; i < size - 1; i++)
				ASSERT_TRUE(a[i] >= a[i + 1]);
		}

