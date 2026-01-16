#include <iostream>
using namespace std;

int main()
{
    int rows, cols;
    cout << "We are supposed to create a 2D array. ";
    cout << "Please enter the number of rows and the number of columns: ";
    cin >> rows >> cols;

    const int MAX = 100; // just to be safe with storage
    int arr[MAX][MAX];
    int flat[MAX * MAX];
    int k = 0; // index for flattened 1D array

    cout << "\nEnter the values:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
            flat[k] = arr[i][j];
            k++;
        }
    }

    // Check for duplicates
    bool hasDuplicates = false;
    cout << "\n";

    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            if (flat[i] == flat[j]) {
                // Check if already printed
                bool alreadyPrinted = false;
                for (int x = 0; x < i; x++) {
                    if (flat[x] == flat[i]) {
                        alreadyPrinted = true;
                        break;
                    }
                }

                if (!alreadyPrinted) {
                    cout << "Duplicate value found: " << flat[i] << endl;
                    hasDuplicates = true;
                }
                break;
            }
        }
    }

    if (!hasDuplicates) {
        cout << "Thank you. There are no duplicate elements." << endl;
    }

    return 0;
}
