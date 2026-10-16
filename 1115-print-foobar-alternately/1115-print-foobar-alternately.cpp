class FooBar {
private:
    int n;
    mutex m;
    condition_variable cv;
    int ready = 0;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        unique_lock<mutex> lock(m);
        
        for (int i = 0; i < n; i++) {
            cv.wait(lock,[&](){
                return (ready%2 == 0);
            });
            
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            ready++;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        unique_lock<mutex> lock(m);

        for (int i = 0; i < n; i++) {
            cv.wait(lock,[&](){
                return (ready%2 == 1);
            });
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            ready++;
            cv.notify_all();
        }
    }
};