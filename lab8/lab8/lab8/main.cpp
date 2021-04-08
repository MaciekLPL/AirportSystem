#include <iostream>
#include <regex>
struct Dane {
    std::string data;
    std::string numerTelefonu;
    std::string kodPocztowy;
};

int main() {
    Dane dane;
    std::string wiadomosc =
        " temat: Rezerwacja z900729tm zosta³a zaakceptowana"
        " od: hotelM@gmail.com"
        " treœæ: Dziêkujemy za rezerwacjê pokoju nr 515 "
        " W razie dodatkowych pytañ prosimy dzwoniæ na recepcjê 356 000 000."
        " Hotel M. 48-220 ul. Aleja Wilanowska"
        " wiadomoœæ zosta³a dostarczona dnia 13.07.2018 o godzinie 21:15";
    /////////////////////zadanie 1///////////////////////////////////

    std::smatch wynik;
    std::regex wzorzec1("[0-9]{3} [0-9]{3} [0-9]{3}");
    std::regex wzorzec2("[0-9]{2}-[0-9]{3}");
    std::regex wzorzec3("((0[1-9])|(1[0-9])|(2[0-9])|(3[0-1])).((0[1-9])|(1[0-2])).[0-9]{4}");

    if (std::regex_search(wiadomosc, wynik, wzorzec1))
        dane.numerTelefonu = wynik[0];
    if (std::regex_search(wiadomosc, wynik, wzorzec2))
        dane.kodPocztowy = wynik[0];
    if (std::regex_search(wiadomosc, wynik, wzorzec3))
        dane.data = wynik[0];

    std::cout << dane.data << std::endl;
    std::cout << dane.kodPocztowy << std::endl;
    std::cout << dane.numerTelefonu << std::endl;

    //////////////////////////zadanie 2///////////////////////////////////
    std::string email = "";
    while (true)     {
        std::cout << "Wpisz email:" << std::endl;
        std::cin >> email;
        std::regex emailRegex("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

        if (std::regex_match(email, emailRegex))
            break;
        else
            std::cout << "Email jest niepoprawny" << std::endl;
    }

}