// This Program Encrypt and Decrypt the message within XOR Cipher
// Author : Abdallah Kareem Abdallah 
// Version : 2.0

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

// Function to encrypt the message using XOR Cipher
string encrypt(const string& message, const string& key) {
    string encrypted_hex;
    string cipher_text;
    // Iterate over each character in the message
    for (char ch : message) {
        // XOR operation between the character and the corresponding key character
        char temp = ch ^ key[(encrypted_hex.size() / 3) % key.size()];
        // Convert the XOR result to hexadecimal representation
        stringstream ss;
        ss << hex << setw(2) << setfill('0') << static_cast<int>(temp);
        // Append the hexadecimal representation to the encrypted string with a space separator
        encrypted_hex += ss.str() + " ";
        // Append the XOR result character to the cipher text
        cipher_text += temp;
    }
    // Return the encrypted cipher text along with its hexadecimal representation
    return cipher_text + " (Cipher) " + encrypted_hex + "(Hexadecimal)";
}

// Function to decrypt the message encrypted using XOR Cipher
string decrypt(const string& message, const string& key) {
    string hex_to_text;
    // Iterate over the message in pairs to extract each hexadecimal character
    for (size_t i = 0; i < message.size(); i += 3) {
        // Convert the pair of hexadecimal characters to integer
        int temp;
        stringstream ss;
        ss << hex << message.substr(i, 2);
        ss >> temp;
        // Convert the integer to its corresponding character
        hex_to_text += static_cast<char>(temp);
    }

    string decrypted_result;
    // Iterate over each character in the hexadecimal text
    for (char ch : hex_to_text) {
        // XOR operation between the character and the corresponding key character
        char temp = ch ^ key[(decrypted_result.size() / 3) % key.size()];
        // Append the decrypted character to the result
        decrypted_result += temp;
    }
    // Return the decrypted text
    return decrypted_result;
}

int main() {
    int choice;
    // Prompt user to choose encryption or decryption
    cout << "1. Encryption\n2. Decryption\nChoose(1,2): ";
    cin >> choice;

    if (choice == 1) {
        cout << "---Encryption---" << endl;
        string message, key;
        // Clear the input buffer
        cin.ignore();
        // Prompt user to enter message and key
        cout << "Enter message: ";
        getline(cin, message);
        cout << "Enter key: ";
        getline(cin, key);
        // Encrypt the message using XOR Cipher and display the result
        string encrypted = encrypt(message, key);
        cout << "Encrypted Text: " << encrypted << endl;
    } else if (choice == 2) {
        cout << "---Decryption---" << endl;
        string message, key;
        cin.ignore();
        // Prompt user to enter encrypted message (in hexadecimal) and key
        cout << "Enter message (Hexadecimal): ";
        getline(cin, message);
        cout << "Enter key: ";
        getline(cin, key);
        // Decrypt the message using XOR Cipher and display the result
        string decrypted = decrypt(message, key);
        cout << "Decrypted Text: " << decrypted << endl;
    } else {
        // Display error message for invalid choice
        cout << "Invalid Choice" << endl;
    }

    return 0;
}