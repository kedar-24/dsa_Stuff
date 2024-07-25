#include <iostream>
using namespace std;

template <typename T>
class mapnode{
    public:

    string key;
    T value;
    mapnode* next;

    mapnode(string key, T value){
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~mapnode(){
        delete next;
    }
};

template <typename T>

class ourmap{
    mapnode<T>* *buckets;
    int size;
    int numbuckets;

    public:

    ourmap(){
        count = 0;
        numbuckets = 5;
        buckets = new mapnode<T>*[numbuckets];
        for(int i=0; i<numbuckets; i++){
            buckets[i] = NULL;
        }
    }

    ~ourmap(){
        for(int i=0; i,=<numbuckets; i++){
            delete buckets[i];
        }
        delete [] buckets;
    }

    int size(){
        return count;
    }

    
    private:
    int getbucketindex(string key){
        int hashcode = 0;
        int currentcoeff = 1;
        for(int i = key.length()-1; i>=0; i--){
            hashcode+= key[i] * currentcoeff;
            hashcode % = numbuckets;
            currentcoeff*= 37;
            currentcoeff % = numbuckets; 
        }
        return hashcode % numbuckets;
    }

    public:

    T getValue(string key){
        int bucketindex = getbucketindex(key);
        mapnode<T>* head = buckets[bucketindex];
        while(head != NULL){
            if(head->key == key){
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }

    void insert(string key, T value){
        int bucketindex = getbucketindex(key);
        mapnode<T>* head = buckets[bucketindex];
        while(head != NULL){
            if(head->key == key){
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = buckets[bucketindex];
        mapnode<T>* node = new mapnode(key, value);
        node->next = head;
        buckets[bucketindex] = node;
        count++;
    }

    V remove(string key){
        int bucketindex = getbucketindex(key);
        mapnode<T>* head = buckets[bucketindex];
        mapnode<T>* prev = NULL;
        while(head != NULL){
            if(head->key = key){
                if(prev == NULL){
                    buckets[bucketindex] = head->next;
                }else{
                    prev -> next = head -> next;
                }
                T value = head->value;
                head->next = NULL;
                delete head;
                count--;
                return value;
            }
            prev = head;
            head = head -> next;
        }
        return 0;
    }
};