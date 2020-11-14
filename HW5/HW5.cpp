/*
    Brett Beaulieu
    Computing 3
    HW5
*/

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
    // Addition operator for real and imaginary numbers
    ComplexNumber operator+ (ComplexNumber c2) const {
        return ComplexNumber (this->real+c2.real, this->imag+c2.imag) ;
    }
    // Subtraction operator for real and imaginary numbers
    ComplexNumber operator- (ComplexNumber c2) const {
        return ComplexNumber(this->real-c2.real, this->imag-c2.imag) ;
    }
    // Multiplication operator for real and imaginary numbers
    friend ComplexNumber operator*(ComplexNumber c2, ComplexNumber m2){
        ComplexNumber a;
        a.setReal((c2.getReal()*m2.getReal())-(c2.getImag() * m2.getImag()));
        a.setImag((c2.getReal()*m2.getImag())+(c2.getImag() * m2.getReal()));
        return a;
    }
    // Function to find cojugate of calling object
    ComplexNumber conjugate(ComplexNumber &obj)
    {
        this->imag=obj.imag * (-1);
        return ComplexNumber(this->imag);
    }
    // Insertion operator allowing complex number to be outputted
    friend ostream& operator<< (ostream&, ComplexNumber&);
    // Extraction operator allowing complex number to be outputted
    friend istream& operator>> (istream&, ComplexNumber&);
private:
    double real,imag;   // Real and Imaginary number variables
};

// Insertion operator allowing complex number to be outputted
ostream &operator<< (ostream& out, ComplexNumber& c)
{
    // If both numbers are equal to zero
    if (c.real == 0 && c.imag == 0) {
        out << 0 << endl;
    }
    
    // If only the real number is zero
    if (c.real == 0 && c.imag != 0) {
        out << c.imag << "i" << endl;
    }

    // If only the imaginary number is zero
    if (c.real != 0 && c.imag == 0) {
        out << c.real;
    }

    // If both numbers are not equal to zero
    if (c.imag != 0 && c.real != 0) {
        if (c.imag > 0){
            out << c.real << "+" << c.imag << "i" << endl;
        }
        else{
          out << c.real << c.imag << "i" << endl;
        }
    }
    return out;
}

// Extraction operator allowing complex number to be inputted
istream &operator >> (istream &in, ComplexNumber &c)
{
   cout << "Enter real number: ";
   in >> c.real;
   cout << "Enter imaginary number: ";
   in >> c.imag;
   return in;
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
    
    cout << endl; // Line break for part two
    
    ComplexNumber c5,c6,c7,c8;
    cin >> c5;  // Read in first complex number
    cin >> c6;  // Read in second complex number

    cout << "Inputted first number: " << c5 << endl;
    cout << "Inputted second complex number: " << c6 << endl;
    
    c7 = c5 + c6;   // Add complex numbers
    cout << "c5 + c6 ("<< c5 << " + " << c6 << ") == " << c7 << endl;
    
    c7 = c5 - c6;   // Divide complex numbers
    cout << "c5 - c6 ("<< c5 << " - " << c6 << ") == " << c7 << endl;
    
    c7 = c5 * c6;   // Multiply complex number
    cout << "c5 * c6 ("<< c5 << " * " << c6 << ") == " << c7 << endl;
    
    c8.setReal(3);  // Set real number to 3
    c8.setImag(-5); // Set imaginary number to -5
    cout << "Complex number before conjugate: " << c8 << endl;
    c8.conjugate(c8);   // Find the conjugate and output
    cout << "Complex number after conjugate: " << c8 << endl;
    return 0;
}
