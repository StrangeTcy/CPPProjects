#include <iostream> 
#include <string> 

using namespace std;

int main() 
{ 
   int n;
   bool isPrime = true;
   cout<<"Enter the number:\n"; 
   cin>>n;
   for(int i = 2; i < n-1; ++i)
    isPrime&=(n%i!=0);
  isPrime ? cout << "Prime" : cout << "Not Prime";
    
} 



