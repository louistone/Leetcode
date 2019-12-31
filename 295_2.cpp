// Author: Tong Xu
// Date: 12/31/2019
// New solution using multiset iterator
// Didn't do it bug-free and my original code caused 2 bugs which I have made note in the comments

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if(numSet.empty()) {
            l = r = numSet.insert(num);
            return; // forget this line of code
        }

        numSet.insert(num);
        if(numSet.size() & 1) {
            if(num >= *r) l = r;
            else l = --r; // move r, assign value to l
            //if(num >= *r) ++l;
            //else --r; my orignal code only handles the newly inserted num are on both edges
        }
        else {
            if(num >= *r) ++r;
            else --l;
        }
    }

    double findMedian() {
        return (double)(*l+*r)/2.0;
    }

private:
    multiset<int> numSet;
    multiset<int>::iterator l;
    multiset<int>::iterator r;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
