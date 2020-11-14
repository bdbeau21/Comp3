/*
    Brett Beaulieu
    HW2
    Computing 3
*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <cmath>

using namespace std;

// Function outputs the type of triangle taking in three integer triangle side lengths
void triangle(int a, int b, int c);

// Function outputs the type of triangle taking in three double triangle side lengths
void triangle(double a, double b, double c);

int main(int argc, char ** argv){
    int side1, side2, side3;        // 3 integers declared for triangle sides
    double side_1, side_2, side_3;  // 3 doubles delcared for triangle sides
    
    // Error check for correct number of arguments
    if (argc ==3|| argc==4|| argc>5){
        cerr << "Error! Number of command line arguments."<< endl;
        exit(1);
    }
    // No command line arguments integer function used
    else if(argc==1){
        cout << "Enter three triangle side length sizes: ";
        cin >> side1 >> side2 >> side3;
	// Error check side lengths
	if(side1<=0||side2<=0||side3<=0){
	  cerr<< "ERROR! One or more triangle sizes are not positive integers"
	      << endl;
	  exit(1);
	}
        triangle(side1,side2,side3);
    }
    // Checks for double command line call
    else if (strcmp(argv[1], "-d")==0){
        // If there is one command line argument
        if(argc==2){
            cout << "Enter three triangle side length sizes: ";
            cin >> side_1 >> side_2 >> side_3;
        }
        // If there is 4 command line arguments
        else{
	    // Change string to float
	    side_1=atof(argv[2]);
            side_2=atof(argv[3]);
            side_3=atof(argv[4]);
        }
	// Error check side lengths
	if(side_1<=0||side_2<=0||side_3<=0){
	  cerr<< "ERROR! One or more triangle sizes are not positive integers"
	      << endl;
	  exit(1);
	}
	// Call triangle double function
        triangle(side_1,side_2,side_3);
    }
    // All argument conditions
    else{
        // If there is two command line arguments
        if(argc==2){
            cout << "Enter three triangle side length sizes: ";
            cin >> side1 >> side2 >> side3;
        }
	// Converts command line arguments 
        else{
            side1=atoi(argv[2]);
            side2=atoi(argv[3]);
            side3=atoi(argv[4]);
        }
	// Error check side lengths
	if(side1<=0||side2<=0||side3<=0){
	  cerr<< "ERROR! One or more triangle sizes are not positive integers"
	      << endl;
	  exit(1);
	}
	// Call integer triangle function
        triangle(side1,side2,side3);
    }
    return 0;
}

// Function outputs the type of triangle taking in three integer triangle side lengths
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

// Function outputs the type of triangle taking in three double triangle side lengths
void triangle(double a, double b, double c){
    double hold = 0.0;   // Variable used to swap side values
    double temp=0.0;     // Variable used to hold difference
    const double EPSILON = 0.001; // Double to help determine if side lengths are "equal"
    
    // If a is the largest side length
    if(a>=b && a>= c){
        // Swap side values a and c
        temp=a-c;
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

    // Output double with 5 decimal places
    cout << fixed << setprecision(5);
    cout << a << " " << b << " " << c << " ";

    // A is greater than B
    if(a>b){
        temp=fabs(a-b);  // Find difference of a and b
	// Determines if values are close enough to be considered equal
        if(temp<EPSILON){
            a=b;
        }
    }
    // B is greater than A
    if(b>a){
        temp =fabs(b-a);  // Find difference of b and a
	// Determines if values are close enough to be considered equal
        if(temp<EPSILON){
            b=a;
        }
    }
    // C is greater than A
    if(c>a){
        temp=fabs(c-a);  // Find difference of c and a
	// Determines if values are close enough to be considered equal
        if(temp<EPSILON){
            c=a;
        }
    }
    // C is greater than B
    if(c>b){
        temp=fabs(c-b);  // Find difference of a and b
	// Determines if values are close enough to be considered equal
        if(temp<EPSILON){
	  c=a;
        }
    }
    
    // Checks the triangle inequality theorem to make sure sides form a triangle
    if((a>(b+c))||(b>(a+c))||(c>(a+b))){
        cout << "Not a triangle" << endl;
    }
    // If only two sides are the same outputs isoceles triangle
    else if((a==b && a!= c)||(a==c && a!= b) ||(b==c && b!=a)){
        // Uses Pythagorean theorem to determine if triangle is a right triangle
        if((fabs((c*c)-((a*a)+(b*b)))<EPSILON)){
            cout << "Right ";
        }
        cout << "Isosceles triangle" << endl;
    }
    // All sides are different lengths outputting Scalene triangle
    else if(a!=b && a!=c && b!=c){
        // Uses Pythagorean theorem to determine if triangle is a right triangle
        if((fabs((c*c)-((a*a)+(b*b)))<EPSILON)){
            cout << "Right ";
        }
        cout << "Scalene triangle" << endl;
    }
    // Triangle has all equals sides making it an Equilateral triangle
    else if(a==b && b==c){
        cout << "Equilateral triangle"<< endl;
    }
}
