#include <iostream>
#include <fstream>
#include <cctype>

using std::cout;
using std::endl;
using std::string;

void parse_file(string filedir);

int main() {
    string fileToTranslate;

    cout << "\033[1m                        MORSE CODE TRANSLATOR" << endl;
    cout << "-- --- .-. ... .   -.-. --- -.. .   - .-. .- -. ... .-.. .- - --- .-." << endl << endl;
    
    cout << "\033[0mLocation of file to translate: \033[33m";
    
    std::getline(std::cin, fileToTranslate);
    
    cout << "\033[0m" << endl; // Reset terminal color
    
    parse_file(fileToTranslate);
    return 0;
}

string toMorse(char l) {
    string morse;
    switch (tolower(l)) {
        case 'a': morse = ".-";       break;
        case 'b': morse = "-...";     break;
        case 'c': morse = "-.-.";     break;
        case 'd': morse = "-..";      break;
        case 'e': morse = ".";        break;
        case 'f': morse = "..-.";     break;
        case 'g': morse = "--.";      break;
        case 'h': morse = "....";     break;
        case 'i': morse = "..";       break;
        case 'j': morse = ".---";     break;
        case 'k': morse = "-.-";      break;
        case 'l': morse = ".-..";     break;
        case 'm': morse = "--";       break;
        case 'n': morse = "-.";       break;
        case 'o': morse = "---";      break;
        case 'p': morse = "-.-.";     break;
        case 'q': morse = "--.-";     break;
        case 'r': morse = ".-.";      break;
        case 's': morse = "...";      break;
        case 't': morse = "-";        break;
        case 'u': morse = "..-";      break;
        case 'v': morse = "...-";     break;
        case 'w': morse = ".--";      break;
        case 'x': morse = "-..-";     break;
        case 'y': morse = "-.--";     break;
        case 'z': morse = "--..";     break;
        case '1': morse = ".----";    break;
        case '2': morse = "..---";    break;
        case '3': morse = "...--";    break;
        case '4': morse = "....-";    break;
        case '5': morse = ".....";    break;
        case '6': morse = "-....";    break;
        case '7': morse = "--...";    break;
        case '8': morse = "---..";    break;
        case '9': morse = "----.";    break;
        case '0': morse = "-----";    break;
        case ' ': morse = " ";        break;
        default: morse = l;
    }
    return morse;
}

void parse_file(string filedir) {
    std::ofstream morseFile("morse_" + filedir);

    std::ifstream input(filedir);
    string filestream;

    // Use a while loop together with the getline() function to read the file line by line
    while (std::getline(input, filestream)) {
        // Output the text from the file
        for (char& c: filestream) {
            morseFile << toMorse(c) << "   ";
        }
        morseFile << endl;
    }

    input.close();
    cout << "Translated \033[33m" << filedir << "\033[0;0m into \033[36m" << "morse_" << filedir;
}
