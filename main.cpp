#include <iostream>
#include <fstream>

int main() {
    std::string firstName, lastName, dateOfPayment;
    bool valueTrue;
    int payment;
    std::cout << "Enter the first name: ";
    std::cin >> firstName;
    std::cout << "Enter the last name: ";
    std::cin >> lastName;
    do{
        valueTrue = true;
        std::cout << "Enter the date of payment (dd-mm-yy): ";
        std::cin >> dateOfPayment;
        int dd = std::stoi(dateOfPayment.substr(0, 2));
        int mm = std::stoi(dateOfPayment.substr(3, 2));
        int yy = std::stoi(dateOfPayment.substr(6, 2));
        if(dd < 1 || dd > 31 || mm < 1 || mm > 12 || yy < 0 || yy > 21){
            std::cout << " Bad input. Try again!" << std::endl;
            valueTrue = false;
        }
    } while (!valueTrue);
    do{
        valueTrue = true;
        std::cout << "Enter the value of payment: ";
        std::cin >> payment;
        if(payment <= 0){
            std::cout << " Bad input. Try again!" << std::endl;
            valueTrue = false;
        }
    }while (!valueTrue);
    std::ofstream paymentFile("../PaymentFile.txt", std::ios::app);
    if(paymentFile.is_open()){
        paymentFile << firstName << " " << lastName << " " << dateOfPayment << " " << payment << std::endl;
        paymentFile.close();
    }
    else std::cout << "Can't open file PaymentFile.txt" << std::endl;
    return 0;
}
