class MyCircularDeque {
public:
//dharmik
        int cap;
        int Front=-1;
        int Last=-1;
        int size=0;
         vector<int> a;
    int mod(int k, int n)
    {
        return ((k %= n) < 0) ? k+n : k;
    }

    MyCircularDeque(int k) {
       a.resize(k);
       cap=k;
    }
    
    bool insertFront(int value) {
        if(Last==-1 && Front==-1){
            Last++;
            Front++;
            a[Last]=value;
        }
        if(size==cap){
            return false;
        }
        Front=mod(Last-size,cap);
        size++;
        a[Front]=value;
        return true;
    }
    
    bool insertLast(int value) {
        if(Last==-1 && Front==-1){
            Last++;
            Front++;
            a[Last]=value;
        }
         if(size==cap){
            return false;
        }
        Last=mod(Front+size,cap);
        size++;
        a[Last]=value;
        return true;
    }
    
    bool deleteFront() {

        if(Front ==-1 && Last==-1 ){
            return false;
        }
        if(Front==Last){
            Front =-1;
            Last=-1;
            size--;
            return true;
        }
        Front=mod(Front+1,cap);
        size--;
        return true;
    }
    
    bool deleteLast() {
          if(Front ==-1 && Last==-1 ){
            return false;
        }
        if(Front==Last){
            Front =-1;
            Last=-1;
            size--;
            return true;
        }
        Last=mod(Last-1,cap);
        size--;
        return true;
    }
    
    int getFront() {
        if(Front==-1){
            return -1;
        }
        return a[Front];
    }
    
    int getRear() {
          if(Last==-1){
            return -1;
        }
        return a[Last];
    }
    
    bool isEmpty() {
        if(Front==-1 && Last==-1){
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if(size==cap){
           return true;
        }
        return false;
    }
};
