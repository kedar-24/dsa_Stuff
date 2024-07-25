template <typename T, typename V, typename W>

class triplet{
    T x;
    V y;
    W z;

    void setx(T x){
        this->x = x;
    }
    void sety(V y){
        this->y = y;
    }
    void setz(W z){
        this->z = z;
    }

    T getx(){
        return x;
    }
    V gety(){
        return y;
    }
    W getz(){
        return z;
    }
}