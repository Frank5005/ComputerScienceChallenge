class Solution {
    public:
        string shortestPalindrome(string s) {
            string rev = s, palindrome;
            int n = s.length(), longestPalPrefix = 0;
            //Verify if it's palindrome
            if(s.empty()){
                return s;
            }
            reverse(rev.begin(), rev.end());
            if (rev == s){
                return rev;
            }
            //Finding the subset that it's palindrome
            for (int i = n; i >= 0; i--) {
                if (s.substr(0, i) == rev.substr(n - i)) {
                    longestPalPrefix = i;
                    break;
                }
            }
            //Adding the rest in the front
            palindrome = s.substr(longestPalPrefix);
            reverse(palindrome.begin(), palindrome.end());
            return palindrome + s;
        }
    };