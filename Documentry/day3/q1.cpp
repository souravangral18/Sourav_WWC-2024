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
        ListNode* dummy = new ListNode(); 
        ListNode* current = dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = carry; // Start with the carry from the previous addition
            if (l1) {
                sum += l1->val;
                l1 = l1->next; 
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next; 
            }
            
            carry = sum / 10;
            current->next = new ListNode(sum % 10); 
            current = current->next; 
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
