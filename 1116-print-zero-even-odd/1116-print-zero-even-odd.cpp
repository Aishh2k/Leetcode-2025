class ZeroEvenOdd {
private:
    int n;
    std::mutex m;
    std::condition_variable cv;
    int turn;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        turn = 0;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for(int i =1;i<=n;i++){
            std::unique_lock<std::mutex> lock(m);
            cv.wait(lock, [&]{
                return turn == 0;
            });
            printNumber(0);
            if(i%2 == 1){
                turn = 1; //odd
            }else{
                turn = 2; // even
            }
            cv.notify_all();
        }
        
    }

    void odd(function<void(int)> printNumber) {
        for(int i =1;i<=n;i+=2){
            std::unique_lock<std::mutex> lock(m);
            cv.wait(lock, [&]{
                return turn == 1;
            });
            printNumber(i);
            turn = 0;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for(int i =2;i<=n;i += 2){
            std::unique_lock<std::mutex> lock(m);
            cv.wait(lock, [&]{
                return turn == 2;
            });
            printNumber(i);
            turn = 0;
            cv.notify_all();
        }
    }
};