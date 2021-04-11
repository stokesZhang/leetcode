#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

/*  环形链表
    模板题，Floyd判圈算法
*/
bool hasCycle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }
    ListNode *slow = head; // 初始时慢指针在位置 head，快指针在位置 head.next
    ListNode* fast = head->next;
    while (slow != fast) {
        if (fast == nullptr || fast->next == nullptr) {
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}

// 找到链表开始入环的第一个节点
ListNode *detectCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }
    ListNode *slow = head, *fast = head;
    do {
        if (fast == nullptr || fast->next == nullptr) {
            return nullptr;
        }
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

ListNode *detectCycle2(ListNode *head) { // Floyd判圈算法的另一种写法
    ListNode *slow = head, *fast = head;
    while (fast != nullptr) {
        slow = slow->next;
        if (fast->next == nullptr) {
            return nullptr;
        }
        fast = fast->next->next;
        if (fast == slow) {
            ListNode *ptr = head;
            while (ptr != slow) {
                ptr = ptr->next;
                slow = slow->next;
            }
            return ptr;
        }
    }
    return nullptr;
}