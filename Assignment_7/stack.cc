#include "stack.h"

std::stack<double> stack1;

int Operation(string word) {
    char* p;
    double var = strtod(word.c_str(), &p);
	
    if(*p) {
        if(word == "add") return add();
        else if(word == "sub") return sub();
        else if(word == "mul") return mul();
        else if(word == "div") return divide();
        else if(word == "pow") return power();
        else if(word == "neg") return neg();
        else if(word == "abs") return absolut();
        else if(word == "sin") return sinus();
        else if(word == "cos") return cosinus();
        else if(word == "log")  return logarithm();
        else if(word == "exp") return exponent();
		else if(word == "max") return max();
		else if(word == "min") return min();
		else if(word == "gamma") return gamma();
		else if(word == "bc") return bc();
		else if(word == "dup") return dup();
		else if(word == "exch") return exch();
        else if(word == "?" || word == "h" || word == "help") {
            cout << "Arithmetic operations:" << endl;
            cout << "add, sub, mul, div, pow, neg, abs, sin, cos, log, exp" << endl << endl;
			
            cout << "Other:" << endl;
            cout << "?, h, help, q, quit, =, pstack" << endl;
			
            return 0;
        }
        else if(word == "q" || word == "quit") {
            if(StackSize() == 0) {
                cout << "***Stack is empty, therefore can't be written to output***" << endl;
				
                exit(0);
            }
            else {
                StackPeek(StackSize());
				
                exit(0);
            }
        }
        else if(word == "=") {
            if(StackSize() == 0) {
                cout << "***Stack is empty***" << endl;
				
                return -1;
            }
            else {
                StackPeek(0);
				
                return 0;
            }
        }
        else if(word == "pstack") {
            if(StackSize() == 0) {
                cout << "***Stack is empty***" << endl;
				
                return -1;
            }
            else {
                StackPeek(StackSize());
				
                return 0;
            }
		}
        else {
            if(StackSize() > 0) StackPeek(StackSize());
            cout << "***Invalid operator***" << endl;
			
            return -1;
        }
	}
	else {
		StackPush(var);
		
		return 0;
	}
}

void StackPush(double x) {
    stack1.push(x);
}

int StackSize() {
    return stack1.size();
}

double StackPop() {
    double num = stack1.top();
	
    stack1.pop();
	
    return num;
}

void StackPeek(int n) {
    stack<double> temp;
	
    double temp1;
	
    if(n == 0) cout << stack1.top() << endl;
    else {
        for(int i=0; i<n; i++) {
            temp1 = StackPop();
			
            temp.push(temp1);
        }
        while(!temp.empty()) {
            temp1 = temp.top();
            cout << temp1 << " ";
			
            StackPush(temp1);
			
            temp.pop();
        }
        cout << endl;
    }
}

int add() {
    double a, b;
	
    if(StackSize() < 2) {
        if(StackSize() == 1) StackPeek(StackSize());
        cout << "***Insufficient amount of elements on the stack***" << endl;
		
        return -1;
    }
    else {
        a = StackPop();
        b = StackPop();
		
        StackPush(b + a);
		
        return 0;
    }
}

int sub() {
    double a, b;
	
    if(StackSize() < 2) {
        if(StackSize() == 1) StackPeek(StackSize());
        cout << "***Insufficient amount of elements on the stack***" << endl;
		
        return -1;
    }
    else {
        a = StackPop();
        b = StackPop();
		
        StackPush(b-a);
		
        return 0;
    }
}

int mul() {
    double a, b;
	
    if(StackSize() < 2)
    {
        if(StackSize() == 1) StackPeek(StackSize());
        cout << "***Insufficient amount of elements on the stack***" << endl;
		
        return -1;
    }
    else {
        a = StackPop();
        b = StackPop();
		
        StackPush(b*a);
		
        return 0;
    }
}

int divide() {
    double a, b;
	
    if(StackSize() < 2) {
        if(StackSize() == 1) StackPeek(StackSize());
        cout << "***Insufficient amount of elements on the stack***" << endl;
		
        return -1;
    }
    else {
        a = StackPop();
		
        if(a == 0) {
            StackPush(a);
			
            StackPeek(StackSize());
			
            cout<<"***It is impossible to divide by 0***" << endl;
			
            return -1;
        }
        else {
            b = StackPop();
			
            StackPush(b/a);
			
            return 0;
        }
    }
}

int power() {
    double a, b;
	
    if(StackSize() < 2) {
        if(StackSize()==1) StackPeek(StackSize());
        cout << "***Insufficient amount of elements on the stack***" << endl;
		
        return -1;
    }
    else {
        a = StackPop();
        b = StackPop();
		
        StackPush(pow(b, a));
		
        return 0;
    }
}

int neg() {
    double a; 
	
    if(StackSize() < 1) {
        cout<<"***Insufficient amount of elements on the stack***"<<endl;
		
        return -1;
    }
    else {
        a = StackPop();
		
        StackPush(a*(-1));
		
        return 0;
    }
}

int absolut() {
    double a;
	
    if(StackSize() < 1) {
        cout << "***Insufficient amount of elements on the stack***" << endl;
		
        return -1;
    }
    else {
        a = StackPop();
		
        StackPush(fabs(a));
		
        return 0;
    }
}

int sinus() {
    double a;
	
    if(StackSize() < 1) {
        cout << "***Insufficient amount of elements on the stack***" << endl;
		
        return -1;
    }
    else {
        a = StackPop();
		
        StackPush(sin(a));
		
        return 0;
    }
}

int cosinus() {
    double a;
	
    if(StackSize() < 1) {
        cout << "***Insufficient amount of elements on the stack***" << endl;
		
        return -1;
    }
    else {
        a = StackPop();
		
        StackPush(cos(a));
		
        return 0;
    }
}

int logarithm() {
    double a;
	
    if(StackSize() < 1) {
        cout << "***Insufficient amount of elements on the stack***" << endl;
		
        return -1;
    }
    else {
        a = StackPop();
		
        if(a <= 0) {
            StackPush(a);
			
            StackPeek(StackSize());
			
            cout << "***The base of a logarithm must be a positive real number not equal to 1***" << endl;
			
            return -1;
        }
        else {
            StackPush(log(a));
			
            return 0;
        }
    }
}

int exponent() {
    double a;
	
    if(StackSize() < 1) {
        cout << "***Insufficient amount of elements on the stack***"<<endl;
		
        return -1;
    }
    else {
        a = StackPop();
		
        StackPush(exp(a));
		
        return 0;
    }
}

int max() {
	double a, b;
	
	if(StackSize() < 2) {
        if(StackSize() == 1) StackPeek(StackSize());
        cout << "***Insufficient amount of elements on the stack***" << endl;
		
        return -1;
    }
	else {
        a = StackPop();
        b = StackPop();
		
        if(a > b) StackPush(a);
		if(b > a) StackPush(b);
		if(a == b) StackPush(a);
		
        return 0;
    }
}

int min() {
	double a, b;
	
	if(StackSize() < 2) {
        if(StackSize() == 1) StackPeek(StackSize());
        cout << "***Insufficient amount of elements on the stack***" << endl;
		
        return -1;
    }
	else {
        a = StackPop();
        b = StackPop();
		
        if(a > b) StackPush(b);
		if(b > a) StackPush(a);
		if(a == b) StackPush(a);
		
        return 0;
    }
}

int gamma() {
	double a;
	
	if(StackSize() < 1) {
        if(StackSize() == 1) StackPeek(StackSize());
        cout << "***Insufficient amount of elements on the stack***" << endl;
		
        return -1;
    }
	else {
        a = StackPop();
		a = tgamma(a);
		
		if(isnan(a) == 1 || isinf(a) == 1) {
			cout << "***Incorrect input***" << endl;
			
			return -1;
		}
		else {
			StackPush(a);
			
			return 0;
		}
    }
}

int bc() {
	double k, n;
	double j = 1;
	
	if(StackSize() < 2) {
        if(StackSize() == 1) StackPeek(StackSize());
        cout << "***Insufficient amount of elements on the stack***" << endl;
		
        return -1;
    }
	else {
        k = StackPop();
        n = StackPop();
		
		if(n < k) {
			cout << "***Incorrect input, n must be a natural number higher or equal to natural number k higher or equal to 0" << endl;
			
			StackPush(n);
			StackPush(k);
			
			StackPeek(StackSize());
			
			return -1;
		}
		else {
			int i = n;
			
			if(k < n - k) {
				while(i >= n - k + 1) {
				j = j * i / (n - i + 1);
				i--;
				}
			}
			else if(k >= n - k) {
			while(i >= k + 1) {
					j = j * i / (n - i + 1);
					i--;
				}
			}
		}
    StackPush(j);
		
        return 0;
    }
}

int dup() {
	double a;
	
	if(StackSize() < 1) {
        if(StackSize() == 1) StackPeek(StackSize());
        cout << "***Insufficient amount of elements on the stack***" << endl;
		
        return -1;
    }
	else {
        a = StackPop();
		
		StackPush(a);
		StackPush(a);
		
        return 0;
    }
}

int exch() {
	double a, b;
	
	if(StackSize() < 2) {
        if(StackSize() == 1) StackPeek(StackSize());
        cout << "***Insufficient amount of elements on the stack***" << endl;
		
        return -1;
    }
	else {
        a = StackPop();
		b = StackPop();
		
		StackPush(a);
		StackPush(b);
		
        return 0;
    }
}