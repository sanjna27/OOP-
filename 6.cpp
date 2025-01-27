//c++ code to calculate average
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main(int argc,char* argv[]){
   string name;
   float marks[5];
   float average;
   float sum=0;
   cout<<"Enter name of student: ";
   getline(cin, name);
   cout<<"Enter scores of 5 tests of student: ";
   for(int i=0;i<5;i++){
    cin>>marks[i];
    sum += marks[i];
   }
   average=sum/5;
   cout<<"Student Name: "<< name <<endl;
   cout<<"Test scores: ";
    for(int i=0;i<5;i++){
       printf("%.2f ",marks[i]);
    }
   printf("\nAverage test score: %.2f",average);

}