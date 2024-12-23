#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(); // Dummy node to simplify logic
        ListNode* current = dummy;       // Pointer to construct the result list
        int carry = 0;                   // Variable to store the carry-over

        while (l1 || l2 || carry) {
            int sum = carry; // Start with the carry from the previous addition
            if (l1) {
                sum += l1->val; // Add the value from the first list
                l1 = l1->next;  // Move to the next node
            }
            if (l2) {
                sum += l2->val; // Add the value from the second list
                l2 = l2->next;  // Move to the next node
            }
            
            carry = sum / 10;         // Calculate the carry for the next digit
            current->next = new ListNode(sum % 10); // Create a new node with the digit
            current = current->next; // Move the pointer to the next node
        }
        
        return dummy->next; // Return the head of the resulting list
    }
};

// Helper functions to test the implementation
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create two example linked lists: 342 (2 -> 4 -> 3) and 465 (5 -> 6 -> 4)
    ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
    ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);

    // Print the result list: 807 (7 -> 0 -> 8)
    printList(result);

    return 0;
}
