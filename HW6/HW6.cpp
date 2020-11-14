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
    friend ComplexNumber operator+(ComplexNumber c2, ComplexNumber m2){
        ComplexNumber a;
        a.setReal(c2.getReal() +m2.getReal());
        a.setImag(c2.getImag() +m2.getImag());
        return a;
    }
    // Overloaded Addition operator for real and imaginary numbers
    friend ComplexNumber operator+(ComplexNumber c2, double i){
        ComplexNumber a;
        a.setReal(c2.getReal() +i);
        a.setImag(c2.getImag());
        return a;
    }
    // Overloaded Addition operator for real and imaginary numbers
    friend ComplexNumber operator+(double i, ComplexNumber c2){
        ComplexNumber a;
        a.setReal(c2.getReal() + i);
        a.setImag(c2.getImag());
        return a;
    }
    // Subtraction operator for real and imaginary numbers
    friend ComplexNumber operator-(ComplexNumber c2, ComplexNumber m2){
        ComplexNumber a;
        a.setReal(c2.getReal() -m2.getReal());
        a.setImag(c2.getImag() -m2.getImag());
        return a;
    }
    // Overloaded Subtraction operator for real and imaginary numbers
    friend ComplexNumber operator-(ComplexNumber c2,double i){
        ComplexNumber a;
        a.setReal(c2.getReal() -i);
        a.setImag(c2.getImag());
        return a;
    }
    // Overloaded Subtraction operator for real and imaginary numbers
    friend ComplexNumber operator-(double i, ComplexNumber c2)  {
        ComplexNumber a;
        ComplexNumber b=c2.conjugate(); // Finds the conjugate to subtract complex number
        a.setReal(i - c2.getReal());
        a.setImag(b.getImag());
        return a;
    }
    // Multiplication operator for real and imaginary numbers
    friend ComplexNumber operator*(ComplexNumber c2, ComplexNumber m2){
        ComplexNumber a;
        a.setReal((c2.getReal()*m2.getReal())-(c2.getImag() * m2.getImag()));
        a.setImag((c2.getReal()*m2.getImag())+(c2.getImag() * m2.getReal()));
        return a;
    }
    // Overloaded Multiplication operator for real and imaginary numbers
    friend ComplexNumber operator*(ComplexNumber c2,double i)  {
        ComplexNumber a;
        a.setReal(c2.getReal() *i);
        a.setImag(c2.getImag() *i);
        return a;
    }
    // Overloaded Multiplication operator for real and imaginary numbers
    friend ComplexNumber operator*(double i, ComplexNumber c2)  {
        ComplexNumber a;
        a.setReal(c2.getReal() *i);
        a.setImag(c2.getImag() *i);
        return a;
    }
    // Division operator for real and imaginary numbers
    friend ComplexNumber operator/(ComplexNumber c2, ComplexNumber m2)  {
        ComplexNumber a,c,d;
        ComplexNumber b=m2.conjugate(); // Used to find conjugate of function
        c=(c2*b);   // Multiply first complex number by conjugate
        d=(m2*b);   // Multiply second complex number by conjugate

        a.setReal(c.getReal()/d.getReal()); // Divide Top and bottom real numbers
        a.setImag(c.getImag()/d.getReal()); // Divide Imaginary with real
        return a;
    }
    // Division operator for real and imaginary numbers
    friend ComplexNumber operator/(ComplexNumber c2, double i)  {
        ComplexNumber a;
        a.setReal(c2.getReal()/i);  // Divide by double
        a.setImag(c2.getImag()/i);  // Divide by double
        return a;
    }
    // Function to find cojugate of calling object
    ComplexNumber conjugate()
    {
        ComplexNumber tmp;
        tmp.real=this->real;
        tmp.imag=this->imag * -1;
        return tmp;
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
    int a;
    // Helps format of input extraction operator
    cout << "Choose an option for input: " << endl;
    cout << "1 - both real and imaginary number" << endl;
    cout << "2 - only the real part" << endl;
    cout << "3 - only the imaginary part" << endl;
    cout << "Your option: " << endl;
    in >> skipws >>a;
    
    // While integer is valid
    while (a>3 || a<1){
        cout<< "Invalid number. Reinput: " << endl;
        in >> skipws >>a;
    }
    
    // Switch statement to accept all cases of complex numbers
    switch(a){
        // Input both real and imaginary numbers
        case 1:
            cout << "Enter real number: ";
            in >> skipws >> c.real >> skipws;
            cout << "Enter imaginary number: ";
            in >> skipws >> c.imag >> skipws;
            break;
        // Input just real numbers
        case 2:
            cout << "Enter real number: ";
            in >> skipws >> c.real >> skipws;
            c.imag =0.0;
            break;
        // Input just imaginary numbers
        case 3:
            c.real =0.0;
            cout << "Enter imaginary number: ";
            in >> skipws >> c.imag >> skipws;
            break;
        // Garbage case
        default:
            break;
    }
    return in;
}

int main(int argc, char *argv[])
{
    ComplexNumber c1,c3,c5(1.0,2.0);
    double d=4.0;
    cin >> c1;
    
    // Addition Testing
    cout << "Addition: " << endl;
    c3=c1+c5;
    cout << c3 << endl;
    c3=c1+d;
    cout << c3 << endl;
    c3=d+c1;
    cout << c3 << endl;
    
    // Subtraction Testing
    cout << "Subtraction: " << endl;
    c3=c1-c5;
    cout << c3 << endl;
    c3=c1-d;
    cout << c3 << endl;
    c3=d-c1;
    cout << c3 << endl;
    
    // Multiplication Testing
    cout << "Multiplication: " << endl;
    c3=c1*c5;
    cout << c3 << endl;
    c3=c1*d;
    cout << c3 << endl;
    c3=d*c1;
    cout << c3 << endl;
    
    // Division Testing
    cout << "Division: " << endl;
    c3=c1/c5;
    cout << c3 << endl;
    c3=c1/d;
    cout << c3 << endl;
    return 0;
}
