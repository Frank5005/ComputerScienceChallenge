class Solution {
    public:
        string reverseWords(string s) {
            string solve = "", word;
            vector<string> words;
            ostringstream oss;
            //Removing spaces
            istringstream iss(s);
            //Split the string and put it in a vector
            while(iss >> word){
                words.push_back(word);
            }
            //Change the order of the words
            reverse(words.begin(), words.end());
            //Return the vector to the word
            //Include the space between words
            for(int i = 0; i < words.size(); ++i){
                if(i != 0){
                    oss << " ";
                }
                oss << words[i];
            }
            solve = oss.str();
            return solve;
        }
    };