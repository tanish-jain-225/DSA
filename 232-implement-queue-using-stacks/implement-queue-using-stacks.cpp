// Leetcode 232: Implement Queue using Stacks
class MyQueue // O(1) for push, O(n) for pop and peek
{
public:
    stack<int> s1,
        s2; // s1 is the main stack that holds the queue elements, s2 is a
            // temporary stack used during the pop and peek operations

    void push(int x) // O(n)
    {
        // Push element x to the back of queue.
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x); // push the new element to s1
        // Move all elements back to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop() // O(1)
    {
        // Removes the element from in front of queue and returns that element.
        int ans = s1.top();
        s1.pop();
        return ans;
    }

    int peek() // O(1)
    {
        // Get the front element.
        return s1.top();
    }

    bool empty() // O(1)
    {
        // Returns whether the queue is empty.
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */