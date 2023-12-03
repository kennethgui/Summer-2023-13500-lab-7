/*
Kenneth Guillont
Kenneth.guillont83@myhunter.cuny.edu
Lab 7 A
*/
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string removeLeadingSpaces(const string& line) {
    string fixIndent;
    bool leading = true;

    for (int i = 0; i < line.length(); ++i) {
        char ch = line[i];
        if (leading && isspace(ch)) {
            continue;
        } else {
            leading = false;
            fixIndent += ch;
        }
    }

    return fixIndent;
}

int countChar(const string& line, char c) {
    int count = 0;

    for (int i = 0; i < line.length(); ++i) {
        if (line[i] == c) {
            ++count;
        }
    }

    return count;
}

int main() {
    string line;
    int openBlocks = 0;
    bool firstLine = true;

    while (getline(cin, line)) {
        int openCurlyBraces = countChar(line, '{');
        int closedCurlyBraces = countChar(line, '}');

        openBlocks += openCurlyBraces - closedCurlyBraces;

        string indentedLine;
        if (firstLine) {
            indentedLine = removeLeadingSpaces(line);
            firstLine = false;
        } else {
            indentedLine = string(openBlocks, '\t') + removeLeadingSpaces(line);

            if (!indentedLine.empty() && indentedLine[0] == '}') {
                --openBlocks;
                indentedLine = string(openBlocks, '\t') + removeLeadingSpaces(line);
            }
        }

        cout << indentedLine << endl;
    }

    return 0;
}
