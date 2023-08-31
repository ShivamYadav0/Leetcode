class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        //create new dummy tl ll for values<x
        ListNode* tl=new ListNode(0);
        ListNode* tlp=tl;
        //create new dummy th ll for values>=x
        ListNode* th=new ListNode(0);
        ListNode* thp=th;
        //pointer to traverse given ll
        ListNode* temp=head;
        while(temp!=NULL){
            if(temp->val<x){
                //attach it in tl linked list
                tlp->next=temp;
                tlp=temp;
            }else{
                //attach in th linked list
                thp->next=temp;
                thp=temp;
            }
            temp=temp->next;
        }
        //connecting tl and th 
        tlp->next=th->next;
        thp->next=NULL;
        return tl->next;
    }
};