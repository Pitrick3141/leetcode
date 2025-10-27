class Solution {
public:
    int compress(vector<char>& chars) {
        int index = 1, count = 1;
        auto it = chars.begin();
        char current = *it;
        while(++it != chars.end()) {
            if(*it == current) count ++;
            else {
                if(count > 1) {
                    int tens = 1;
                    while(tens * 10 <= count) tens *= 10;
                    while(tens) {
                        chars[index++] = (count / tens) + '0';
                        count %= tens;
                        tens /= 10;
                    }
                }
                current = *it;
                chars[index++] = current;
                count = 1;
            }
        }
        if(count > 1) {
            int tens = 1;
            while(tens * 10 <= count) tens *= 10;
            while(tens) {
                chars[index++] = (count / tens) + '0';
                count %= tens;
                tens /= 10;
            }
        }
        return index;
    }
};