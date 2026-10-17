class FizzBuzz {
private:
    int n;
    mutex m;
    condition_variable cv;
    int counter = 1;


public:
    FizzBuzz(int n) {
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        unique_lock<mutex> lock(m);
        while(counter <=n){
            cv.wait(lock, [&](){
                return counter > n || (counter %3 == 0 && counter %5 != 0);
            });
            if(counter > n ){
                break;
            }
            counter++;
            printFizz();
            cv.notify_all();
        }
        
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        unique_lock<mutex> lock(m);
        while(counter <=n){
            cv.wait(lock, [&](){
                return counter > n || (counter %3 != 0 && counter %5 == 0);
            });
            if(counter > n ){
                break;
            }
            counter++;
            printBuzz();
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        unique_lock<mutex> lock(m);
        while(counter <=n){
            cv.wait(lock, [&](){
                return counter >n || (counter %3 == 0 && counter %5 == 0);
            });
            if(counter > n ){
                break;
            }
            counter++;
            printFizzBuzz();
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        unique_lock<mutex> lock(m);
        while(counter <=n){
            cv.wait(lock, [&](){
                return counter > n || (counter %3 != 0 && counter %5 != 0);
            });
            if(counter > n ){
                break;
            }
            printNumber(counter);
            counter++;
            cv.notify_all();
        }
        
    }
};