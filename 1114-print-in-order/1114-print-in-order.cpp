class Foo {
public:
    mutex m;
    condition_variable cv;
    int ready = 0;
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        unique_lock<mutex> lock(m);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        ready = 1;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(m);
        cv.wait(lock, [&](){
            return ready == 1;
        });

        printSecond();
        ready = 2;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        // printThird() outputs "third". Do not change or remove this line.
        unique_lock<mutex> lock(m);
        cv.wait(lock, [&](){
            return ready == 2;
        });
        printThird();
    }
};