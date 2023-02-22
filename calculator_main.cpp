#include <iostream>
#include <vector>

class Token {
	public: 
		char kind;
		double value;
	private:
		get_token()
		{

		}
		expression()
		{
			
		}
};

int main() {

	//Initialize vector of tokens
	std::vector<Token> tok;

	//Accept user input
	while (std::cin)
	{
		Token t = get_token();
		tok.push_back(t);
	}

	std::cout << "Result: " << res << std::endl;

	return 0;

}
