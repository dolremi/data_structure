struct Node{
  int val;
  struct Node Next;
Node(int d): val(d), Next(0){};
};

class stack{
  
 public: 
  int pop(){
    if(head){
      int item = head->val;
      Node *tmp = head;
      head = head->next;
      delete tmp;
      return item;
    }

    return -9999999;
  }
  void push(int new){
    Node *newNode = new Node(new);
    newNode -> Next = head;
    head = newNode;
  }

  int peek(){
    if(head){
      return head->val;
    }else{
      return -999999999;
    }
  }

 private:
  Node *head;
