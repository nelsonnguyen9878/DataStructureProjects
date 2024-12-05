#include <iostream>
#include <vector>
using namespace std;

int dynamicPalindrome(string);




int main() {

    // change the words in the quotation to check if there's any palindromes
    // some words to test: malayalam, racecar, civic, fell, mom
    string word = "civic";

    cout << dynamicPalindrome(word);
    return 0;
}



int dynamicPalindrome(string word) {

    // variables 
    int n = word.size(); 
    int length = 1; // setting it to one since theres always a palindrome of 1
    vector<vector<bool>> T(n, vector<bool>(n, false)); // 2D array

    // Print the table to verify
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << T[i][j] << " ";
        }
        cout << endl;
    }


    // base case where, each letter is a palindrome, sets the diagonal
    for(int i = 0; i < n; ++i) {
        T[i][i] = true;
    }

    // base case for finding palindrome length of 2
    for(int i = 0; i < n - 1; ++i) {
        if(word[i] == word[i + 1]) {
            T[i][i + 1] = true; 
            length = 2;
        }
    }

    // general case, lengths greater than 2
    for(int i = 3; i <= n; ++i) {
        for(int j = 0; j < n - i + 1; ++j) {
            // end index
            int k = j + i - 1;
            if(word[j] == word[k] && T[j + 1][k - 1] == true) {
                T[j][k] = true;
                if (i > length) {
                    length = i;
                }
            }
        }
     }

     cout << "\n\n";
     for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << T[i][j] << " ";
        }
        cout << std::endl;
    }
    return length;
}
