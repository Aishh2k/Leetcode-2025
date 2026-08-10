class DiningPhilosophers {
public:
    std::mutex m;
    std:: condition_variable cv;
    bool fork[5] = {false, false, false, false, false};
    
    DiningPhilosophers() {
        
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {


		int left = philosopher;
        int right = (left +1) % 5;
        /* 
            P0 → forks 0,1
            P1 → forks 1,2
            P2 → forks 2,3
            P3 → forks 3,4
            P4 → forks 4,0      
        */

        std::unique_lock<std::mutex> lock(m);
        cv.wait(lock, [&]{
            return(!fork[left] && !fork[right]);
        });

        fork[left] = true;
        fork[right] = true;

        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();

        fork[left] = false;
        fork[right] = false;

        cv.notify_all();
    }
};