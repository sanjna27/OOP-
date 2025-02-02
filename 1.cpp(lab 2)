#include<iostream>
using namespace std;

int main(int argc,char *argv[]){
       int sum=0;
       int n;
       cout<<"Enter the size of an array: ";
       cin>>n;
        int arr[n];
       int *ptr=arr;
       cout<<"Enter the elements of array: ";
       for(int i=0;i<n;i++){
           cin>>*(ptr+i);
           sum+=*(ptr+i);
       }
       cout<<"Array: ";
       for(int i=0;i<n;i++){
           cout<<*(ptr+i)<< " ";
       }
       cout<<endl;

       cout<<"The sum of elements of array is: "<< sum<<endl;

    return 0;
}
