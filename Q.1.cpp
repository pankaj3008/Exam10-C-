#include <iostream>
using namespace std;

// Selection Sort
void SS(int arr[], int N) {
    for(int i = 0; i < N - 1; i++) {
        int smallest = i;
        for(int j = i + 1; j < N; j++) {
            if(arr[j] < arr[smallest]) {
                smallest = j;
            }
        }
        swap(arr[i], arr[smallest]);
    }
}

// Merge Function
void merge(int arr[], int start, int end, int middle) {
    int leftside = middle - start + 1;
    int rightside = end - middle;

    int left[leftside];
    int right[rightside];

    for(int i = 0; i < leftside; i++) {
        left[i] = arr[start + i];
    }
    for(int i = 0; i < rightside; i++) {
        right[i] = arr[middle + 1 + i];
    }

    int i = 0, j = 0, k = start;

    while(i < leftside && j < rightside) {
        if(left[i] < right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    while(i < leftside) {
        arr[k++] = left[i++];
    }
    while(j < rightside) {
        arr[k++] = right[j++];
    }
}

// Merge Sort
void MS(int arr[], int start, int end) {
    if(start >= end) return;

    int middle = (start + end) / 2;
    MS(arr, start, middle);
    MS(arr, middle + 1, end);
    merge(arr, start, end, middle);
}

// Linear Search
int Linearsearch(int arr[], int size, int key) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == key) return i;
    }
    return -1;
}

// Binary Search (Recursive)
int binarysearch(int arr[], int start, int end, int target) {
    if(start > end) return -1;

    int middle = (start + end) / 2;
    if(arr[middle] == target) return middle;
    else if(arr[middle] < target) return binarysearch(arr, middle + 1, end, target);
    else return binarysearch(arr, start, middle - 1, target);
}

// Print Array
void print(int arr[], int N) {
    for(int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int size;
    int choice;

    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];

    cout << "Enter the elements of the array: ";
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    do {
        cout << "\nChoose an option: " << endl;
        cout << "1. Merge Sort" << endl;
        cout << "2. Selection Sort" << endl;
        cout << "3. Linear Search" << endl;
        cout << "4. Binary Search" << endl;
        cout << "5. Display the array" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        int target, result;

        switch (choice) {
            case 1:
                MS(arr, 0, size - 1);
                cout << "Array sorted using Merge Sort." << endl;
                break;

            case 2:
                SS(arr, size);
                cout << "Array sorted using Selection Sort." << endl;
                break;

            case 3:
                cout << "Enter the element to search: ";
                cin >> target;
                result = Linearsearch(arr, size, target);
                if(result != -1)
                    cout << "Element found at index " << result << endl;
                else
                    cout << "Element not found." << endl;
                break;

            case 4:
                cout << "Enter the element to search: ";
                cin >> target;
                result = binarysearch(arr, 0, size - 1, target);
                if(result != -1)
                    cout << "Element found at index " << result << endl;
                else
                    cout << "Element not found." << endl;
                break;

            case 5:
                cout << "Current array: ";
                print(arr, size);
                break;

            case 0:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice! Try again." << endl;
                break;
        }

    } while(choice != 0);

    return 0;
}
