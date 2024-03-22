/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   fraction.h
 * Author: erichuiza
 *
 * Created on March 21, 2024, 8:29 AM
 */

#ifndef FRACTION_H
#define FRACTION_H

struct Fraction {
    int numerator;
    int denominator;
};

// máximo común denominador
int gcd(int, int);

// simplificación de la matriz
void simplify(struct Fraction&);

#endif /* FRACTION_H */

