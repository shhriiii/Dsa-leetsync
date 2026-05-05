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
    ListNode* rotateRight(ListNode* h, int k) {
        
 
        if (!h || !h->next || k == 0) return h;

        vector<ListNode*> a;
        ListNode* head = h;

        while (head != nullptr) {
            a.push_back(head);
            head = head->next;
        }

        k = k % a.size();
        int n = a.size();

        reverse(a.begin(), a.begin() + (n - k));
        reverse(a.begin() + (n - k), a.end());
        reverse(a.begin(), a.end());
        
        ListNode* dummy = a[0];
        head = dummy;

        for (int i = 1; i < n; i++) {
            dummy->next = a[i];
            dummy = dummy->next;
        }

        dummy->next = NULL;

        return head;
    }
};