#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
};

int len(ListNode* list) 
{
	int count = 0; 
	if (list == NULL) return 0;
	ListNode *tmp = list; 
	while(tmp->next!=NULL) 
	{
		count++;
		tmp=tmp->next;
	}
	return count+1;
}
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
	ListNode* merge1 = list1; 
	ListNode* merge2 = list2;

	ListNode* merge = (ListNode*) malloc(sizeof(ListNode));
	merge->val=0;
	ListNode* tmp = merge;

	while(merge1 != NULL && merge2 != NULL){
		if(merge1->val <=  merge2->val){
			tmp->next = merge1;
			merge1 = merge1->next; 
		}
		else if(merge1->val > merge2->val) 
		{
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

	ListNode * result = merge->next;
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
	if(list==nullptr) return nullptr;
	ListNode *prev, *next, *current; 
	current = list; 
	while(current)
	{
//n=cn;cn=prv;prv=n;c=n;
		next = current->next;
		current->next = prev; 

		prev = next; 
		current=next;

	}
	return prev;

}
int main() {

    ListNode* list1 = new ListNode(1);

    list1->next = new ListNode(3);

    list1->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(2);

    list2->next = new ListNode(4);

    list2->next->next = new ListNode(6);

    ListNode* merged = mergeTwoLists(list1, list2);

    printList(merged);
    reverse(merged);
    printList(merged);
    return 0;

}
