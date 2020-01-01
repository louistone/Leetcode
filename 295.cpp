//Author: Tong Xu
//Date: 12/31/2019

// This code will time limit exceeded

// Catch: using multiset to handle duplicate number


class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        count = 0;
    }

    void addNum(int num) {
        numSet.insert(num);
        count++;
    }

    double findMedian() {
        double res;
        int index = 0, leftVal, rightVal;

        for(auto it = numSet.begin(); it != numSet.end(); it++) {
            if(index == (count-1)/2) {
                leftVal = *it;
            }

            if(index == (count-1)/2 + 1) {
                rightVal = *it;
            }

            index++;
        }

        if(count%2) return (double)leftVal;
        return ((double)leftVal+(double)rightVal)/2.0;
    }

private:
    multiset<int> numSet;
    int count;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
