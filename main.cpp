#include <iostream>
#include <fstream>

int main() {
    std::string FirstName, LastName, DateOfPayment;
    bool ValueTrue;
    int Payment;
    std::cout << "Enter the first name: ";
    std::cin >> FirstName;
    std::cout << "Enter the last name: ";
    std::cin >> LastName;
    do{
        ValueTrue = true;
        std::cout << "Enter the date of payment (dd-mm-yy): ";
        std::cin >> DateOfPayment;
        int dd = std::stoi(DateOfPayment.substr(0,2));
        int mm = std::stoi(DateOfPayment.substr(3,2));
        int yy = std::stoi(DateOfPayment.substr(6,2));
        if(dd < 1 || dd > 31 || mm < 1 || mm > 12 || yy < 0 || yy > 21){
            std::cout << " Bad input. Try again!" << std::endl;
            ValueTrue = false;
        }
    } while (!ValueTrue);
    do{
        ValueTrue = true;
        std::cout << "Enter the value of payment: ";
        std::cin >> Payment;
        if(Payment <= 0){
            std::cout << " Bad input. Try again!" << std::endl;
            ValueTrue = false;
        }
    }while (!ValueTrue);
    std::ofstream PaymentFile("../PaymentFile.txt",std::ios::app);
    PaymentFile << FirstName << " " << LastName << " " << DateOfPayment << " " << Payment << std::endl;
    PaymentFile.close();
    return 0;
}
