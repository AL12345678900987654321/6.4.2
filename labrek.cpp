#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// ���������� ������� ��� ��������� ���������� ������
int* createArray(int n, int index = 0) {
    static int* arr = new int[n];
    if (index < n) {
        cin >> arr[index];
        createArray(n, index + 1);
    }
    return arr;
}

// ���������� ������� ��� ��������� ������
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

// ���������� ������� ��� ���������� ���������� �� ������� ��������
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

// ���������� ������� ��� ���������� ���� ������ �������� ���� ������� ��������� ��������
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

// ���������� ������� ��� ������������ �������� ������
void transformArray(int* arr, int n, int evenIndex = 0, int oddIndex = 0, int* temp = nullptr) {
    if (evenIndex == 0) temp = new int[n]; // ����������� temp
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
        // ��������� �������������� ������ � �����������
        for (int i = 0; i < n; ++i) {
            arr[i] = temp[i];
        }
        delete[] temp;
    }
}

int main() {
    int n;
    cout << "������ ������� �������� ������: ";
    cin >> n;

    if (n <= 0) {
        cout << "������� ����� ������." << endl;
        return 1;
    }
    cout << "������ �������� ������:" << endl;
    int* arr = createArray(n);
    printArray(arr, n, "���������� �����");

    int minAbsElement = findMinAbsElement(arr, n);
    cout << "̳�������� �� ������� �������: " << minAbsElement << endl;

    int sumModules = sumAfterFirstZero(arr, n);
    cout << "���� ������ �������� ���� ������� ��������� ��������: " << sumModules << endl;

    transformArray(arr, n);
    printArray(arr, n, "������������ �����");

    delete[] arr;
    return 0;
}
