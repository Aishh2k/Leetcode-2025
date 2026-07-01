class MyCircularQueue {
public:
    int K;
    int curSize;
    int front;
    int rear;
    vector<int> dcq;
    MyCircularQueue(int k) {
        K=k;
        front = 0;
        rear = k-1;
        curSize = 0;
        dcq.resize(K);
    }
    
    bool enQueue(int value) {
        if(curSize == K){
            return false;
        }else{
            curSize++;
            rear = (rear + 1) % K;
            dcq[rear] = value;
            return true;
        }
    }
    
    bool deQueue() {
        if(curSize == 0){
            return false;
        }else{
            front = (front +1)%K;
            curSize--;
            return true;
        }
    }
    
    int Front() {
        if(curSize == 0){
            return -1;
        }else{
            return dcq[front];
        }
    }
    
    int Rear() {
        if(curSize == 0){
            return -1;
        }else{
            return dcq[rear];
        }
    }
    
    bool isEmpty() {
        if(curSize==0){
            return true;
        }else{
            return false;
        }
    }
    
    bool isFull() {
        if(curSize==K){
            return true;
        }else{
            return false;
        }
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */