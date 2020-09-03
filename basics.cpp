
#include <iostream>
using namespace std;

int hello_world()
{
  std::cout << "Hello World!";
  return 0;
}


int pow(int base, int expo){
    int x = base;
    if (expo ==0)
    { 
        return 1;
    }
 else if (y < 0){
        cout<<"exponent cant be negative value "<<endl;
        return -1;
    }
    else{
        for(int i = 1; i < expo; i++){
            x *= base;
        }
        return x;
    }
}

float sine(float o, float h){
    float x = o / h;
    return x;
}

float avg(int array[], int size) {
    int i, sum = 0;       
    for (i = 0; i < size; ++i)
     {
         sum += array[i];
      }
     return float(sum) / size;
}


int main() {
// Functions calls
  int b, int ex; 
  int arr[6] = {1, 2, 3, 7, 9, 5};
  float m;
  
  cout<<"Enter base: "<<endl;
  cin>>b
   cout<<"Enter exponent: "<<endl;
  cin>>ex
  int x = pow(b,ex);
  if (x =! -1)
       cout<<"The power value  is "<< x<<endl;

  cout<<"Enter hypotenuse length: "<<endl;
  cin>>b
   cout<<"Enter opposite length : "<<endl;
  cin>>ex

  float s = sine(ex,b);
  cout<<"The sine value  is "<< s<< endl;
  
  m = getAverage( arr, 6 ) ;
  cout << "Average value is: " << m << endl; 
  return 0;
}
