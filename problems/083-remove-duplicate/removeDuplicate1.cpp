#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode*next;
    ListNode(int x): val(x), next(nullptr){}
};

ListNode*deleteDuplicates(ListNode* head){
    ListNode* current = head;
    while(current != nullptr && current->next != nullptr){
        if(current->val == current->next->val){
            ListNode* toDelete = current->next;
            current->next = current->next->next;
            delete toDelete;
        }else{
            current = current->next;
        }
    }
    return head;
}

ListNode* createList(){
    int n;
    cout<<"Enter number of nodes in the sorted linked list: ";
    cin>>n;

    if(n==0) return nullptr;

    cout<<"Enter the elements in sorted order:\n";
    int val;
    cin>>val;
    ListNode*head = new ListNode(val);
    ListNode* tail = head;

    for (int i =1; i<n; ++i){
        cin>>val;
        tail->next = new ListNode(val);
        tail = tail->next;
    }

    return head;
}

void printList(ListNode* head){
    cout<<"Linked list after removing duplicates: ";
    while(head != nullptr){
        cout<<head->val;
        if(head->next) cout<<" -> ";
        head = head->next;
    }
    cout<<endl;
}

void freeList(ListNode* head){
    while(head != nullptr){
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main(){
    ListNode* head = createList();
    head = deleteDuplicates(head);
    printList(head);
    freeList(head);

    return 0;
}