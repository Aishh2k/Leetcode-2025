class H2O {
public:
    int water;
    std::mutex m;
    std::condition_variable cv;
    H2O() {
        water = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        std::unique_lock<std::mutex> lock(m);

        cv.wait(lock, [&]{
            return (water < 2);
        });

        water++;
        releaseHydrogen();
        if(water == 2){
            cv.notify_all();      
        }  
    }

    void oxygen(function<void()> releaseOxygen) {
        std::unique_lock<std::mutex> lock(m);

        cv.wait(lock, [&]{
            return (water == 2);
        });

        water = 0;
        releaseOxygen();
        cv.notify_all();   
    }
};