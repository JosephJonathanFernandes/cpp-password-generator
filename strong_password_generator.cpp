#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Character pools
const string LOWER = "abcdefghijklmnopqrstuvwxyz";
const string UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string DIGITS = "0123456789";
const string SPECIAL = "!@#$%^&*";
const string ALL_CHARS = LOWER + UPPER + DIGITS + SPECIAL;

// Initialize seed once
void initRandom() {
    static bool seeded = false;
    if (!seeded) {
        srand(static_cast<unsigned int>(time(0)));
        seeded = true;
    }
}

// Generate a secure password ensuring at least one of each required type
string generateSecurePassword(int length) {
    if (length < 4) return "";

    initRandom();

    vector<char> password;

    // Ensure at least one of each type
    password.push_back(LOWER[rand() % LOWER.length()]);
    password.push_back(UPPER[rand() % UPPER.length()]);
    password.push_back(DIGITS[rand() % DIGITS.length()]);
    password.push_back(SPECIAL[rand() % SPECIAL.length()]);

    // Fill the rest
    for (int i = 4; i < length; ++i) {
        password.push_back(ALL_CHARS[rand() % ALL_CHARS.length()]);
    }

    // Shuffle the password
    random_shuffle(password.begin(), password.end());

    return string(password.begin(), password.end());
}

// Check strength based on presence of character types
string checkStrength(const string& password) {
    bool hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false;

    for (char ch : password) {
        if (islower(ch)) hasLower = true;
        else if (isupper(ch)) hasUpper = true;
        else if (isdigit(ch)) hasDigit = true;
        else if (ispunct(ch)) hasSpecial = true;
    }

    int length = password.length();

    if (length >= 12 && hasLower && hasUpper && hasDigit && hasSpecial)
        return "Strong";
    else if (length >= 8 && hasLower && hasUpper && hasDigit)
        return "Moderate";
    else
        return "Weak";
}

int main() {
    int length;

    cout << "==== Password Generator and Strength Checker ====\n";
    
    while (true) {
        cout << "Enter desired password length (min 4): ";
        cin >> length;

        if (cin.fail() || length < 4) {
            cin.clear(); // Clear input buffer
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number >= 4.\n";
        } else {
            break;
        }
    }

    string password = generateSecurePassword(length);
    string strength = checkStrength(password);

    cout << "\nGenerated Password: " << password << endl;
    cout << "Password Strength: " << strength << endl;

    return 0;
}
