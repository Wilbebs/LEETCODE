#include <string>

class Solution {
public:
    bool isPalindrome(int x) {
         
        string xStr = to_string(x);
        string reverseStr = xStr; 
        int j = 0; 
        for (int i = xStr.size()-1; i >= 0; --i) {
             
             reverseStr[j] =  xStr.at(i); 
             j++;
             
        }
    /*cout << "xStr: " << xStr << endl; 
    cout << "reverseStr: " << reverseStr << endl;*/

    if (xStr == reverseStr ) {
        return true; 
        }
    else if (xStr != reverseStr ) {
        return false; 
        }
        return true; 
    }
    
};