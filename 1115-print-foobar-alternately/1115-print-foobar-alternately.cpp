class FooBar {
private:
    std::condition_variable cv;
    std::mutex m;
    int n;
    bool turn = true;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(m);
            cv.wait(lock,[&]{
                return turn;
            });
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            turn = false;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(m);
            cv.wait(lock,[&]{
                return !turn;
            });
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            turn = true;
            cv.notify_all();
        }
    }
};