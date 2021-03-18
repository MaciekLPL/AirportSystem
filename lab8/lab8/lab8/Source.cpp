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

	std::regex emailRegex("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
	return std::regex_match(mail, emailRegex);
	
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

	replaceDuplicates();

}


