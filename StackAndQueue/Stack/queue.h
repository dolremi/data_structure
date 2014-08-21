struct Node {
  int val;
  struct Node * Next;
  Node (int d): val(d), Next(0){};
};

class queue{
 public:
  void enqueue(int d){
    // check if the first node is empty
    if(!first){
      last  = new Node(d);
      first = last;
    }else{
      last->Next = new Node(d);
      last = last -> Next;
    }
  }

  int dequeue(){
    if(first){
      int item = first->val;
      Node *tmp = first;
      first = first -> Next;
      delete tmp;
      return item;
    }

    return -99999999;
  }

 private:
  Node *first;
  Node *last;
}
    
