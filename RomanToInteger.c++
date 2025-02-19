class Solution {
    public:
        int romanToInt(string s) {
            int solve = 0;
            //Separate the string
            int n = s.length();
            char arr[16];
            strcpy(arr, s.c_str());
            //Identify the characters and make the sum or substract
            int i = 0;
            for(int d = 0; d < n + 1; d++){
                if(arr[i] == 'I'){
                    if(arr[i+1] == 'V'){
                        solve += 4;
                        i += 2;
                    } else if(arr[i+1] == 'X'){
                        solve += 9;
                        i += 2;
                    } 
                    else{
                        solve += 1;
                        i += 1;
                    }
                }
                if(arr[i] == 'V'){
                    solve += 5;
                    i += 1;
                }
                if(arr[i] == 'X'){
                    if(arr[i+1] == 'L'){
                        solve += 40;
                        i += 2;
                    } else if(arr[i+1] == 'C'){
                        solve += 90;
                        i += 2;
                    } 
                    else{
                        solve += 10;
                        i += 1;
                    }
                }
                if(arr[i] == 'L'){
                    solve += 50;
                    i += 1;
                }
                if(arr[i] == 'C'){
                    if(arr[i+1] == 'D'){
                        solve += 400;
                        i += 2;
                    } else if(arr[i+1] == 'M'){
                        solve += 900;
                        i += 2;
                    } 
                    else{
                        solve += 100;
                        i += 1;
                    }
                }
                if(arr[i] == 'D'){
                    solve += 500;
                    i += 1;
                }
                if(arr[i] == 'M'){
                    solve += 1000;
                    i += 1;
                }
            }
            //Make the sum or substract
            return solve;
        }
    };
    