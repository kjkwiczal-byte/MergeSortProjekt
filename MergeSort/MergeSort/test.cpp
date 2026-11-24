#include "pch.h"
#include "../../MergeSort.h"
#include <vector>
#include <algorithm>

// 1. Zachowuje tablice niezmieniona, gdy ona jest juz posortowana rosnaco
TEST(MergeSortTest, AlreadySorted) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 1, 2, 3, 4, 5 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 2. Potrafi posortowac tablice, ktora jest posortowana w odwrotnej kolejnosci
TEST(MergeSortTest, ReverseSorted) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 5, 4, 3, 2, 1 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 3. Poprawnie sortuje losowa tablice liczb
TEST(MergeSortTest, RandomArray) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 38, 27, 43, 3, 9, 82, 10 };
    std::vector<int> expected = { 3, 9, 10, 27, 38, 43, 82 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 4. Poprawnie sortuje tablice tylko z liczbami ujemnymi
TEST(MergeSortTest, OnlyNegativeNumbers) {
    MergeSort<int> sorter;
    std::vector<int> arr = { -5, -1, -10, -3, -2 };
    std::vector<int> expected = { -10, -5, -3, -2, -1 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 5. Poprawnie sortuje tablice z liczbami ujemnymi i liczbami dodatnimi
TEST(MergeSortTest, NegativeAndPositiveNumbers) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 3, -2, 0, -5, 10, -1 };
    std::vector<int> expected = { -5, -2, -1, 0, 3, 10 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 6. Obsluguje pusta tablice bez rzucania wyjatkiem
TEST(MergeSortTest, EmptyArray) {
    MergeSort<int> sorter;
    std::vector<int> arr = {};
    EXPECT_NO_THROW(sorter.sort(arr));
    EXPECT_TRUE(arr.empty());
}

// 7. Nie zmienia tablicy, ktora zawiera tylko jeden element
TEST(MergeSortTest, SingleElement) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 42 };
    std::vector<int> expected = { 42 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 8. Poprawnie sortuje tablice z duplikatami liczb
TEST(MergeSortTest, ArrayWithDuplicates) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 4, 2, 4, 1, 2, 3, 1 };
    std::vector<int> expected = { 1, 1, 2, 2, 3, 4, 4 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 9. Poprawnie sortuje tablice ujemna z duplikatami
TEST(MergeSortTest, NegativeWithDuplicates) {
    MergeSort<int> sorter;
    std::vector<int> arr = { -4, -2, -4, -1, -2, -10 };
    std::vector<int> expected = { -10, -4, -4, -2, -2, -1 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 10. Poprawnie sortuje tablice z liczbami ujemnymi, dodatnimi oraz duplikatami
TEST(MergeSortTest, MixedWithDuplicates) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 5, -3, 0, 5, -3, 2, 0, -1 };
    std::vector<int> expected = { -3, -3, -1, 0, 0, 2, 5, 5 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 11. Poprawnie sortuje tablice zawierajaca tylko dwa elementy w kolejnosci rosnacej
TEST(MergeSortTest, TwoElementsAscending) {
    MergeSort<int> sorter;
    std::vector<int> arr = { 1, 2 };
    std::vector<int> expected = { 1, 2 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 12. Poprawnie sortuje duza tablice zawierajaca ponad 100 elementow
TEST(MergeSortTest, LargeArrayOver100) {
    MergeSort<int> sorter;
    std::vector<int> arr;
    for (int i = 150; i > 0; --i) {
        arr.push_back(i);
    }
    std::vector<int> expected = arr;
    std::sort(expected.begin(), expected.end());

    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

// 13. Poprawnie sortuje duza tablice (ponad 100 el.) z ujemnymi, dodatnimi i duplikatami
TEST(MergeSortTest, LargeMixedWithDuplicatesOver100) {
    MergeSort<int> sorter;
    std::vector<int> arr;
    for (int i = 0; i < 150; ++i) {
        arr.push_back((i % 25) - 12);
    }
    std::vector<int> expected = arr;
    std::sort(expected.begin(), expected.end());

    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}