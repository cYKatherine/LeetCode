// Solution for https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {
private:
    priority_queue<int> maxHeap;
    priority_queue<int, std::vector<int>, std::greater<int> > minHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (maxHeap.empty() || num < maxHeap.top()) maxHeap.push(num);
        else minHeap.push(num);
        
        if (maxHeap.size() != minHeap.size() && maxHeap.size() - minHeap.size() != 1) {
            if (maxHeap.size() > minHeap.size()) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            } else {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
    }
    
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) return (maxHeap.top() + minHeap.top()) / 2.0;
        else return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */