#include <iostream>
using namespace std;

class PayrollManager {
private:
    double grossPay;
public:
    PayrollManager(double gross) : grossPay(gross) {}

    double calculateTax() const {
        if (grossPay >= 24000 && grossPay <= 150000) {
            return 0.3 * grossPay;
        } else if (grossPay > 150000 && grossPay <= 250000) {
            return 0.32 * grossPay;
        } else if (grossPay > 250000) {
            return 0.35 * grossPay;
        } else {
            return 0.0;
        }
    }

    double calculateHousingLevy() const {
        return 0.015 * grossPay;
    }

    double calculateNHIFCharge() const {
        return 0.0275 * grossPay;
    }

    double calculateNetPay() const {
        double tax = calculateTax();
        double housingLevy = calculateHousingLevy();
        double nhifCharge = calculateNHIFCharge();
        return grossPay - tax - housingLevy - nhifCharge;
    }
};

int main() {
    cout <<"-- PAYROLL MANAGEMENT SYSTEM --\n"<<endl;
    double grossPay;
     cout << "Enter the employee's gross pay: ";
     cin >> grossPay;

    PayrollManager payroll(grossPay);

    double tax = payroll.calculateTax();
    double housingLevy = payroll.calculateHousingLevy();
    double nhifCharge = payroll.calculateNHIFCharge();
    double netPay = payroll.calculateNetPay();

    cout << "Tax: Kes" << tax << std::endl;
    cout << "Housing Levy: Kes" << housingLevy << std::endl;
    cout << "NHIF Charge: Kes" << nhifCharge << std::endl;
    cout << "Net Pay: Kes" << netPay << std::endl;

    return 0;
}
