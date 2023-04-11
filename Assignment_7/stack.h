#include <iostream>
#include <stack>
#include <cmath>
#include <string>

using namespace std;

#ifndef STACK_H

#define STACK_H


extern stack<double> stack1;

void StackPush(double x);
double StackPop();
void StackPeek(int n);
int StackSize();

int Operation(string word);

int add();
int sub();
int mul();
int divide();
int power();
int neg();
int absolut();
int sinus();
int cosinus();
int logarithm();
int exponent();
int max();
int min();
int gamma();
int bc();
int dup();
int exch();

#endif