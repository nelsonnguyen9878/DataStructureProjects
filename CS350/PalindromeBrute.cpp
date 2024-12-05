#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int longestPalindromeSub(string);

int longestPalindromeSub(string word)
{
    int max = 1;
    int start = 0;

    // loops through the string
    for(int i = 0; i < word.length(); ++i) {
        // loops through the string from the second element
        for(int j = 1; j < word.length(); ++j) {
            int flag = 1;
            // checking for palindrome
            for(int k = 0; k < (j - i + 1) / 2; ++k) {
                if (word[i + k] != word[j - k])
                    flag = 0;
            }
            
            // if there is a palindrome, we set the max lenght of the palindrome 
            if(flag && (j - i + 1) > max) {
                start = i;
                max = j - i + 1;
            }
        }
    }
    // returns the length of the biggest palindrome
    return max;
}


int main() {

    // change the words in the quotation to check if there's any palindromes
    // some words to test: malayalam, racecar, civic, fell, mom, agcgt
    string word = "agcgt";
    //cout << word << ": " << longestPalindromeSub(word);

    auto start = high_resolution_clock::now();
    for(int i = 0; i < 10000000; ++i) {
        longestPalindromeSub(word);
    }
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);

    cout << duration.count() << endl;

    return 0;
}
