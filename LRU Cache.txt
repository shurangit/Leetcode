class LRUCache{
private:
    struct ListNode{
        int val;
        int key;
        ListNode *next;
        ListNode *prev;
        ListNode(int k,int v):key(k),val(v){}
    };
    int maxSize;//max size of cache
    ListNode *head;
    ListNode* tail;
    unordered_map<int, ListNode*> key2Node; //associate key to a node
     
    void insertToEnd(int key, int value){
        if(isFull()||key2Node.count(key)!=0) return;
        ListNode* tmp=new ListNode(key,value);
        key2Node[key]=tmp; //insert to hash
        //insert yo linkedlist
        if(!head) head=tail=tmp;
        else{
            tail->next=tmp;
            tmp->prev=tail;
            tail=tail->next;
        }
    }
    
    void removeHead(){
        if(!head) return;
        //hash
        key2Node.erase(head->key);
        ListNode* tmp=head;
        if(head==tail) head=tail=NULL;
        else{
            head=head->next;
            head->prev=NULL;
        }
        delete tmp;
    }
    
    void moveToEnd(int key){
        //key not exists or already in the end
        if(key2Node.count(key)==0||key2Node[key]==tail) return;
        ListNode* tmp=key2Node[key];
        if(tmp==head){
            head=head->next;
            head->prev=NULL;
           
        }else{
            tmp->prev->next=tmp->next;
            tmp->next->prev=tmp->prev;
        }
         tail->next=tmp;
         tmp->prev=tail;
         tmp->next=NULL;
         tail=tail->next;
    }
public:
    LRUCache(int capacity) {
       maxSize=capacity;
       head=NULL;
       tail=NULL;
       key2Node.clear();
    }
    
    int get(int key) {
        if(key2Node.count(key)==0) return -1;
        //for use key in the cache, move to the end
        moveToEnd(key);
        return key2Node[key]->val;
    }
    
    void set(int key, int value) {
        //key already exist
        if(get(key)!=-1){
            key2Node[key]->val=value;
            return;
        }
        //not exist
        if(isFull()) removeHead();
        insertToEnd(key,value);
    }
    
    bool isFull(){
        return key2Node.size()>=maxSize;
    }

};