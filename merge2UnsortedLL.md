```
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;

    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;

    while (l1 != nullptr && l2 != nullptr) {
        if (l1->val < l2->val) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }

    if (l1 != nullptr) {
        current->next = l1;
    } else {
        current->next = l2;
    }

    return dummy->next;
}

ListNode* insertionSortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;

    ListNode* sorted = nullptr;
    ListNode* current = head;

    while (current != nullptr) {
        ListNode* nextNode = current->next;
        if (sorted == nullptr || current->val < sorted->val) {
            current->next = sorted;
            sorted = current;
        } else {
            ListNode* search = sorted;
            while (search->next != nullptr && search->next->val < current->val) {
                search = search->next;
            }
            current->next = search->next;
            search->next = current;
        }
        current = nextNode;
    }

    return sorted;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    cout << "Enter elements for the first list (-1 to end): ";
    ListNode* l1 = nullptr;
    ListNode* tail1 = nullptr;
    int num;
    while (cin >> num && num != -1) {
        if (l1 == nullptr) {
            l1 = new ListNode(num);
            tail1 = l1;
        } else {
            tail1->next = new ListNode(num);
            tail1 = tail1->next;
        }
    }

    cout << "Enter elements for the second list (-1 to end): ";
    ListNode* l2 = nullptr;
    ListNode* tail2 = nullptr;
    while (cin >> num && num != -1) {
        if (l2 == nullptr) {
            l2 = new ListNode(num);
            tail2 = l2;
        } else {
            tail2->next = new ListNode(num);
            tail2 = tail2->next;
        }
    }

    ListNode* mergedList = mergeTwoLists(l1, l2);
    ListNode* sortedList = insertionSortList(mergedList);

    cout << "Sorted list: ";
    printList(sortedList);

    while (l1 != nullptr) {
        ListNode* temp = l1;
        l1 = l1->next;
        delete temp;
    }

    while (l2 != nullptr) {
        ListNode* temp = l2;
        l2 = l2->next;
        delete temp;
    }

    delete mergedList;
    delete sortedList;

    return 0;
}
```
![image](https://github.com/jsamiksha1/ADSA-lab-/assets/101424133/376e7b13-47bb-4b9d-ba64-68860852d70d)
