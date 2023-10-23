class LRUCache {
public:
class node
{
    public:
    int key;
    int val;
    node* prev;
    node* ne;
    node(int key,int value)
    {
        this->key=key;
        this->val=value;
    }
};
int cap;
unordered_map<int,node*>m;
node* head=new node(-1,-1);
node* tail=new node(-1,-1);
    LRUCache(int capacity) {
        cap=capacity;
        head->ne=tail;
        tail->prev=head;
    }
    void addnode(node* newnode)
    {
        node* temp=head->ne;
        newnode->ne=temp;
        newnode->prev=head;
        head->ne=newnode;
        temp->prev=newnode;
    }
    void delnode(node* n)
    {
        node* p=n->prev;
        node* a=n->ne;
        p->ne=a;
        a->prev=p;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end())
        {
            node* n=m[key];
            int ans=n->val;
            m.erase(key);
            delnode(n);
            addnode(n);
            m[key]=head->ne;
            return ans;
        }
        return -1;
        
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end())
        {
            node* curr=m[key];
            m.erase(key);
            delnode(curr);
        }
        if(m.size()==cap)
        {
            m.erase(tail->prev->key);
            delnode(tail->prev);
        }
        addnode(new node(key,value));
        m[key]=head->ne;
        
    }
};
