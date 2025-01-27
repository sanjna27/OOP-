//c++ code to find secong highest element of array using pointer
#include<iostream>
using namespace std;

int main(int argc, char *argv[]){
	float array[20];
	float max1=0; //max1 is highest element
	float max2=0; //max2 is second highest element
	cout<<"Enter 20 elements of array:"<<endl;
	float *ptr=array;
	for(int i=0;i<20;i++){
		cin>>*(ptr+i);
	}
	for(int i=0;i<20;i++){
		if(*(ptr+i)>max1){
			max2=max1;
			max1=*(ptr+i);
		}else if ((*(ptr+i)!=max1) && (max2<*(ptr+i))){
			max2=*(ptr+i);
		}
	}
	cout<<"The second highest element of array is: "<<max2<<endl;
}