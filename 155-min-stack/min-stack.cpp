
// Approach: Use a stack of pairs to store both the value and the current minimum at each level of the stack.
class MinStack
{
public:
    stack<pair<int, int>> s; // pair<value, current_min>

    void push(int val) // TC: O(1) SC: O(1)
    {
        if (s.empty())
        {
            s.push({val, val});
        }
        else
        {
            // Get the current minimum from the top of the stack
            int current_min = s.top().second;

            // Push the new value along with the updated minimum
            s.push({val, min(val, current_min)});
        }
    }

    void pop() // TC: O(1) SC: O(1)
    {
        if (!s.empty())
        {
            s.pop();
        }
    }

    int top() // TC: O(1) SC: O(1)
    {
        if (!s.empty())
        {
            return s.top().first; // Return the top value
        }
        return -1; // or throw an exception
    }

    int getMin() // TC: O(1) SC: O(1)
    {
        if (!s.empty())
        {
            return s.top().second; // Return the current minimum
        }
        return -1; // or throw an exception
    }
};


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */