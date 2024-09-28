class MyCircularDeque {
    vector<int> arr;
    int front;
    int rear;
    int count;
    int k;
public:
    MyCircularDeque(int k) {
        this -> k = k;
        arr.resize(k);
        front = 1;
        rear = 0;
        count = 0;
    }
    
    bool insertFront(int value) {
        if(this -> isFull()) return false;        
        front = (front - 1 + k) % k;
        arr[front] = value;
        count++;
        return true;
    }
    
    bool insertLast(int value) {
        if(this -> isFull()) return false;
        rear = (rear + 1) % k;
        arr[rear] = value;
        count++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        arr[front] = -1;
        front = (front + 1) % k;
        count--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        arr[rear] = -1;
        rear = (rear - 1 + k) % k;
        count--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return arr[front];
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == k;
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