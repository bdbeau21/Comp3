#include <iostream>
using namespace std;

/* Class to represent imaginary and real numbers `*/
class ComplexNumber{
public:
    // Default Constructor
    ComplexNumber() : real(0.0), imag(0.0) {}
    // Constructor only sets real
    ComplexNumber(double r) : real(r), imag(0.0){}
    // Constructor sets both parts
    ComplexNumber(double r, double i) : real(r), imag(i){}
    // Accessor function for real numbers
    double getReal(){ return real;}
    // Accessor function for imaginary numbers
    double getImag(){return imag;}
    // Mutator function for real numbers
    void setReal(double r){real=r;}
    // Mutator function for imaginary numbers
    void setImag(double i){imag=i;}
    // Insertion operator allowing complex number to be outputted
    friend ostream& operator<< (ostream&, ComplexNumber&) ;
private:
    double real,imag;   // Real and Imaginary number variables
};

// Insertion operator allowing complex number to be outputted
ostream &operator<< (ostream& out, ComplexNumber& c)
{
    out << c.real;
    
    // If imaginary number is negative
    if(c.imag<0){
        out<< c.imag << "i" << endl;
    }
    // Imaginary number is positive or zero
    else{
        out << "+" << c.imag << "i" ;
    }
    return out;
}

int main(int argc, char *argv[])
{
    ComplexNumber c1, c2(-2.0), c3(1.0, -4.0), c4;
    cout << "Testing Default Constructor: " << c1 << endl;
    cout << "Testing constructor that allows only real part to be set: " << c2 << endl;
    cout << "Testing constructor that allows both parts to be set: " <<c3 << endl;
    
    cout << "Default Constructor: " << c4 << endl;
    c4.setReal(3);
    c4.setImag(-5);
    
    cout << "Testing set and get functions: " << c4.getReal() << c4.getImag() << "i"
         << endl;
    return 0;
}
