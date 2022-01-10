class Solution
{
    public:
    void linkdelete(struct Node  *head, int n, int m)
    {
        //Add code here 
        while(head != NULL){
            int k = n;
            k--;
            while(k>0 && head != NULL){
                k--;
                head = head->next;
            }
            if(head == NULL)
            return;
            
            Node* pt = head;
            k=m;
            while(k>0 && pt != NULL){
                k--;
                pt = pt->next;
            }
            if(pt == NULL){
                head->next = pt;
            }
            else{
                head->next = pt->next;
            }
            head = head->next;
        }
    }
};
