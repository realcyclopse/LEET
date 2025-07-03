class MinStack {
public:
    stack<long long> st;   // use long long to store possibly encoded values
    long long minVal;

    MinStack() {
        minVal = LLONG_MAX;
    }

    void push(int val) {
        if (st.empty()) {
            st.push(val);
            minVal = val;
        } else if (val < minVal) {
            st.push(2LL * val - minVal);  // encode safely
            minVal = val;
        } else {
            st.push(val);
        }
    }

    void pop() {
        if (st.top() < minVal) {
            // top is encoded, decode previous min
            minVal = 2LL * minVal - st.top();
        }
        st.pop();
    }

    int top() {
        if (st.top() < minVal) {
            return (int)minVal;
        }
        return (int)st.top();
    }

    int getMin() {
        return (int)minVal;
    }
};
