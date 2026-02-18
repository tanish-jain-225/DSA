class MyStack // O(n) for push, O(1) for pop, top, and empty
{
public:
    queue<int> q1, q2; // q1 is the main queue that holds the stack elements, q2
                       // is a temporary queue used during the push operation

    void push(int x) // O(n)
    {
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x); // push the new element to q1
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop() // O(1)
    {
        int topElement = q1.front();
        q1.pop();
        return topElement;
    }

    int top() // O(1)
    {
        return q1.front();
    }

    bool empty() // O(1)
    {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */