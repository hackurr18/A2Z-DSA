#include <iostream>
using namespace std;

class Solution {
public:
    /*
        Checks whether a character is alphanumeric.
        Letters from a-z, A-Z, and digits from 0-9 are considered valid.
    */
    bool isAlphaNumeric(char ch) {
        return (ch >= 'a' && ch <= 'z') ||
               (ch >= 'A' && ch <= 'Z') ||
               (ch >= '0' && ch <= '9');
    }

    /*
        Converts an uppercase character to lowercase.
        Digits and lowercase letters are returned unchanged.
    */
    char toLowerChar(char ch) {
        if(ch >= 'A' && ch <= 'Z') {
            return char(ch + 32);
        }

        return ch;
    }

    /*
        Checks palindrome by cleaning the string first,
        then comparing characters from both ends.
    */
    bool isPalindrome(string s) {
        string cleaned = "";

        // Build the cleaned string using only lowercase alphanumeric characters
        for(char ch : s) {
            if(isAlphaNumeric(ch)) {
                cleaned += toLowerChar(ch);
            }
        }

        int left = 0;
        int right = cleaned.size() - 1;

        // Compare opposite characters of the cleaned string
        while(left < right) {
            if(cleaned[left] != cleaned[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};

/*
    Driver function used to test the better approach.
*/
int main() {
    string s = "A man, a plan, a canal: Panama";

    Solution obj;
    bool ans = obj.isPalindrome(s);

    cout << (ans ? "true" : "false");

    return 0;
}