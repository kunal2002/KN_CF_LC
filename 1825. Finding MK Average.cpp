// It's a code with story
class MKAverage {
    int m, k;
    multiset<int> lo, mid, hi;
    queue<int> q;
    long long sumMid = 0;
    void moveLotoMid()
    {
        auto it = prev(lo.end());
        int x = *it;
        lo.erase(it);
        sumMid += x;
        mid.insert(x);
    }
    void moveMidtoLo()
    {
        auto it = mid.begin();
        int x = *it;
        mid.erase(it);
        sumMid -= x;
        lo.insert(x);
    }
    void moveHitoMid()
    {
        auto it = hi.begin();
        int x = *it;
        hi.erase(it);
        sumMid += x;
        mid.insert(x);
    }
    void moveMidtoHi()
    {
        auto it = prev(mid.end());
        int x = *it;
        mid.erase(it);
        sumMid -= x;
        hi.insert(x);
    }
    void buildInitial() 
    {
        for (int i = 0; i < k; ++i) 
            moveMidtoLo();
        for (int i = 0; i < k; ++i) 
            moveMidtoHi();
    }
    void rebalanceAll() 
    {
        rebalanceSizes();
        fixOrder();
        // sizes might have shifted during fixOrder, finalize sizes again for safety
        rebalanceSizes();
    }
    void rebalanceSizes()
    {
        //shrink
        while((int)hi.size() > k)
            moveHitoMid();
        while((int)lo.size() > k)
            moveLotoMid();
        //grow
        while((int)lo.size() < k)
        {
            if(!mid.empty())
                moveMidtoLo();
            else
            {
                moveHitoMid();
                moveMidtoLo();
            }
        }
        while((int)hi.size() < k)
        {
            if(!mid.empty())
                moveMidtoHi();
            else
            {
                moveLotoMid();
                moveMidtoHi();
            }
        }
    }
    
    void fixOrder() 
    {
        // lo's max should be <= mid's min
        while (!lo.empty() && !mid.empty() && *prev(lo.end()) > *mid.begin()) 
        {
            int a = *prev(lo.end());
            int b = *mid.begin();
            lo.erase(prev(lo.end()));
            mid.erase(mid.begin());
            lo.insert(b);
            mid.insert(a);
            sumMid += a;
            sumMid -= b;
        }
        // mid's max should be <= hi's min
        while (!mid.empty() && !hi.empty() && *prev(mid.end()) > *hi.begin()) 
        {
            int a = *prev(mid.end());
            int b = *hi.begin();
            mid.erase(prev(mid.end()));
            hi.erase(hi.begin());
            mid.insert(b);
            hi.insert(a);
            sumMid += b;
            sumMid -= a;
        }
    }
public:
    MKAverage(int m, int k) {
        this->m = m;
        this->k = k;
    }
    void addElement(int num) {
        q.push(num);

        // Fill phase: until we reach m, keep everything in mid
        if((int)q.size() <= m) 
        {
            mid.insert(num);
            sumMid += num;
            if ((int)q.size() == m)
                buildInitial(); // Split mid into lo / mid / hi for the first time
            return;
        }
        // Steady-state: we already have m elements before adding this one
        // Place 'num' in the appropriate basket using current borders
        if (!lo.empty() && num <= *prev(lo.end()))
            lo.insert(num);
        else if (!hi.empty() && num >= *hi.begin())
            hi.insert(num);
        else 
        {
            mid.insert(num);
            sumMid += num;
        }

        // Evict the oldest element so window stays at size m
        int old = q.front(); 
        q.pop();
        auto it = lo.find(old);
        if (it != lo.end())
            lo.erase(it);
        else if ((it = hi.find(old)) != hi.end())
            hi.erase(it);
        else 
        {
            it = mid.find(old);
            if(it != mid.end()) 
            {
                sumMid -= old;
                mid.erase(it);
            }
        }

        // Restore sizes and ordering invariants
        rebalanceAll();
    }
    
    int calculateMKAverage() {
        if((int)q.size() < m)
            return -1;
        int denom = (m - 2 * k);
        return (int)(sumMid * 1.0 / denom);
    }
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */
