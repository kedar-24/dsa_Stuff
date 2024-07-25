#include <iostream>
using namespace std;

void swap(int *input, int a, int b){
    int temp = input[a];
    input[a] = input[b];
    input[b] = temp;
}
void inplaceHeapsort(int input[], int n){
    // building heap.
    for(int i=1; i<n; i++){
        int childindex = i;
        while(childindex > 0){
            int parentindex = (childindex - 1 )/2;
            if(input[parentindex] > input[childindex]){
                //swap
                int temp = input[parentindex];
                input[parentindex] = input[childindex];
                input[childindex] = temp;
            }
            else{
                break;
            }
            childindex = parentindex;
        }
    }
    // remove elements.
    int size = n;
    while(size > 1){
        int t = input[0];
        input[0] = input[size-1];
        input[size-1] = t;

        size--;

        int parentindex = 0;
        int lc = 2*(parentindex)+1;
        int rc = 2*(parentindex)+2;
        while(lc < size){
            if(input[parentindex] > input[lc]){
                swap(input, parentindex, lc);
                parentindex = lc;
            }
            if(rc < size && input[parentindex] > input[rc]){
                swap(input, parentindex, rc);
                parentindex = rc;
            }else{
                break;
            }
            lc = 2*(parentindex)+1;
            rc = 2*(parentindex)+2;
        }
    }
}

int main(){
    int input[] = {5, 1, 2, 0, 8};
    inplaceHeapsort(input, 5);

    for(int i = 0; i<5; i++){
        cout<<input[i]<<" ";
    }
}

/*while(lc < size){
            int minindex = parentindex;
            if(input[minindex] > input[lc]){
                minindex = lc;
            }
            if(rc < size && input[minindex] > input[rc]){
                minindex = rc;
            }
            if(minindex == parentindex){
                break;
            }
            int temp = input[parentindex];
            input[parentindex] = input[minindex];
            input[minindex] = temp;
            parentindex = minindex;
            lc = 2*(parentindex)+1;
            rc = 2*(parentindex)+2;*/