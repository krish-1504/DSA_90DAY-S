class MyCircularQueue {
    int size;
    int *arr;
    int qfront;
    int qrear;
public:
    MyCircularQueue(int k) {
        arr = new int[k];
        qfront = -1;
        qrear = -1;
        size = k;
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }
        if(qfront == -1){
            qfront = 0;
        }
        qrear = (qrear+1) % size;
        arr[qrear] = value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()){
            return false;
        }
        if(qfront == qrear){
            qfront = -1;
            qrear = -1;
        }
        else{
            qfront = (qfront+1)%size;
        }
        return true;
    }
    
    int Front() {
        if(qfront == -1){
            return -1;
        }
        return arr[qfront];
    }
    
    int Rear() {
        if(qrear == -1){
            return -1;
        }
        return arr[qrear];
    }
    
    bool isEmpty() {
        if(qrear == -1){
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if(qrear == size-1 && qfront == 0){
            return true;
        }
        if(qrear == qfront-1){
            return true;
        }
        return false;
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