#include <iostream>

int main() {
	
	try {
		double a, b, c, d;
		std::cout << "Podaj trzy liczby:\n";
		std::cin >> a >> b >> c;
		
		try {
			d = (b * b) - (4 * a * c);
			
			if (d < 0)
				throw "typ: lancuch znakow";
			else if (d == 0)
				throw 22.2;
			else
				throw std::exception("wyjatek");
		}
		catch (...) {
			std::cout << "Exception catch" << std::endl;
			throw;
		}
	}

	catch (const char* lancuch) {
		std::cout << "Zlapano " << lancuch << std::endl;
	}
	catch (double liczba) {
		std::cout << "Zlapano typ double: " << liczba << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Zlapano " << e.what() << std::endl;
	}
}