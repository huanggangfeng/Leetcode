class Solution {
public:
    bool canWinNim(int n) {
        if (n <= 3)
            return true;
        bool option1 = true;
        bool option2 = true;
        bool option3 = true;
        bool current = false;
        // 
        for (int i = 4; i <= n; i++) {
            // option1, option2， option3都是true，也就是说不管你这次拿几个，对方都能赢，所以当前必输，否则，就能赢
            if (option1 && option2 && option3)
                current = false;
            else 
                current = true;
             option1 = option2;
             option2 = option3;
             option3 = current;
        }
        return current;
    }
};

class Solution {
public:
    bool canWinNim(int n) {
        return (n % 4);
    }
};