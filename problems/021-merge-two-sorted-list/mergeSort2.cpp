#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr){}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (list1 && list2){
        if(list1 -> val < list2 -> val){
            tail -> next = list1;
            list1 = list1 -> next;
        }else{
            tail -> next = list2;
            list2 = list2->next;
        }
        tail = tail -> next;
    }
    tail -> next = list1 ? list1 : list2;
    return dummy.next;
}

ListNode* inputList(int n){
    if(n==0) return nullptr;
    int x;
    cout << "Enter "<<n<<" sorted elements: ";
    cin>>x;
    ListNode* head = new ListNode(x);
    ListNode* curr = head;
    for (int i = 1; i<n; ++i){
        cin>>x;
        curr->next = new ListNode(x);
        curr = curr->next;
    }
    return head;
}

void printList(ListNode* head){
    while (head){
        cout<<head-> val;
        if(head->next) cout<<" -> ";
        head = head->next;
    }
    cout<<endl;
}

int main(){
    int n1, n2;

    cout<<"Enter number of elements in List 1: ";
    cin>>n1;
    ListNode* list1 = inputList(n1);
    cout<<"Enter number of elements in List 2: ";
    cin>>n2;
    ListNode* list2 = inputList(n2);
    cout<<"List 1: ";
    printList(list1);
    cout<<"List 2: ";
    printList(list2);
    ListNode* merged = mergeTwoLists(list1, list2);
    cout<<"Merged list: ";
    printList(merged);
    
    return 0;
}