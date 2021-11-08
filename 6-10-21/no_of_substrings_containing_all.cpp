//https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0, j=0, count=0, temp=0;
        int arr[3] = {0};
        while(j<s.length())
        {
            if(arr[s[j++]-'a']++ == 0) temp++;
            
            while(temp == 3)
            {
                count += s.length()-j+1;
                if(arr[s[i++]-'a']-- == 1) temp--;
            }
        }
        return count;
    }
};