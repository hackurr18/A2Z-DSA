#include <iostream>
using namespace std;

// Function to print a square pattern of stars
void pattern1(int N) {
    // Outer loop to handle rows
    for (int i = 0; i < N; i++) {
        // Inner loop to handle columns for each row
        for (int j = 0; j < N; j++) {
            // Print a star followed by a space
            cout << "* ";
        }
        // After printing stars in a row, move to the next line
        cout << endl;
    }
}
void pattern2(int N) {
        // Loop for rows
        for (int i = 0; i < N; i++) {
            // Loop for columns (stars in each row)
            for (int j = 0; j <= i; j++) {
                cout << "* ";
            }
            // Move to next line after each row
            cout << endl;
        }
}



int main() {
    int N = 5;  // Set the size of the square (5x5)
    //pattern1(N); // Call the function to print the pattern
    pattern2(N);
    return 0;
}