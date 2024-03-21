// FCAI – Structured Programming – 2024 - Assignment 2
// Program Name: CS112_A2_T3_20230482_S18_20231134_S17_20231116_S17
// Program Description: Calculator that is able to add, subtract, multiply and divide fractions
// Last Modification Date: 18/3/2024

// Author1 and ID and Group: Youssef Amgad Abd Al Halim Ahmed, 20230482, S18, Testing and regex pattern
// youssefamgadelkhatib@gmail.com
// 11410120230482@stud.cu.edu.eg

// Author2 and ID and Group: Mohamed Ahmed Mohamed Abd El_wahab,20231134,S17, Mathematical Calculations
// ahmd.mohamed200515@gmail.com
// 11410120231134@stud.cu.edu.eg

// Author3 and ID and Group: Amr Khaled Ahmed Abd ElHamid,20231116,S17, divided the regex pattern into three parts(operator, fraction 1 , fraction 2), created if statement for the mathematical calculations
// yy171516@gmail.com
// 11410120231116@stud.cu.edu.eg

// Teaching Assistant: Eng/ Ahmed Lotfi
/*
Algorithm in pseudocode link
https://drive.google.com/drive/folders/1fSyH52ToPxvq5ms9hI4HHlvmgVc1YVQL?usp=sharing
*/

#include <iostream>
#include <regex>
# include <cctype>
# include <string>
# include <cstring>
# include <algorithm>
# include <vector>

using namespace std;

bool is_valid(string format);
string operation(string equation);
pair<long long, long long> extract_fraction(string temp_fraction);
string addition_fraction(long long num_fraction1,long long deno_fraction1,long long num_fraction2,long long deno_fraction2);
string subtraction_fraction(long long num_fraction1,long long deno_fraction1,long long num_fraction2,long long deno_fraction2);
string multiplcation_fraction(long long num_fraction1,long long deno_fraction1,long long num_fraction2,long long deno_fraction2);
string division_fraction(long long num_fraction1,long long deno_fraction1,long long num_fraction2,long long deno_fraction2);
pair<long long,long long> common_divisor(long long numerator,long long denominator);


int main() {

    cout << "Welcome to our fractional calculator" << endl;

    while(true){
        string format;
        string choice;

        // display menu and take input from user and take choice from user
        cout << "1. Enter an input" << endl;
        cout << "2. Exit" << endl;
        cout << "Choose 1 or 2" << endl;
        cin >> choice;

        // validate choice
        while (true) {
            if (choice == "1")break;
            else if (choice == "2") {
                cout << "Thanks for using our fractional calculator" << endl;
                return 0;
            } else {
                cout << "Invalid input, please enter a valid choice" << endl;
                cin >> choice;
            }
        }

        // get calculation from user
        cin.ignore();
        cout << "Please enter your calculation" << endl;
        getline(cin, format);

        // make sure format isn't empty
        while (format.empty()) {
            cout << "Invalid input" << endl;
            cout << "Enter a valid input format" << endl;
            getline(cin, format);
        }

        // make sure format matches calculation format
        bool is_valid_format = is_valid(format);

        while (!is_valid_format) {
            cout << "Invalid input" << endl;
            cout << "Enter a valid input format"<<endl;;
            getline(cin, format);
            is_valid_format = is_valid(format);
        }
        operation(format);
    }

}


string operation(string equation) {
    double result_D;
    regex N("-");
    regex Multi("\\*"); // Escaping '*' since it's a special character in regex
    regex Divide ("/");
    smatch matches;

    // here I will define the equation form divided into parts then take every part as (fraction_1, operation, fraction_2) the perform the equation
    regex equation_form("[ ]*?([+-]?[0-9]+(?:/[0]?+[1-9][0-9]*)?)\\s([-+*/])\\s([+-]?[0-9]+(?:/[0]?+[1-9][0-9]*)?)[ ]*?");
    regex_match(equation, matches, equation_form);
    string fraction_1 = matches[1].str();
    string operation = matches[2].str();
    string fraction_2 = matches[3].str();
    // by operation choose the operation

    pair<long long, long long> fraction = extract_fraction(fraction_1);
    pair<long long, long long> fraction2 = extract_fraction(fraction_2);

    if (operation == "+"){
        cout << "Addition" << endl;
        addition_fraction(fraction.first,fraction.second,fraction2.first,fraction2.second);

    }
    else if (operation == "-"){
        cout << "Subtraction" << endl;
        subtraction_fraction(fraction.first,fraction.second,fraction2.first,fraction2.second);

    }
    else if (operation == "/"){
        cout << "Divide" << endl;
        division_fraction(fraction.first,fraction.second,fraction2.first,fraction2.second);

    }
    else if (operation == "*"){
        cout << "multiplies" << endl;
        multiplcation_fraction(fraction.first,fraction.second,fraction2.first,fraction2.second);

    }

    // Return some value since the function is declared to return a string
    return "Operation performed successfully";
}


// function that checks if the format the user entered is correct and valid
bool is_valid(string format) {
    if (regex_match(format, regex("[ ]*?[+-]?[0-9]+(?:/[0]?+[1-9][0-9]*)?\\s[-/*+]\\s[+-]?[0-9]+(?:/[0]?+[1-9][0-9]*)?[ ]*?"))) {
        return true;
    } else {
        return false;
    }
}


pair<long long, long long> extract_fraction(string temp_fraction) {
    long long sign = 1;
    string fraction = temp_fraction;
    if (fraction[0] == '-') {
        sign = -1;
        fraction = fraction.substr(1); // Remove the negative sign

    }
    // Find the position of the divide operator
    size_t divide_pos = fraction.find('/');
    // Extract numerator and denominator
    long long numerator = stoll(fraction.substr(0, divide_pos));
    long long denominator = 1; // Default denominator is 1 if not specified
    if (divide_pos != string::npos) { // get the double of fraction
        denominator = stoll(fraction.substr(divide_pos + 1));

    }
    numerator *= sign;
    return make_pair(numerator, denominator); // return value of numerator and denominator
}


string addition_fraction(long long num_fraction1,long long deno_fraction1,long long num_fraction2,long long deno_fraction2){
    long long denomenator = deno_fraction1*deno_fraction2;  // line 148&149 will perform calculation of fraction addition
    long long numerator = (num_fraction1*deno_fraction2)+(num_fraction2*deno_fraction1);
    pair<long long, long long> common_divsor = common_divisor(numerator, denomenator); // take the common divisor to denominator and numerator
    numerator = common_divsor.first;
    denomenator = common_divsor.second;
    if(numerator==0){ // check if numerator equals to zero or not
        cout<<num_fraction1<<"/"<<deno_fraction1<<" / "<<num_fraction2<<"/"<<deno_fraction2<<" = "<<numerator<<endl;
    }
    else if(denomenator==1){ // check if denominator equals to zero or not
        cout<<num_fraction1<<"/"<<deno_fraction1<<" + "<<num_fraction2<<"/"<<deno_fraction2<<" = "<<numerator<<endl;
    }
    else if(denomenator==-1){ // check if denominator equals to zero or not
        cout<<num_fraction1<<"/"<<deno_fraction1<<" + "<<num_fraction2<<"/"<<deno_fraction2<<" = "<<-numerator<<endl;
    }
    else if(deno_fraction1==1){
        cout<<num_fraction1<<" + "<<num_fraction2<<"/"<<deno_fraction2<<" = "<<numerator<<"/"<<denomenator<<endl;
    }
    else if(deno_fraction2==1){ // check if denominator is smaller than zero or not
        cout<<num_fraction1<<"/"<<deno_fraction1<<" + "<<num_fraction2<<" = "<<numerator<<"/"<<denomenator<<endl;
    }
    else if(denomenator<0){ // check if denominator is smaller than zero or not
        cout<<num_fraction1<<"/"<<deno_fraction1<<" + "<<num_fraction2<<"/"<<deno_fraction2<<" = "<<-numerator<<"/"<<-denomenator<<endl;
    }
    else if(numerator<0){ // check if numerator is smaller than zero or not
        cout<<num_fraction1<<"/"<<deno_fraction1<<" + "<<num_fraction2<<"/"<<deno_fraction2<<" = "<<numerator<<"/"<<denomenator<<endl;
    }
    else{
        cout<<num_fraction1<<"/"<<deno_fraction1<<" + "<<num_fraction2<<"/"<<deno_fraction2<<" = "<<numerator<<"/"<<denomenator<<endl;

    }
    return "";
}


string subtraction_fraction(long long num_fraction1,long long deno_fraction1,long long num_fraction2,long long deno_fraction2){
    long long denomenator = deno_fraction1*deno_fraction2; // line 190&191 will perform calculation of fraction subtraction
    long long numerator = (num_fraction1*deno_fraction2)-(num_fraction2*deno_fraction1);
    pair<long long, long long> common_divsor = common_divisor(numerator, denomenator); // take the common divisor to denominator and numerator
    numerator = common_divsor.first;
    denomenator = common_divsor.second;
    if(numerator==0){ // check if numerator equals to zero or not
        cout<<num_fraction1<<"/"<<deno_fraction1<<" - "<<num_fraction2<<"/"<<deno_fraction2<<" = "<<numerator<<endl;
    }
    else if(denomenator==1){ // check if denominator equals to zero or not
        cout<<num_fraction1<<"/"<<deno_fraction1<<" - "<<num_fraction2<<"/"<<deno_fraction2<<" = "<<numerator<<endl;
    }
    else if(denomenator==-1){ // check if denominator equals to zero or not
        cout<<num_fraction1<<"/"<<deno_fraction1<<" - "<<num_fraction2<<"/"<<deno_fraction2<<" = "<<-numerator<<endl;
    }
    else if(deno_fraction1==1){
        cout<<num_fraction1<<" - "<<num_fraction2<<"/"<<deno_fraction2<<" = "<<numerator<<"/"<<denomenator<<endl;
    }
    else if(deno_fraction2==1){ // check if denominator is smaller than zero or not
        cout<<num_fraction1<<"/"<<deno_fraction1<<" - "<<num_fraction2<<" = "<<numerator<<"/"<<denomenator<<endl;
    }
    else if(denomenator<0){ // check if denominator is smaller than zero or not
        cout<<num_fraction1<<"/"<<deno_fraction1<<" - "<<num_fraction2<<"/"<<deno_fraction2<<" = "<<-numerator<<"/"<<-denomenator<<endl;
    }
    else if(numerator<0){ // check if numerator is smaller than zero or not
        cout<<num_fraction1<<"/"<<deno_fraction1<<" - "<<num_fraction2<<"/"<<deno_fraction2<<" = "<<-numerator<<"/"<<denomenator<<endl;
    }
    else{
        cout<<num_fraction1<<"/"<<deno_fraction1<<" - "<<num_fraction2<<"/"<<deno_fraction2<<" = "<<numerator<<"/"<<denomenator<<endl;

    }


    return "";
}


string multiplcation_fraction(long long num_fraction1,long long deno_fraction1,long long num_fraction2,long long deno_fraction2){
    long long denomenator = deno_fraction1*deno_fraction2; // line 218&219 will perform calculation of fraction multiplcation
    long long numerator = (num_fraction1*num_fraction2);
    pair<long long, long long> common_divsor = common_divisor(numerator, denomenator); // take the common divisor to denominator and numerator
    numerator = common_divsor.first;
    denomenator = common_divsor.second;
    if(numerator==0){ // check if numerator equals to zero or not
        cout<<num_fraction1<<"/"<<deno_fraction1<<" * "<<num_fraction2<<"/"<<deno_fraction2<<" = "<<numerator<<endl;
    }
    else if(denomenator==1){ // check if denominator equals to zero or not
        cout<<num_fraction1<<"/"<<deno_fraction1<<" * "<<num_fraction2<<"/"<<deno_fraction2<<" = "<<numerator<<endl;
    }
    else if(denomenator==-1){ // check if denominator equals to zero or not
        cout<<num_fraction1<<"/"<<deno_fraction1<<" * "<<num_fraction2<<"/"<<deno_fraction2<<" = "<<-numerator<<endl;
    }
    else if(deno_fraction1==1){
        cout<<num_fraction1<<" * "<<num_fraction2<<"/"<<deno_fraction2<<" = "<<numerator<<"/"<<denomenator<<endl;
    }
    else if(deno_fraction2==1){ // check if denominator is smaller than zero or not
        cout<<num_fraction1<<"/"<<deno_fraction1<<" * "<<num_fraction2<<" = "<<numerator<<"/"<<denomenator<<endl;
    }
    else if(denomenator<0){ // check if denominator is smaller than zero or not
        cout<<num_fraction1<<"/"<<deno_fraction1<<" * "<<num_fraction2<<"/"<<deno_fraction2<<" = "<<-numerator<<"/"<<-denomenator<<endl;
    }
    else if(numerator<0){ // check if numerator is smaller than zero or not
        cout<<num_fraction1<<"/"<<deno_fraction1<<" * "<<num_fraction2<<"/"<<deno_fraction2<<" = "<<numerator<<"/"<<denomenator<<endl;
    }
    else{
        cout<<num_fraction1<<"/"<<deno_fraction1<<" * "<<num_fraction2<<"/"<<deno_fraction2<<" = "<<numerator<<"/"<<denomenator<<endl;

    }

    return "";
}


string division_fraction(long long num_fraction1,long long deno_fraction1,long long num_fraction2,long long deno_fraction2){
    long long denomenator = deno_fraction1*num_fraction2; // line 245&246 will perform calculation of fraction division
    long long numerator = (num_fraction1*deno_fraction2);
    pair<long long, long long> common_divsor = common_divisor(numerator, denomenator); // take the common divisor to denominator and numerator
    numerator = common_divsor.first;
    denomenator = common_divsor.second;
    while(true){
        if(deno_fraction1==0||num_fraction2==0){
            cout<<num_fraction1<<"/"<<deno_fraction1<<" / "<<num_fraction2<<"/"<<deno_fraction2<<" = Undefined"<<endl;
            break;
        }
        if((deno_fraction1==0&&num_fraction1==0)||(deno_fraction2==0&&num_fraction2==0)){
            cout<<num_fraction1<<"/"<<deno_fraction1<<" / "<<num_fraction2<<"/"<<deno_fraction2<<" = Undefined"<<endl;
            break;
        }
        if(numerator==0){ // check if numerator equals to zero or not
            cout<<num_fraction1<<"/"<<deno_fraction1<<" / "<<num_fraction2<<"/"<<deno_fraction2<<" = "<<numerator<<endl;
            break;
        }
        else if(denomenator==1){ // check if denominator equals to zero or not
            cout<<num_fraction1<<"/"<<deno_fraction1<<" / "<<num_fraction2<<"/"<<deno_fraction2<<" = "<<numerator<<endl;
            break;
        }
        else if(denomenator==-1){ // check if denominator equals to zero or not
            cout<<num_fraction1<<"/"<<deno_fraction1<<" / "<<num_fraction2<<"/"<<deno_fraction2<<" = "<<-numerator<<endl;
            break;
        }
        else if(deno_fraction1==1){
            cout<<num_fraction1<<" / "<<num_fraction2<<"/"<<deno_fraction2<<" = "<<numerator<<"/"<<denomenator<<endl;
            break;
        }
        else if(deno_fraction2==1){ // check if denominator is smaller than zero or not
            cout<<num_fraction1<<"/"<<deno_fraction1<<" / "<<num_fraction2<<" = "<<numerator<<"/"<<denomenator<<endl;
            break;
        }
        else if(denomenator<0){ // check if denominator is smaller than zero or not
            cout<<num_fraction1<<"/"<<deno_fraction1<<" / "<<num_fraction2<<"/"<<deno_fraction2<<" = "<<-numerator<<"/"<<-denomenator<<endl;
            break;
        }
        else if(numerator<0){ // check if numerator is smaller than zero or not
            cout<<num_fraction1<<"/"<<deno_fraction1<<" / "<<num_fraction2<<"/"<<deno_fraction2<<" = "<<numerator<<"/"<<denomenator<<endl;
            break;
        }
        else{
            cout<<num_fraction1<<"/"<<deno_fraction1<<" / "<<num_fraction2<<"/"<<deno_fraction2<<" = "<<numerator<<"/"<<denomenator<<endl;
            break;

        }
    }

    return "";
}


pair<long long,long long> common_divisor(long long numerator, long long denominator){
    long long common_divisor = 1; // make first common_divisor value equals to 1
    long long smaller_Number = min(abs(numerator), abs(denominator)); // take smallest number between numerator and denominator
    for(int i = 1; i <= smaller_Number; i++){ // iterate from 1 to smallest number between numerator and denominator
        if(numerator % i == 0 && denominator % i == 0){ // check numerator is divisible by i and denominator is divisible by i or not
            common_divisor = i; // modify common_divisor value
        }
    }
    numerator /= common_divisor; // making division between numerator and common_divisor
    denominator /= common_divisor; // making division between denominator and common_divisor
    return make_pair(numerator, denominator);
}