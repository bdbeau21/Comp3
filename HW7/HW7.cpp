#include <iostream>
using namespace std;

/* Class to represent imaginary and real numbers `*/
template <class t>
class ComplexNumber{
public:
    // Default Constructor
    ComplexNumber();
    // Constructor only sets real
    ComplexNumber(t);
    // Constructor sets both parts
    ComplexNumber(t,t);
    // Accessor function for real numbers
    t getReal();
    // Accessor function for imaginary numbers
    t getImag();
    // Mutator function for real numbers
    void setReal(t);
    // Mutator function for imaginary numbers
    void setImag(t);
    // Addition operator for real and imaginary numbers
    template <class u>
    friend ComplexNumber<u> operator+(ComplexNumber<u> c2, ComplexNumber<u> m2);
    // Overloaded Addition operator for real and imaginary numbers
    template <class u>
    friend ComplexNumber<t> operator+(ComplexNumber<u>, t);
    // Overloaded Addition operator for real and imaginary numbers
    template <class u>
    friend ComplexNumber<u> operator+(t, ComplexNumber<u>);
    // Subtraction operator for real and imaginary numbers
    template <class u>
    friend ComplexNumber<u> operator-(ComplexNumber<u>, ComplexNumber<u>);
    // Overloaded Subtraction operator for real and imaginary numbers
    template <class u>
    friend ComplexNumber<u> operator-(ComplexNumber<u>,t);
    // Overloaded Subtraction operator for real and imaginary numbers
    template <class u>
    friend ComplexNumber<u> operator-(t, ComplexNumber<u>);
    // Multiplication operator for real and imaginary numbers
    template <class u>
    friend ComplexNumber<u> operator*(ComplexNumber<u>, ComplexNumber<u>);
    // Overloaded Multiplication operator for real and imaginary numbers
    template <class u>
    friend ComplexNumber<u> operator*(ComplexNumber<u>,t);
    // Overloaded Multiplication operator for real and imaginary numbers
    template <class u>
    friend ComplexNumber<u> operator*(t i, ComplexNumber<u> c2);
    // Division operator for real and imaginary numbers
    template <class u>
    friend ComplexNumber<u> operator/(ComplexNumber<u> c2, ComplexNumber<u> m2);
    // Division operator for real and imaginary numbers
    template <class u>
    friend ComplexNumber<u> operator/(ComplexNumber<u> c2, t);
    // Function to find cojugate of calling object
    ComplexNumber& conjugate();
    // Insertion operator allowing complex number to be outputted
    template<class f>
    friend ostream& operator<< (ostream&, ComplexNumber<f>&);
    // Extraction operator allowing complex number to be outputted
    template<class f>
    friend istream& operator>> (istream&, ComplexNumber<f>&);
private:
    t real,imag;   // Real and Imaginary number variables
};

// Default Constructor
template<class t>
ComplexNumber<t>::ComplexNumber() {
    this->real = 0.0;
    this->imag = 0.0;
}

// Constructor only sets real
template<class t>
ComplexNumber<t>::ComplexNumber(t r) {
    this->real = r;
    this->imag = 0;
}

// Constructor sets both parts
template<class t>
ComplexNumber<t>::ComplexNumber(t r, t i) {
    this->real = r;
    this->imag = i;
}

// Accessor function for real numbers
template<class t>
t ComplexNumber<t>::getReal() {
    return real;
}

// Accessor function for imaginary numbers
template<class t>
t ComplexNumber<t>::getImag() {
    return imag;
}

// Mutator function for real numbers
template<class t>
void ComplexNumber<t>::setReal(t r) {
    real = r;
}

// Mutator function for imaginary numbers
template<class t>
void ComplexNumber<t>::setImag(t i) {
    imag = i;
}

// Addition operator for real and imaginary numbers
template<class t>
ComplexNumber<t> operator+ (ComplexNumber<t> c2, ComplexNumber<t> m2){
    ComplexNumber<t> a;
    a.setReal(c2.getReal() +m2.getReal());
    a.setImag(c2.getImag() +m2.getImag());
    return a;
}

// Overloaded Addition operator for real and imaginary numbers
template<class t>
ComplexNumber<t> operator+ (ComplexNumber<t> c2, t i)
{
    ComplexNumber<t> a;
    a.setReal(c2.getReal() +i);
    a.setImag(c2.getImag());
    return a;
}

// Overloaded Addition operator for real and imaginary numbers
template<class t>
ComplexNumber<t> operator+ (t i, ComplexNumber<t> c2)
{
    ComplexNumber<t> a;
    a.setReal(c2.getReal() +i);
    a.setImag(c2.getImag());
    return a;
}

// Subtraction operator for real and imaginary numbers
template<class t>
ComplexNumber<t> operator- (ComplexNumber<t> c2, ComplexNumber<t> m2){
    ComplexNumber<t> a;
    a.setReal(c2.getReal() -m2.getReal());
    a.setImag(c2.getImag() -m2.getImag());
    return a;
}

// Overloaded Subtraction operator for real and imaginary numbers
template<class t>
ComplexNumber<t> operator- (ComplexNumber<t> c2, t i){
    ComplexNumber<t> a;
    a.setReal(c2.getReal() -i);
    a.setImag(c2.getImag());
    return a;
}

// Overloaded Subtraction operator for real and imaginary numbers
template<class t>
ComplexNumber<t> operator- (t i, ComplexNumber<t> c2){
    ComplexNumber<t> a;
    ComplexNumber<t> b=c2.conjugate(); // Finds the conjugate to subtract complex number
    a.setReal(i - c2.getReal());
    a.setImag(b.getImag());
    return a;
}

// Multiplication operator for real and imaginary numbers
template<class t>
ComplexNumber<t> operator* (ComplexNumber<t> c2, ComplexNumber<t> m2){
    ComplexNumber<t> a;
    a.setReal((c2.getReal()*m2.getReal())-(c2.getImag() * m2.getImag()));
    a.setImag((c2.getReal()*m2.getImag())+(c2.getImag() * m2.getReal()));
    return a;
}

// Overloaded Multiplication operator for real and imaginary numbers
template<class t>
ComplexNumber<t> operator* (ComplexNumber<t> c2, t i){
   ComplexNumber<t> a;
   a.setReal(c2.getReal() *i);
   a.setImag(c2.getImag() *i);
   return a;
}

// Overloaded Multiplication operator for real and imaginary numbers
template<class t>
ComplexNumber<t> operator* (t i, ComplexNumber<t> c2){
  ComplexNumber<t> a;
  a.setReal(c2.getReal() *i);
  a.setImag(c2.getImag() *i);
  return a;
}

// Division operator for real and imaginary numbers
template<class t>
ComplexNumber<t> operator/ (ComplexNumber<t> c2, ComplexNumber<t> m2){
    ComplexNumber<t> a,c,d;
    ComplexNumber<t> b=m2.conjugate(); // Used to find conjugate of function
    c=(c2*b);   // Multiply first complex number by conjugate
    d=(m2*b);   // Multiply second complex number by conjugate

    a.setReal(c.getReal()/d.getReal()); // Divide Top and bottom real numbers
    a.setImag(c.getImag()/d.getReal()); // Divide Imaginary with real
    return a;
}

// Overloaded Division operator for real and imaginary numbers
template<class t>
ComplexNumber<t> operator/ (ComplexNumber<t> c2, t i){
    ComplexNumber<t> a;
    a.setReal(c2.getReal()/i);  // Divide by double
    a.setImag(c2.getImag()/i);  // Divide by double
    return a;
}

// Conjugate Operator
template<class t>
ComplexNumber<t>& ComplexNumber<t>::conjugate() {
    this->imag = -(this->imag);
    return *this;
}

// Insertion operator allowing complex number to be outputted
template<class f> ostream &operator<< (ostream& out, ComplexNumber<f>& c)
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
template<class f>istream &operator >> (istream &in, ComplexNumber<f>& c)
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
    ComplexNumber<int> c1,c3,c5(1,2),d(3,4);
    ComplexNumber<double> m1(2.0),m2(2.0,5.0),m3;
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
    
    // Addition Testing
    cout << "Double Addition: " << endl;
    m3=m1+m2;
    cout << m3 << endl;
    m3=m2+m1;
    cout << m3 << endl;
    return 0;
}
