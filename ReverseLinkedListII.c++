/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    public:
        ListNode* reverseBetween(ListNode* head, int left, int right) {
            ListNode* prev = nullptr;
            ListNode* current = head;
            //Base Case
            if(left == right){
                return head;
            }
            //Moving to the left node
            for (int i = 1; i < left; i++) {
                prev = current;
                current = current->next;
            }
            ListNode* connection = prev;
            ListNode* tail = current;
            //Reversing the list
            ListNode* next_node = nullptr;
            for (int i = 0; i <= right - left; i++) {
                next_node = current->next;
                current->next = prev;
                prev = current;
                current = next_node;
            }
            //Recreating the list
            if (connection) {
                connection->next = prev;
            } else {
                head = prev;
            }
    
            tail->next = current;
    
            return head;
        }
    };