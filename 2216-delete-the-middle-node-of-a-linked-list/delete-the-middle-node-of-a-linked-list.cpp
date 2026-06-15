class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) {
            
            return nullptr;
        }

        int size = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            temp = temp->next;
            size++;
        }

        int mid = size / 2;

       
        if (mid == 0) {
            ListNode* toDelete = head;
            head = head->next;
            delete toDelete;
            return head;
        }

        int c = 0;
        temp = head;
        while (c < mid - 1) {
            temp = temp->next;
            c++;
        }

        ListNode* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;

        return head;
    }
};