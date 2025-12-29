#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;

bool isNumericString(const string& input){

	//return 0 if empty, or not all digits
	return !input.empty() && all_of(input.begin(), input.end(), [](unsigned char c) {return isdigit(c);} );
}

bool isLuhnValid (const string& input){

	int total = 0;
	//double ever second digit starting from the end. If the digit provided doubles to a 2 digit number, add those digits together.
	for(int i = input.length() - 2; i >= 0; i-=2){
		int dbl = (input[i] - '0') *2;
		
		if(dbl > 9){	
			total += (dbl/10 + dbl%10);
		}
		else {
			total += dbl;
		}
	}

	//add all the collected digits together with the digits that were not doubled
	for(int i = input.length() - 1; i>=0; i-=2){
		total+=input[i] - '0';
	}

	//if the number is a multiple of 10 then it is a valid number
	return total%10 == 0;
	
}

int main (){

	string CreditCardNumber;

	while(true){

		//take input
		cout<<"Enter a potential credit card number, type exit to end the program: ";

		cin >> CreditCardNumber;

		//exit if keyword is entered
		if(CreditCardNumber == "exit")
			break;

		//make sure its an all numeric number
		if(!isNumericString(CreditCardNumber)){
			cout << "Input must be all numeric" << endl;
			continue;
		}

		//Check validity with Luhn Algorithm
		if(!isLuhnValid(CreditCardNumber)){
			cout << "This is not a valid credit card number" <<endl;
			continue;
		}

		cout << "This credit card number is valid." <<endl;

	}
	
	return 0;

}