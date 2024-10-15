#include <iostream>
#include <Windows.h>

using namespace std;

bool isInArray(int elem, int* arr, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == elem) {
            return true;
        }
    }
    return false;
}

void addUniqueElement(int elem, int*& result, int& resultSize, int& capacity) {
    if (!isInArray(elem, result, resultSize)) {
        if (resultSize == capacity) {
            capacity *= 2;
            int* newResult = new int[capacity];
            for (int i = 0; i < resultSize; i++) {
                newResult[i] = result[i];
            }
            delete[] result;
            result = newResult;
        }
        result[resultSize++] = elem;
    }
}

void findUniqueInA(int* A, int M, int* B, int N, int*& result, int& resultSize, int& capacity) {
    for (int i = 0; i < M; i++) {
        if (!isInArray(A[i], B, N)) {
            addUniqueElement(A[i], result, resultSize, capacity);
        }
    }
}

void findUniqueInBoth(int* A, int M, int* B, int N, int*& result, int& resultSize, int& capacity) {
    for (int i = 0; i < M; i++) {
        if (!isInArray(A[i], B, N)) {
            addUniqueElement(A[i], result, resultSize, capacity);
        }
    }

    for (int i = 0; i < N; i++) {
        if (!isInArray(B[i], A, M)) {
            addUniqueElement(B[i], result, resultSize, capacity);
        }
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int M, N;

    cout << "¬вед≥ть розм≥р масиву A: ";
    cin >> M;
    cout << "¬вед≥ть розм≥р масиву B: ";
    cin >> N;

    int* A = new int[M];
    int* B = new int[N];

    cout << "¬вед≥ть елементи масиву A:\n";
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }

    cout << "¬вед≥ть елементи масиву B:\n";
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    int capacity = M; 
    int* result = new int[capacity];
    int resultSize = 0;

    findUniqueInA(A, M, B, N, result, resultSize, capacity);

    findUniqueInBoth(A, M, B, N, result, resultSize, capacity);

    cout << "≈лементи масиву A, €ких немаЇ в масив≥ B, без повторень:\n";
    for (int i = 0; i < resultSize; i++) {
        cout << result[i] << " ";
    }

    cout << "≈лементи масив≥в A та B, €к≥ не Ї сп≥льними дл€ обох:\n";
    for (int i = 0; i < resultSize; i++) {
        cout << result[i] << " ";
    }

    delete[] A;
    delete[] B;
    delete[] result;
}
