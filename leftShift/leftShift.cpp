#include<iostream>
using namespace std;

class leftShift{
    private:
        int *head;
        int array_length;
        int shift_num;
    public:
        leftShift(int *head, int array_length, int shift_num){
            this->head = head;
            this->array_length = array_length;
            this->shift_num = shift_num;
        }

        void allocateM(){
            int aux[shift_num];
            for(int i=0; i<shift_num; i++){
                aux[i] = *(head+i);
            }
            for(int i=shift_num; i<array_length; i++){
                *(head+i-shift_num) = *(head+i);
            }
            for(int i=array_length-shift_num; i<array_length; i++){
                *(head+i) = aux[i-array_length+shift_num];
            }
        }

        void allocate1(){
            int counter = 0;
            int begin_index = 0;
            // loop until all the elements have been moved
            while(counter < array_length){
                // first element to move of current iteration
                int first_element = *(head + begin_index);
                int swap_index_pre = begin_index;
                int swap_index_next = (begin_index + shift_num) % array_length;
                while(swap_index_next != begin_index){
                    *(head + swap_index_pre) = *(head + swap_index_next);
                    swap_index_pre = swap_index_next;
                    swap_index_next = (swap_index_next + shift_num) % array_length;
                    counter++;
                }
                // move the first element to the last index
                *(head + swap_index_pre) = first_element;
                counter++;
                begin_index++;
            }
        }

        void swapRecursion(){
            swapRecursion(0, shift_num-1, array_length-1);
        }
        void swapRecursion(int left, int mid, int right){
            int len_left = mid - left + 1;
            int len_right = right - mid;
            if(len_left == len_right){
                swap(left, mid, mid+1, right);
            }else if(len_left < len_right){
                int tmp = right - (mid - left);
                swap(left, mid, tmp, right);
                swapRecursion(left, mid, tmp-1);
            }else{
                int tmp = left + (right - mid) - 1;
                swap(left, tmp, mid+1, right);
                swapRecursion(tmp+1, mid, right);
            }
        }

        void reverse3(){
            int left = 0;
            int mid = shift_num - 1;
            int right = array_length - 1;
            reverse(left, mid);
            reverse(mid+1, right);
            reverse(left, right);
        }

        // no overlap
        void swap(int left1, int right1, int left2, int right2){
            if(right1-left1 != right2-left2 || left2 <= right1){
                cout<<"do nothing"<<endl;
                return;
            }
            for(int i=0; i<right1-left1+1; i++){
                int tmp = *(head + left1 + i);
                *(head + left1 + i) = *(head + left2 + i);
                *(head + left2 + i) = tmp;
            }
        }

        void reverse(int begin, int end){
            if(begin >= end) {
                cout<<"do nothing"<<endl;
                return;
            }

            for(int i=begin, j=end;i<j; i++,j--){
                int tmp = *(head + i);
                *(head + i) = *(head +j);
                *(head + j) = tmp;
            }
        }

        void print(){
            for(int i=0; i<array_length; i++){
                cout<<*(head + i)<<" ";
            }
            cout<<endl;
        }
};
