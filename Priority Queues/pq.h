#include <vector>
using namespace std;

class PriorityQueue{
    private:

    vector<int> pq;

    void swap(int a, int b){
        int temp = pq[a];
        pq[a] = pq[b];
        pq[b] = temp;
    }

    public:

    PriorityQueue(){

    }

    bool isEmpty(){
        return pq.size()==0;
    }

    int getSize(){
        return pq.size();
    }

    int getMin(){
        if(isEmpty()){
            return 0;
        }
        return pq[0];
    }

    void insert(int element){
        pq.push_back(element);
        int childindex = pq.size() - 1;
        while(childindex > 0){
            int parentindex = (childindex -1 )/2;
            if(pq[parentindex] > pq[childindex]){
                swap(parentindex, childindex);
            }
            else{
                break;
            }
            childindex = parentindex;
        }
    }

    int remove(){
        if(isEmpty()){
            return 0;
        }
        int output = pq[0];
        pq[0] = pq[pq.size()-1];
        pq.pop_back();
        int parentindex = 0;
        int lc = 2*(parentindex)+1;
        int rc = 2*(parentindex)+2;
        while(lc < pq.size()){
            if(pq[parentindex] > pq[lc]){
                swap(parentindex, lc);
                parentindex = lc;
            }
            if(rc < pq.size() && pq[parentindex] > pq[rc]){
                swap(parentindex, rc);
                parentindex = rc;
            }else{
                break;
            }
            lc = 2*(parentindex)+1;
            rc = 2*(parentindex)+2;
        }
        return output;

    }
};