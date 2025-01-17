
#include <iostream>
using namespace std;

int findFirstOccurrence(int arr[], int n, int target) {
    int low = 0, high = n - 1, firstOccurrence = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            firstOccurrence = mid;
            high = mid - 1;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return firstOccurrence;
}

int countOccurrences(int arr[], int n, int target) {
    int first = findFirstOccurrence(arr, n, target);

    if (first == -1) {
        return -1;
    }

    int count = 1;
    int i = first + 1;

    while (i < n && arr[i] == target) {
        count++;
        i++;
    }

    return count;
}

int main() {
    int arr[] = {1,2,2,3,3,3,4,4,4,4,5,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target;

    cout << "Enter the target value: ";
    cin >> target;

    int first = findFirstOccurrence(arr, n, target);

    if (first == -1) {
        cout << "Target not found (-1)" << endl;
    } else {
        int count = countOccurrences(arr, n, target);
        cout << "First occurrence: " << first << ", Count: " << count << endl;
    }

    return 0;
}
