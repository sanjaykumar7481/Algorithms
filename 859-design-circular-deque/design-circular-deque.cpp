class LL{
    public:
    int val;
    LL *next,*prev;
    LL(int data){
        this->val=data;
        this->next=NULL;
        this->prev=NULL;
    }
};
class MyCircularDeque {
public:
    int size,limit;
    LL *head,*last;
    MyCircularDeque(int k) {
        this->size=0;
        this->limit=k;
        this->head=NULL;
        this->last=NULL;
    }
    bool insertFront(int value) {
        if(isFull())return false;
        LL *nn=new LL(value);
        nn->next=this->head;
        if(!isEmpty())this->head->prev=nn;
        this->head=nn;
        if(isEmpty())this->last=nn;
        this->size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull())return false;
        if(isEmpty())return insertFront(value);
        LL *nn=new LL(value);
        this->last->next=nn;
        nn->prev=this->last;
        this->last=nn;
        this->size++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty())return false;
        if(this->size==1)
        {
            this->head=NULL;
            this->last=NULL;
        }
        else
        {
            this->head=this->head->next;
            this->head->prev=NULL;   
        }
        this->size--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty())return false;
        if(this->size==1)return deleteFront();
        this->last=this->last->prev;
        this->last->next=NULL;
        this->size--;
        return true;
    }
    
    int getFront() {
        if(isEmpty())return -1;
        return this->head->val;
    }
    
    int getRear() {
        if(isEmpty())return -1;
        return this->last->val;
    }
    
    bool isEmpty() {
        return this->size==0;
    }
    
    bool isFull() {
        return this->size==this->limit;
        
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */