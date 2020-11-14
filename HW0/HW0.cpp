#include <iostream>
using namespace std;

int main(int argc, const char * argv[])
{
  cout << "Hello, World!" << endl; // Output message to screen
    
  // Iterates through and outputs command line arguments
  for (int i = 0; i < argc; i++){
    cout << "argv[" << i << "] = '" << argv[i] << "'" << endl;
  } 
    return 0;
} 
