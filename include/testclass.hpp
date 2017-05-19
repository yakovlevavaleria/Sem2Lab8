#include <iostream>
using namespace std;


class Complex {
	double Real_;
	double Im_;

public:
	Complex() : Real_(0), Im_(0) {};
	Complex(double Real, double Im) : Real_(Real), Im_(Im) {};

	double getReal() { return Real_; }
	double getIm() { return Im_; }
	
	Complex(const Complex &c) {
		Real_ = c.Real_;
		Im_ = c.Im_;
	}

	Complex operator + (const Complex& c2) {
		Complex tmp(*this);
		tmp += c2;
		return tmp;
	}
	Complex operator - (const Complex& c2) {
		Complex tmp(*this);
		tmp -= c2;
		return tmp;
	}
	Complex& operator /= (const Complex& c2){
		try {
			if (c2.Im_ != 0 && c2.Real_ != 0) {
				double tmp;
				tmp = (Real_*c2.Real_ + Im_*c2.Im_) / (c2.Real_*c2.Real_ + c2.Im_*c2.Im_);
				Im_ = (c2.Real_*Im_ - Real_*c2.Im_) / (c2.Real_*c2.Real_ + c2.Im_*c2.Im_);
				Real_ = tmp;
				return *this;
			}
			else throw "Can't divide by zero\n";
		}
		catch (char *msg) {
			cout << "Error: " << msg << endl;
			return *this;
		}
	}
	Complex& operator *= (const Complex& c2)
	{
		double tmp;
		tmp = Real_*c2.Real_ - Im_*c2.Im_;
		Im_ = Real_*c2.Im_ + c2.Real_*Im_;
		Real_ = tmp;
		return *this;
	}
	Complex  operator* (const Complex& c2) {
		Complex tmp(*this);
		tmp *= c2;
		return tmp;
	}
	Complex  operator/ (const Complex& c2) {
		Complex tmp(*this);
		tmp /= c2;
		return tmp;
	}
	Complex& operator+=(const Complex& c2) {
		Real_ += c2.Real_;
		Im_ += c2.Im_;
		return *this;
	}
	Complex& operator-=(const Complex& c2) {
		Real_ -= c2.Real_;
		Im_ -= c2.Im_;
		return *this;
	}
	Complex& operator= (const Complex& res) {
		if (this != &res) {
			Real_ = res.Real_;
			Im_ = res.Im_;
		}
		return *this;
	}
	bool operator== (const Complex& c2) {
		if ((Real_ == c2.Real_) && (Im_ == c2.Im_)) {
			return true;
		}
		else return false;
	}

	void print(ostream&) {
		cout << Real_ << " + i*(" << Im_ << ')' << endl;
	}
	friend ostream& operator << (ostream&cout, Complex& res);
	friend istream& operator >> (istream&cin, Complex& res);
};

ostream & operator<<(ostream & out, Complex &c)
{
	out << c.getReal() << " + i*(" << c.getIm() << ')' << endl;
	return out;
}
istream & operator >> (istream & in, Complex &c)
{
	in >> c.Real_;
	in >> c.Im_;
	return in;
}
