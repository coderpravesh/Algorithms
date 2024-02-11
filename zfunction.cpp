//  The Z-function for this string is an array of length n where the  
// i-th element is equal to the greatest number of characters starting from the position  
// i that coincide with the first characters of s

class Solution {
public:
    vector<int> zFunction(string word) {
        vector <int> z(word.length(), 0);
        int left = 0;
        int right = 0;
        for (int i = 1; i < word.length(); i++) {
            if (i > right) {
                left = right = i;
                while (right < word.length() && word[right] == word[right - left]) {
                    right++;
                }
                z[i] = right - left;
                right--;
            } else {
                // we are operating inside the box 
                // checking the value is inside the box
                if (z[i - left] < right - i + 1) {
                    z[i] = z[i - left];
                } else {
                    left = i;
                    while (right < word.length() && word[right] == word[right - left]) {
                        right++;
                    }
                    z[i] = right - left;
                    right--;
                }
            }
        }
        return z;
    }

    int minimumTimeToInitialState(string word, int k) {
        int n = word.length();
        int ans = (n + k - 1) / k ;
        vector<int> z = zFunction(word);
        for (int i = k ; i < n; i += k) {
            if (z[i] >= n-i) {
                return i / k;
            }
        }

        return ans;
    }
};
