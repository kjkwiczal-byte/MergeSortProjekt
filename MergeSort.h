/**
 * @file MergeSort.h
 * @brief Definicja szablonu klasy MergeSort realizującej sortowanie przez scalanie.
 */

#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

/**
 * @class MergeSort
 * @brief Szablon klasy implementującej algorytm sortowania przez scalanie (Merge Sort).
 * @tparam T Typ danych przechowywanych w tablicy (np. int, long int, float, double).
 */
template <typename T>
class MergeSort {
private:
    /**
     * @brief Scala dwie posortowane podtablice w jedną posortowaną całość.
     * @param arr Referencja do sortowanego wektora.
     * @param left Indeks początkowy lewej podtablicy.
     * @param mid Indeks środkowy dzielący podtablice.
     * @param right Indeks końcowy prawej podtablicy.
     */
    void merge(std::vector<T>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        std::vector<T> L(n1);
        std::vector<T> R(n2);

        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    /**
     * @brief Rekurencyjnie dzieli tablicę na mniejsze fragmenty i wywołuje ich scalanie.
     * @param arr Referencja do sortowanego wektora.
     * @param left Lewy indeks zakresu.
     * @param right Prawy indeks zakresu.
     */
    void sortRecursive(std::vector<T>& arr, int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;
        sortRecursive(arr, left, mid);
        sortRecursive(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

public:
    /**
     * @brief Główna metoda uruchamiająca sortowanie wektora rosnąco.
     * Bezpiecznie obsługuje tablice puste oraz jednoelementowe.
     * @param arr Referencja do wektora do posortowania.
     */
    void sort(std::vector<T>& arr) {
        if (arr.size() <= 1) return;
        sortRecursive(arr, 0, static_cast<int>(arr.size()) - 1);
    }
};

#endif