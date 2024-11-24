#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Рекурсивна функція для створення динамічного масиву
int* createArray(int n, int index = 0) {
    static int* arr = new int[n];
    if (index < n) {
        cin >> arr[index];
        createArray(n, index + 1);
    }
    return arr;
}

// Рекурсивна функція для виведення масиву
void printArray(int* arr, int n, const string& label, int index = 0) {
    if (index == 0) cout << label << ": ";
    if (index < n) {
        cout << setw(4) << arr[index];
        printArray(arr, n, label, index + 1);
    }
    else {
        cout << endl;
    }
}

// Рекурсивна функція для обчислення мінімального за модулем елемента
int findMinAbsElement(int* arr, int n, int index = 1, int minAbs = 0) {
    if (index == 1) minAbs = abs(arr[0]);
    if (index < n) {
        if (abs(arr[index]) < minAbs) {
            minAbs = abs(arr[index]);
        }
        return findMinAbsElement(arr, n, index + 1, minAbs);
    }
    return minAbs;
}

// Рекурсивна функція для обчислення суми модулів елементів після першого нульового елемента
int sumAfterFirstZero(int* arr, int n, int index = 0, bool zeroFound = false, int sum = 0) {
    if (index < n) {
        if (arr[index] == 0) {
            zeroFound = true;
        }
        else if (zeroFound) {
            sum += abs(arr[index]);
        }
        return sumAfterFirstZero(arr, n, index + 1, zeroFound, sum);
    }
    return sum;
}

// Рекурсивна функція для перестановки елементів масиву
void transformArray(int* arr, int n, int evenIndex = 0, int oddIndex = 0, int* temp = nullptr) {
    if (evenIndex == 0) temp = new int[n]; // ініціалізація temp
    if (evenIndex < n) {
        if (evenIndex % 2 == 0) {
            temp[evenIndex / 2] = arr[evenIndex];
        }
        else {
            temp[(n + 1) / 2 + oddIndex] = arr[evenIndex];
            oddIndex++;
        }
        transformArray(arr, n, evenIndex + 1, oddIndex, temp);
    }
    else {
        // Копіювання модифікованого масиву в оригінальний
        for (int i = 0; i < n; ++i) {
            arr[i] = temp[i];
        }
        delete[] temp;
    }
}

int main() {
    int n;
    cout << "Введіть кількість елементів масиву: ";
    cin >> n;

    if (n <= 0) {
        cout << "Невірний розмір масиву." << endl;
        return 1;
    }
    cout << "Введіть елементи масиву:" << endl;
    int* arr = createArray(n);
    printArray(arr, n, "Початковий масив");

    int minAbsElement = findMinAbsElement(arr, n);
    cout << "Мінімальний за модулем елемент: " << minAbsElement << endl;

    int sumModules = sumAfterFirstZero(arr, n);
    cout << "Сума модулів елементів після першого нульового елемента: " << sumModules << endl;

    transformArray(arr, n);
    printArray(arr, n, "Перетворений масив");

    delete[] arr;
    return 0;
}
