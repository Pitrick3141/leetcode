class Solution {
public:
    string gcdOfStrings(string str1, string str2) {

        //Make str1 no shorter than str2
        if(str1.length() < str2.length()) swap(str1, str2);
        int size1 = str1.length(), size2 = str2.length();
        
        int divisorSize = str2.length();

        while(divisorSize > 0) {
            bool divisible = true;
            if(size2 % divisorSize == 0) {
                for(int i = 0; i < size2 && divisible; i += divisorSize) {
                    for(int j = 0; j < divisorSize && divisible; j++) {
                        if(str2[i+j] != str2[j]) divisible = false;
                    }
                }
                if(size1 % divisorSize == 0 && divisible) {
                    for(int i = 0; i < size1 && divisible; i += divisorSize) {
                        for(int j = 0; j < divisorSize && divisible; j++) {
                            if(str1[i+j] != str2[j]) divisible = false;
                        }
                    }
                }
                else divisible = false;
            }
            else divisible = false;
            
            if(divisible) return str2.substr(0, divisorSize);
            else divisorSize --;
        }

        return "";
    }
};