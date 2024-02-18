//
// Created by Gaudium on 16.02.2024.
//

#ifndef SAOD_2_COMPLEX_H
#define SAOD_2_COMPLEX_H
#include <cmath>
#include "format"

class Complex {

public:
    double Re, Im;

    Complex(double Re=0, double Im=0){
        Complex::Re = Re;
        Complex::Im = Im;
    }

    double Arg(){
//        return !Mod() ? 0 : (Re > 0 ? atan(Im/Re) : (Re < 0 ? (Im >= 0 ? acos(-1)+ atan(Im/Re) : -acos(-1)- atan(Im/Re)) : Im >= 0 ? acos(0) : -acos(0)));

        if (!Mod()) return 0;

        if (Re > 0){
            return atan(Im/Re);
        }
        else if (Re < 0){
            return Im >= 0 ? acos(-1)+ atan(Im/Re) : -acos(-1)- atan(Im/Re);
        }
        else{
            return Im >= 0 ? acos(0) : -acos(0);
        }
    }

    double Mod(){
        return sqrt(Re*Re + Im*Im);
    }

    Complex Conjugate() const{
        return {Re, - Im};
    }

    Complex operator + (const Complex& c) const{
        return {this->Re + c.Re, this->Im + c.Im};
    }

    Complex operator - (const Complex& c) const{
        return {this->Re - c.Re, this->Im - c.Im};
    }

    Complex operator * (const Complex& c) const{
        return {Re * c.Re - Im * c.Im, Re * c.Im - c.Re * Im};
    }

    Complex operator / (const Complex& c) const{
        return {(Re*c.Re + Im*c.Im)/ (c.Re*c.Re + c.Im*c.Im), (-Re*c.Im+c.Re*Im)/ (c.Re*c.Re + c.Im*c.Im)};
    }
};

std::ostream& operator<<(std::ostream& o, const Complex& c){
    return o << std::format("({}, {})", c.Re, c.Im);
}

#endif //SAOD_2_COMPLEX_H
