#include "leftShift.cpp"
#include "ctime"
int main(){
    srand((unsigned)time(0));
    int MAX_LENGTH = 100000;
    int MAX_ITERATION = 10000;
    int a[MAX_LENGTH];
    for(int i=0; i<MAX_LENGTH; i++){
        a[i] = rand();
    }
    leftShift lf = leftShift(a, MAX_LENGTH, MAX_LENGTH/100);
    clock_t begin = clock();
    for(int i=0; i<MAX_ITERATION; i++){
        lf.allocateM();
    }
    clock_t end = clock();
    double time_seconds = (end - begin) / (double) CLOCKS_PER_SEC;
    cout<<"time: "<<time_seconds<<endl;
};
