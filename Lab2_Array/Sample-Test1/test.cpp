#include "pch.h"
#include "../Lab2Array/Array.h"


TEST(Array, DefaultConstructor) {
	Array<int> a;
	ASSERT_EQ(a.size(), 0);

}

TEST(Array, CapacityConstructor) {
	Array<int> a(100);
	ASSERT_EQ(a.size(), 0);
}

TEST(Array, CopyConstructor) {
	Array<int> a;
	a.insert(1);
	Array<int> b(a);
	ASSERT_EQ(b.size(), 1);
}

TEST(Array, MoveConstructor) {
	Array<int> a;
	a.insert(1);
	Array<int> b(std::move(a));
	ASSERT_EQ(a.size(), 0);
	a.~Array();
	ASSERT_EQ(b.size(), 1);
}

TEST(Array, CopyOperator) {
	Array<int> a;
	a.insert(1);
	Array<int> b;
	b.insert(3);
	b.insert(4);
	b = a;
	ASSERT_EQ(b.size(), 1);
	ASSERT_EQ(b[0], 1);
}

TEST(Array, MoveOperator) {
	Array<int> a;
	a.insert(1);
	Array<int> b;
	b.insert(3);
	b.insert(4);
	b = std::move(a);
	ASSERT_EQ(b.size(), 1);
	ASSERT_EQ(b[0], 1);
}

TEST(Array, Insert) {
	Array<int> a;
	int testSize = 10;
	for (int i = 0; i < testSize; ++i) {
		a.insert(i + 1);
	}
	ASSERT_EQ(a.size(), testSize);
	for (int i = 0; i < testSize; ++i) {
		ASSERT_EQ(a[i], i + 1);
	}
}

TEST(Array, Change) {
	Array<int> a;
	int testSize = 10;
	for (int i = 0; i < testSize; ++i) {
		a.insert(i + 1);
	}
	for (int i = 0; i < a.size(); ++i) {
		a[i] *= 2;
	}
	for (int i = 0; i < testSize; ++i) {
		ASSERT_EQ(a[i], 2 * (i + 1));
	}
}

TEST(Array, Remove) {
	Array<int> a;
	int testSize = 10;
	for (int i = 0; i < testSize; ++i) {
		a.insert(i + 1);
	}
	a.remove(3);
	ASSERT_EQ(a[3], 5);
}

TEST(Array, Iterator) {
	Array<int> a;
	int testSize = 10;
	for (int i = 0; i < testSize; ++i) {
		a.insert(i + 1);
	}
	int i = 0;
	int counter = 1;
	for (Array<int>::Iterator it = a.iterator(); it.hasNext(); it.next()) {
		ASSERT_EQ(it.get(), i + 1);
		i++;
		counter++;
	}
	ASSERT_EQ(testSize, counter);
}

TEST(Array, ReverseIterator) {
	Array<int> a;
	int testSize = 100;
	for (int i = 0; i < testSize; ++i) {
		a.insert(i + 1);
	}
	int i = testSize - 1;
	int counter = 1;
	for (Array<int>::Iterator it = a.reverseIterator(); it.hasNext(); it.next()) {
		ASSERT_EQ(it.get(), i + 1);
		i--;
		counter++;
	}
	ASSERT_EQ(testSize, counter);
}

TEST(Array, SetIterator) {
	Array<int> a;
	int testSize = 10;
	for (int i = 0; i < testSize; ++i) {
		a.insert(i + 1);
	}

	Array<int>::Iterator it = a.iterator();
	it.next();
	it.next();
	ASSERT_EQ(it.get(), 3);
	it.set(-100);
	ASSERT_EQ(it.get(), -100);
}

TEST(Array, ComplexType) {
	Array<Array<int>> a;
	Array<int> ai;
	ai.insert(-100);
	a.insert(ai);
	ASSERT_EQ(a[0][0], -100);
}

TEST(Array, ExpandTest) {
	int testSize = 20;
	Array<int> a(testSize);
	for (int i = 0; i < 100 * testSize; ++i) {
		a.insert(i + 1);
	}
	ASSERT_EQ(a.size(), 100 * testSize);
}

TEST(Array, StringTest) {
	int testSize = 20;
	int inc = 100;
	Array<std::string> a(testSize);
	for (int i = 0; i < inc * testSize; ++i) {
		a.insert(std::to_string(i + 1));
	}
	ASSERT_EQ(a.size(), inc * testSize);
	for (int i = 0; i < inc * testSize; ++i) {
		ASSERT_EQ(a[i], std::to_string(i + 1));
	}
}



TEST(Array, MiddleInsert) {
	Array<int> a;
	int testSize = 10;
	for (int i = 0; i < testSize; ++i) {
		a.insert(i + 1);
	}
	a.insert(testSize / 2, -1);
	ASSERT_EQ(testSize + 1, a.size());
	for (int i = 0; i < testSize / 2; i++) {
		ASSERT_EQ(a[i], i + 1);
	}
	ASSERT_EQ(a[testSize / 2], -1);
	for (int i = testSize / 2 + 1; i < a.size(); i++) {
		ASSERT_EQ(a[i], i);
	}
}



TEST(Array, ClearAndInsert) {
	int testSize = 20;
	int inc = 100;
	Array<std::string> a(testSize);
	for (int i = 0; i < inc * testSize; ++i) {
		a.insert(std::to_string(i + 1));
	}
	while (a.size() != 0) {
		a.remove(0);
	}
	a.insert("newString");
	ASSERT_EQ(a.size(), 1);
	ASSERT_EQ(a[0], "newString");
}