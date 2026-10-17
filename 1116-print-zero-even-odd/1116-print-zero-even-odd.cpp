class ZeroEvenOdd {
private:
    int n;
    mutex m;
    condition_variable cv;
    int counter = 1;
    bool ready = true;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        unique_lock<mutex> lock(m);
        for(int i = 0;i<n;i++){
            cv.wait(lock, [&](){
                return ready == true;
            });

            printNumber(0);
            ready = false;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        unique_lock<mutex> lock(m);
        for(int i = 2;i<=n;i += 2){
            cv.wait(lock, [&](){
                return ready!= true && counter %2 == 0;
            });

            printNumber(counter);
            counter++;
            ready = true;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        unique_lock<mutex> lock(m);
        for(int i = 1;i<=n;i += 2){
            cv.wait(lock, [&](){
                return ready != true && counter %2 == 1;
            });

            printNumber(counter);
            ready = true;
            counter++;
            cv.notify_all();
        }
    }
};