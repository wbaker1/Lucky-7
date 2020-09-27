// Wesley Baker's Code
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <vector>
using namespace std;

void one() { // 
	int myArray[] = { 1, 23, 34, 10, 4 }; // Sets the array of 5 integers in this case 1, 23,  34, 10, 4 
	int low = myArray[0];// Sets an empty array for low and high. 
	int high = myArray[0];
	for (int i = 0; i < 5; i++) { // Loops through the array.
		if (high < myArray[i]) { // If the number is higher than the current number in the loop it will skip to check low
			high = myArray[i];// If the number is higher it will the high to the number in the loop. 
		}
		if (low > myArray[i]) { // Same as high explanation. 
			low = myArray[i];
		}
	}
	cout << "High " << high << endl; 
	cout << "Low " << low << endl;
}
void two() {
	int sum{}; // Sets an empty array.
	for (int i = 1; i <= 50; i++) { // Fills the array with numbers from 1 - 50.
		if (i % 7 == 0) { // If the number mod 7 is equal to 0, it will add the number to the sum, adding all multiple of 7.
			sum += i;

		}
	}
	cout << "Sum is " << sum << endl;
}
void three() { 
	int sum = 1; // Set sum to 1 to prevent muliplying 1,2,3,4,5,6,7,8,9,10 by 0.
	for (int i = 10; i > 0; i--) { // Loop backward from ten to zero. 
		cout << i << " * ";
			sum *= i; // Multiply i by whatever is in the sum, starts off by 1, multiplies 1 by 10, then 9 by 10, and so on.
	}
	cout << endl;
	cout << "The product is " << sum << endl;
}
void four() { 
	string original, flipped; // Set two string variables.
	cout << " Enter a word to check ";
	getline(cin, original); // Takes the users input, sets it to the string original 
	for (int i = original.length() - 1; i >= 0; i--) { // Loops through each letter backwards and sets it to the flipped string. 
		flipped += original[i];
	}
	if (original == flipped) { // Compares the original and flipped to see if they are the same word.
		cout << " Yes " << endl;
	}
	else {
		cout << " No " << endl;
	}
}
void five() {
	int prime; // Set an int variable "prime"
	bool checker = true;
	cout << " enter a int : ";
	cin >> prime; // Takes user input and sets it to the prime int variable.
	for (int i = 2; i <= prime / 2; i++) { // Loops to see if prime is divisible by 2.
		if (prime % i == 0) { // If prime is divisible by 2, and comes out as a whole number returns false and breaks out of the loop.
			checker = false;
			break;
		}
	}
	if (checker) { // If checker remains true prints Prime.
		cout << "Prime " << endl;
	}
	else {
		cout << " Not a Prime " << endl;
	}
}

void six() {
	srand(time(NULL)); 
	int sum{};
	int numberArray[100]; // Set a number array to contain 100 ints.
	for (int i = 0; i < 100; i++) { // Loops through 100 random numbers 
		numberArray[i] = rand() % 100 + 1;
		cout << numberArray[i] << " "; // Displays the contents of the array.
	}
	for (int j = 0; j < 100; j++) { // Loops through the array and adds all the numbers together.
		sum += numberArray[j];
	}
	cout << " Average is " << sum / 100 << endl; // Takes the average by dividing the sum of the array by the amount of numbers in the array.
}


int main()
{
	one(); // For One, Two, Three, Four, Five, and Six each method is called from main with Seven being in main itself.
	two();
	three();
	four();
	five();
	six();
	
	// Seven 
	int arraySize = 0; // Set an empty array.
	fstream myFile; // File variable.
	string showWords; // Variable to call upon the contents of the file as a string.
	int biggest = 0; // Sets the biggest variable to 0.

	myFile.open("C:/Users/User/source/repos/Lucky7M/Lucky7M/song.txt"); // Locates the file within the source folder of this program. 
	cout << " How big of an array? ";
	cin >> arraySize; // Takes the user input and sets the array to the user's input
	vector<string> wordArray(arraySize); // Creates a vector that is big enough for the user's input and fill it with x amount of words from the contents of the song.txt.
	for (int i = 0; i < arraySize; i++) { // Loops through the vector and takes the contents of the file and puts them into the string variable showWords.
		myFile >> showWords;
		wordArray.push_back(showWords);
	}
	for (int j = 0; j < wordArray.size(); j++) { // Fills the vector with words from myFile.
		cout << wordArray[j] << " "; 
		if (wordArray[j].size() > wordArray[biggest].size()) { // Checks to see which word from the array contains the most characters.
			biggest = j;
		}
	}
	cout << " Biggest " << wordArray[biggest];
	myFile.close(); // Closes the file after the program is finished.
}
