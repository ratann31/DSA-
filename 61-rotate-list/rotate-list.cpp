class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        // Edge Cases:
        // 1. Empty list
        // 2. Only one node
        // 3. No rotation required
        if(head == NULL || head->next == NULL || k == 0)
            return head;

        // -------------------------------
        // Step 1: Find the length of the list
        // and also keep track of the last node (tail)
        // -------------------------------
        int n = 1;                 // We are already at the first node
        ListNode* tail = head;

        while(tail->next) {
            tail = tail->next;     // Move to next node
            n++;                   // Increase length
        }

        // Example:
        // 1 -> 2 -> 3 -> 4 -> 5
        // n = 5
        // tail = 5

        // -------------------------------
        // Step 2: Remove unnecessary rotations
        // Rotating n times gives the same list.
        // Example:
        // n = 5, k = 7
        // 7 % 5 = 2
        // So only 2 rotations are needed.
        // -------------------------------
        k = k % n;

        // If k becomes 0, the list remains unchanged.
        if(k == 0)
            return head;

        // -------------------------------
        // Step 3: Make the linked list circular
        // Connect last node to first node.
        //
        // Before:
        // 1 -> 2 -> 3 -> 4 -> 5 -> NULL
        //
        // After:
        // 1 -> 2 -> 3 -> 4 -> 5
        // ^                    |
        // |____________________|
        // -------------------------------
        tail->next = head;

        // -------------------------------
        // Step 4: Find the new tail
        //
        // New tail will be at (n-k)th node.
        //
        // Example:
        // n = 5
        // k = 2
        //
        // New tail = 3
        // New head = 4
        // -------------------------------
        int steps = n - k;

        ListNode* newTail = head;

        // Move (steps-1) times because we are already
        // standing on the first node.
        for(int i = 1; i < steps; i++)
            newTail = newTail->next;

        // -------------------------------
        // Step 5: Node after newTail becomes newHead
        //
        // Example:
        // newTail = 3
        // newHead = 4
        // -------------------------------
        ListNode* newHead = newTail->next;

        // -------------------------------
        // Step 6: Break the circular list
        //
        // Before:
        // 3 -> 4 -> 5 -> 1 -> 2
        // ^                  |
        // |__________________|
        //
        // After:
        // 4 -> 5 -> 1 -> 2 -> 3 -> NULL
        // -------------------------------
        newTail->next = NULL;

        // Return the new head of the rotated list.
        return newHead;
    }
};