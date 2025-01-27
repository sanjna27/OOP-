//c++ code to calculate sum of elements of array using pointer
#include<iostream>
using namespace std;

int main(int argc,char *argv[]){
     int n;
    int array[n];
    int *ptr=array;
    int sum=0;
    cout<<"Enter the size of array:";
    cin>>n;
    cout<<"Enter elements of array:"<<endl;
    for(int i=0;i<n;i++){
        cin>>*(ptr+i);
        sum += *(ptr+i);
    }
    cout<<"The sum of all the elements of an array is: "<<sum<<endl;
}
