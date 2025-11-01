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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s(nums.begin(), nums.end());
        ListNode dummy(0, head);
        ListNode* cur = &dummy;
        while (cur->next) {
            if (s.count(cur->next->val)) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return dummy.next;
    }
};