class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives{}, tens{};
        
        for (int i = 0; i < bills.size(); ++i) {
            int bill = bills[i];

            if (bill == 5) {
                fives++;
            } else if (bill == 10) {
                if (fives == 0) return false;
                tens++;
                fives--;
            } else {
                if (tens > 0 && fives > 0) {
                    fives--;
                    tens--;
                } else if (fives >= 3) {
                    fives -= 3;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};