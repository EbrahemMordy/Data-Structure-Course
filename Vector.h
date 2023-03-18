#ifndef VECTOR
#define VECTOR
using namespace std;
class Vector{
private:
    int *arr{nullptr};
    int size{};
    int cap{};
    void exCap(){
        cap*=2;
        int *b=new int[cap];
        for(int i=0;i<size;i++) b[i]=arr[i];
        swap(b,arr);
        delete[] b;
    };
public:
    Vector(int Size):size(Size){
        if(size==0)
            size=1;
        cap=size*2;
        arr=new int[cap];
    }
    ~Vector(){
        delete[] arr;
        arr= nullptr;
        size=0;
    }
    void push(int x){
        if(size==cap)
            exCap();
        int *b=new int[size+1];
        for(int i=0;i<size;i++)
            b[i]=arr[i];
        b[size]=x;
        swap(arr,b);
        delete[] b;
        b=nullptr;
        size++;
    }
    void pop(){
        if(empty())
            return;
        size--;
    }
    int find(int x){
        for(int i=0;i<size;i++){
            if(arr[i]==x)
                return i;
        }
        return -1;
    }
    void print(){
        for(int i=0;i<size;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    void print_element(int idx){
        cout<<arr[idx-1]<<endl;
    }
    void remove(int idx){
        for(int i=idx;i<size-1;i++){
            arr[i]=arr[i+1];
        }
        pop();
    }
    int Size(){
        return size;
    }
    int Capacity(){
        return cap;
    }
    int front(){
        return arr[0];
    }
    int back(){
        return arr[size-1];
    }
    void clear(){
        size=0;
    }
    int get(int idx){
        return arr[idx];
    }
    void set(int x,int idx){
        arr[idx]=x;
    }
    void insert(int x,int idx){
        if(size==cap)
            exCap();
        int *b=new int[size+1];
        for(int i=0;i<idx;i++)
            b[i]=arr[i];
        b[idx]=x;
        for(int i=idx+1;i<=size;i++)
            b[i]=arr[i-1];
        swap(arr,b);
        delete[] b;
        b=nullptr;
        size++;
    }
    bool empty(){
        if(size==0)
            return true;
        return false;
    }
};
#endif //VECTOR
