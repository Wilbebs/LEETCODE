class Solution {
public:
    bool isValid(string s) {
        stack<char> Stack; 
         
        for (int i = 0; i < s.length(); i++) {


        if (Stack.empty() && s.length() == 1) {

            return false; 

        }    

        if (i < s.length() && s[i] == '{' || s[i] == '[' || s[i] == '(') {

            Stack.push(s[i]); 

        } 
        else if (!Stack.empty() && i < s.length() && s[i] == '}' || s[i] == ']' || s[i] == ')') {

            if (!Stack.empty() && s[i] == '}' && Stack.top() == '{') {
              Stack.pop(); 
            }
            else if (!Stack.empty() && s[i] == ']' && Stack.top() == '[') {
              Stack.pop(); 
            }
            else if (!Stack.empty() && s[i] == ')' && Stack.top() == '(') {
              Stack.pop(); 
            }
            else {
                return false; 
            }

        }
        else if (Stack.empty() && i < s.length() && s[i] == '}' || s[i] == ']' || s[i] == ')' ) {

            return false; 

        }    
        
      }
       return Stack.empty(); 
    }
}; 

/*GPT Way w/ Unordered Map (Better Runtime, Larger Memory Consumption)
#include <stack>
#include <unordered_map>
#include <string>
#include <iostream>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> Stack; 
        
        // Map to store matching closing to opening brackets
        std::unordered_map<char, char> bracketMap = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            
            // If it's a closing bracket
            if (bracketMap.count(c)) {
                // Check if stack is empty or the top of the stack doesn't match
                if (Stack.empty() || Stack.top() != bracketMap[c]) {
                    return false;
                }
                Stack.pop(); // Pop the matched opening bracket
            } 
            // If it's an opening bracket
            else {
                Stack.push(c);
            }
        }
        
        // If the stack is empty, the string is valid
        return Stack.empty();
    }
}; */ 
