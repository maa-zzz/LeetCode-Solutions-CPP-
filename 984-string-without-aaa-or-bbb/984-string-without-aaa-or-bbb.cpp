class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string res = "";  
        while (A && B) {
            if (A > B) {
                res += "aab";
                A--;
            } else if (B > A) {
                res += "bba";
                B--;
            } else {
                res += "ab";
            }
            A--;
            B--;
        }
        while (A--) res += "a";
        while (B--) res += "b";
        return res;
    }
};