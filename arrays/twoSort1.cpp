#include <iostream>
#include <cstdlib>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* merge1 = list1;
    ListNode* merge2 = list2;

    ListNode* merge = (ListNode*) malloc(sizeof(ListNode));
    merge->val = 0;
    merge->next = nullptr;   // very important

    ListNode* tmp = merge;

    while (merge1 != nullptr && merge2 != nullptr) {
        if (merge1->val <= merge2->val) {
            tmp->next = merge1;
            merge1 = merge1->next;
        } else {
            tmp->next = merge2;
            merge2 = merge2->next;
        }

        tmp = tmp->next;
    }

    if (merge1 != nullptr) {
        tmp->next = merge1;
    } else {
        tmp->next = merge2;
    }

    ListNode* result = merge->next;

    free(merge);   // dummy node free

    return result;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}
ListNode* reverse(ListNode* list) 
{
	//if(list==nullptr) return nullptr;
	ListNode *prev, *next, *current; 
	prev=nullptr;
	current = list; 
	while(current!=nullptr)
	{
		//n=cn;cn=prv;prv=n;c=n;
		next = current->next;
		current->next = prev; 
		prev = current; 
		current=next;

	}
	return prev;

}
bool hasCycle(ListNode* list) 
{
	ListNode* fast = list; 
	ListNode* slow = list; 
	while(fast != nullptr && fast->next !=nullptr){
		slow=slow->next;
		fast=fast->next->next; 
		if(slow->val==fast->val) 
			return true;
	}
return false;
}
int main() {
	ListNode* list1 = new ListNode(1);
	list1->next = new ListNode(3);
	list1->next->next = new ListNode(5);

	ListNode* list2 = new ListNode(2);
	list2->next = new ListNode(6);
	list2->next->next = new ListNode(6);

	ListNode* merged = mergeTwoLists(list1, list2);

	printList(merged);
	ListNode*tmp = reverse(merged);
	printList(tmp);
	list2->next->next = new ListNode(6);
	list2->next->next->next = new ListNode(8);
	list2->next->next->next->next = new ListNode(6);
	ListNode* head = new ListNode(1);
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(3);
	ListNode* node4 = new ListNode(4);

	head->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node2;  // ← Points back to node2!

	//hasCycle(head);  // Returns true ✓
	cout<<true<<":"<<hasCycle(list2)<<endl;
	printList(list2);
	ListNode*tmp1=reverse(list2);
	printList(tmp1);
	return 0;
}
