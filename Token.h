#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>

class Token {
	public:
		char kind; // Type of operator
		double value; // arguments

		Token get_token();

		double expression()
		{
			double left = term();//read and evaluate a term;
			Token t = get_token();
			switch(t.kind) {
				case '+':
					left += term();
					t = get_token();
					break;
				case '-':
					left -= term();
					t = get_token();
					break;
				default:
					return left;
			}
			return left;
		}
		double term()
		{
			double left = primary();
			Token t = get_token();
			while(true){
				switch(t.kind) {
					case '*':
						left *= primary();
						t = get_token();
						break;
					case '/':
						{
							double d = primary();
							if (d==0)
								std::cerr << "Divide by zero";
							left /= d;
							t = get_token();
							break;
						}
					default:
						return left;
				}
			}
		}
		double primary()
		{
			Token t = get_token();
			switch (t.kind) {
				case '(': // handle '(' expression ')'
					{
						double d = expression();
						t = get_token();
						if(t.kind != ')')
							std::cerr << "')' expected";
						return d;
					}
				case '8':
					return t.value;
				default:
					std::cerr << "Primary expected";
			}
		}

};

#endif
