#include <iostream>
#include <cstdlib>

using namespace std;

// Function outputs the type of triangle taking in three triangle side lengths
void triangle(int a, int b, int c);

int main(int argc, char ** argv){
    int side1, side2, side3;        // 3 integers declared for triangle side
    
    // Error check for correct number of arguments
    if (argc ==2|| argc==3|| argc>4){
        cerr << "Error! Number of command line arguments."<< endl;
        exit(1);
    }
    // If there is one command line argument to run program
    else if(argc==1){
        cout << "Enter three triangle side length sizes: ";
        cin >> side1 >> side2 >> side3;
    }
    // There is three command line arguments following run program command
    else{
        // converts arguments from string to int
        side1=atoi(argv[1]);
        side2=atoi(argv[2]);
        side3=atoi(argv[3]);
    }
    
    // If triangle side is not a positive integer
    if(side1<=0||side2<=0||side3<=0){
        cerr<< "ERROR! One or more triangle sizes are not positive integers" << endl;
        exit(1);
    }
    triangle(side1, side2, side3);
    return 0;
}

// Function outputs the type of triangle taking in three triangle side lengths
void triangle(int a, int b, int c){
    int hold;   // Variable used to swap side values
    
    // If a is the largest side length
    if(a>=b && a>= c){
        // Swap side values a and c
        hold= a;
        a=c;
        c=hold;
    }
    // If b is the largest side length
    else if(b>=a && b >= c){
        // Swap sides values b and c
        hold =b;
        b=c;
        c=hold;
    }
    
    cout << a << " " << b << " " << c << " ";
    
    // Checks the triangle inequality theorem to make sure sides form a triangle
    if((a>(b+c))||(b>(a+c))||(c>(a+b))){
        cout << "Not a triangle" << endl;
    }
    // If only two sides are the same outputs isoceles triangle
    else if((a==b && a!= c)||(a==c && a!= b) ||(b==c && b!=a)){
        // Uses Pythagorean theorem to determine if triangle is a right triangle
        if((c*c)==(a*a)+(b*b)){
            cout << "Right ";
        }
        cout << "Isosceles triangle" << endl;
    }
    // All sides are different lengths outputting Scalene triangle
    else if(a!=b && a!=c && b!=c){
        // Uses Pythagorean theorem to determine if triangle is a right triangle
        if((c*c)==((a*a)+(b*b))){
            cout << "Right ";
        }
        cout << "Scalene triangle" << endl;
    }
    // Triangle has all equals sides making it an Equilateral triangle
    else if(a==b && b==c){
        cout << "Equilateral triangle"<< endl;
    }
}
