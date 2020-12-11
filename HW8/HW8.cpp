#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

class RationalNumber
{
    public:
        // Default constructor
        RationalNumber(){
            this->numerator = 0;
            this->denominator = 1;
        }
        // One argument constructor
        RationalNumber(long num){
            this->numerator = num;
            this->denominator = 1;
        }
        // Two arguement constructor
        RationalNumber(long num, long den){
            // Try for denominator
            try{
                this->numerator = num;
                this->denominator = den;
               
                // If the denominator is negative
                if( this->denominator < 0 )
                {
                    this->denominator *= -1;
                    this->numerator *= -1;
                }
                // If the denominator is equal to zero
                else if(this->denominator ==0){
                    throw(this->denominator);
                }
            }
            // Catch statement if the denominator is zero
            catch(long &a){
                cout << "Denominator cannot equal zero!";
                exit(-1);
            }
        }
        // Return the Numerator
        long getNumerator(){
            return this->numerator;
        }
        // Return the Denominator
        long getDenominator(){
            return this->denominator;
        }
        // Function to reduce a fraction
        void reduce(){
            this->numerator /= this->gcd(this->numerator, this->denominator);
            this->denominator /= this->gcd(this->numerator, this->denominator);
        }
        // Function to find the greatest common divisor
        long gcd(long x, long y){
            // If remainder of both numbers is equal to zero
            if( x % y == 0 ){
                return y;
            }
            // Else use recursion to find the gcd
            else{
                return this->gcd(y, x % y);
            }
        }
        // Addition operator
        RationalNumber operator+(RationalNumber &a){
            // Calculate the numerator
            long num = this->numerator * a.getDenominator() + a.getNumerator() * this->denominator;

            // Calculate the denominator
            long den = this->denominator * a.getDenominator();

            // Call initialization constructor
            RationalNumber b(num, den);
            
            // Reduce rational number
            b.reduce();
            
            return b;
        }
        // Subtraction operator
        RationalNumber operator-(RationalNumber &a){
            // Calculate the numerator
            long num = this->numerator * a.getDenominator() - a.getNumerator() * this->denominator;

            // Calculate the denominator
            long den = this->denominator * a.getDenominator();

            // Call to two argument constructor
            RationalNumber b(num, den);
            
            // Reduce rational number
            b.reduce();

            return b;
        }
        // Multiplication operator
        RationalNumber operator*(RationalNumber &a){
            // Calculate the numerator
            long num = this->numerator * a.getNumerator();

            // Calculate the denominator
            long den = this->denominator * a.getDenominator();

            // Call to two argument constructor
            RationalNumber b(num, den);

            // Reduce rational number
            b.reduce();

            return b;
        }
        // Divison operator
        RationalNumber operator/(RationalNumber &a){
            // Calculate the numerator
            long num = this->numerator * a.getDenominator();

            // Calculate the denominator
            long den = this->denominator * a.getNumerator();

            // Call to two argument constructor
            RationalNumber b(num, den);

            // Reduce the rational number
            b.reduce();

            return b;
        }
        // Output rational number
        friend ostream & operator << (ostream &out, const RationalNumber &r)
        {
            out<<r.numerator<<" / "<<r.denominator<<endl;
            return out;
        }
        // Input rational number
        friend istream & operator >> (istream &in, RationalNumber &r)
        {
            // Try for denominator
            try{
                cout<<"Enter numerator : ";
                in>>r.numerator;
                cout<<"Enter denominator : ";
                in>>r.denominator;
                
                // If denominator is negative
                if( r.denominator < 0)
                {
                    r.denominator *= -1;
                    r.numerator *= -1;
                }
                // If denominator is zero
                else if(r.denominator ==0){
                    throw(r.denominator);
                }
            }
            // Catch statement if the denominator is zero
            catch(long &a){
                cout << "Denominator cannot be zero/n";
                exit(-1);
            }
            return in;
        }
private:
    long numerator;     // Long for numerator
    long denominator;   // Long for denominator
};

int main(void){
    RationalNumber num1,num2(3,2), num3;
    cout << "Input rational number:" << endl;
    cin >> num1;
    
    // Add rational numbers
    cout << "Addition:" << endl;
    num3=num2+num1;
    cout << num3 << endl;
    
    // Subtract rational numbers
    cout << "Subtraction:" << endl;
    num3=num2-num1;
    cout << num3 << endl;
    
    // Multiply rational numbers
    cout << "Multiplication:" << endl;
    num3=num2*num1;
    cout << num3 << endl;
    
    // Divide rational numbers
    cout << "Division:" << endl;
    num3=num2/num1;
    cout << num3 << endl;
    
    return 0;
}
