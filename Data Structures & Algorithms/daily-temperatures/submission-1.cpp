class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> st;

        for (int i{}; i < n; ++i) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int lastDayIndex = st.top();
                st.pop();

                answer[lastDayIndex] = i - lastDayIndex;
            }

            st.push(i);
        }

        return answer;

    }

};
