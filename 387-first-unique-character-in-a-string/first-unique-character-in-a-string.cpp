class Solution // Define the Solution class
{
public:
    // Function to find the index of the first unique character in a string
    int firstUniqChar(string s) {
        unordered_map<char, int>
            charCount; // Map to store the count of each character
        queue<int> q;  // Queue to maintain the order of characters

        // Iterate through the string to count the occurrences of each character
        for (int i = 0; i < s.length(); i++) {
            if (charCount.find(s[i]) ==
                charCount.end()) // If the character is not in the map
            {
                charCount[s[i]] = 1; // Initialize count to 1
                q.push(i); // Push the index of the character into the queue
            } else {
                charCount[s[i]]++; // Increment the count if the character is
                                   // already in the map
            }

            while (q.size() > 0 &&
                   charCount[s[q.front()]] >
                       1) // Remove indices of characters that are not unique
            {
                q.pop(); // Pop the front index from the queue
            }
        }

        // If the queue is empty, return -1; otherwise, return the index of the
        // first unique character
        return q.size() == 0 ? -1 : q.front();
    }
};