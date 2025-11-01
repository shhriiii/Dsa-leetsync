class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> st(nums.begin(), nums.end());
        while (head && st.find(head->val) != st.end()) {
            head = head->next;
        }

        if (!head) return nullptr;
        ListNode* newHead = head;
        ListNode* curr = head->next;
        ListNode* prev = newHead;

        while (curr) {
            if (st.find(curr->val) != st.end()) {
                prev->next = curr->next;
            } else {
                prev = curr;
            }
            curr = curr->next;
        }

        return newHead;
    }
};
