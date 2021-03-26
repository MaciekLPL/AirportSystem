#include <iostream>
#include <regex>

bool isPasswordValid(std::string passwd) {

	if (passwd.size() < 8)
		return false;

	std::regex upperCaseRegex("[A-Z]");
	std::regex lowerCaseRegex("[a-z]");
	std::regex numberRegex("[0-9]");
	std::regex specialCharsRegex("[!@#$%^&*()<>?/]");

	bool hasUppercase = std::regex_search(passwd, upperCaseRegex);
	bool hasLowercase = std::regex_search(passwd, lowerCaseRegex);
	bool hasNumber = std::regex_search(passwd, numberRegex);
	bool hasSpecialChar = std::regex_search(passwd, specialCharsRegex);

	if (hasUppercase && hasLowercase && hasNumber && hasSpecialChar)
		return true;
	else
		return false;
}

bool isEmailValid(std::string mail) {


	const char es[] = "bar0sh@bartosz.com";
	std::cmatch c;
	std::regex emailRegex("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

	return std::regex_match(es, c, emailRegex);
	//std::cout << "string literal with " << c[0] << " matches\n";
	//std::regex_match(mail, emailRegex);
	
}


void replaceDuplicates() {

	std::string text = "Lorem Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aliquam nec ante sit amet amet nulla nulla euismod rhoncus rhoncus. Fusce ultricies lacus lacus sed nulla dapibus, eget maximus nisl nisl mollis.";
	std::regex duplicates("\\b(\\w+) \\1\\b");
	std::cout << std::regex_replace(text, duplicates, "$1");

}

int main() {
	
	//std::string pass = "";
	//std::string email = "";
	//
	//while (true) {

	//	std::cout << "Wpisz email:" << std::endl;
	//	std::cin >> email;
	//	if (isEmailValid(email))
	//		break;
	//	else
	//		std::cout << "Email jest poprawny" << std::endl;
	//}

	//while(true) {
	//	std::cout << "Wpisz haslo:" << std::endl;
	//	std::cin >> pass;
	//	if (isPasswordValid(pass))
	//		break;
	//	else
	//		std::cout << "Haslo  nie spelnia wymogow" << std::endl;
	//}

	//const char wiadomosc[] =
	//	" temat: Rezerwacja z900729tm zosta³a zaakceptowana"
	//	" od: hotelM@gmail.com"
	//	" treœæ: Dziêkujemy za rezerwacjê pokoju nr 515 "
	//	" W razie dodatkowych pytañ prosimy dzwoniæ na recepcjê 356 000 000."
	//	" Hotel M. 48-220 ul. Aleja Wilanowska"
	//	" wiadomoœæ zosta³a dostarczona dnia 13.07.2018 o godzinie 21:15";


	//std::smatch wynik;
	//std::cmatch wynik2;
	//std::regex wzorzec("\\w+ M.");

	//if (std::regex_search(wiadomosc, wynik2, wzorzec))
	//	std::cout << wynik2[0];

	////isEmailValid("chuj");
	//replaceDuplicates();


	const std::string s = "Quick browsssn fox.";

	std::regex words_regex("[^\\s]+");
	auto words_begin =
		std::sregex_iterator(s.begin(), s.end(), words_regex);
	auto words_end = std::sregex_iterator();

	std::cout << "Found "
		<< std::distance(words_begin, words_end)
		<< " words:\n";

	for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
		std::smatch match = *i;
		std::string match_str = match.str();
		std::cout << match_str << '\n';
	}


}


