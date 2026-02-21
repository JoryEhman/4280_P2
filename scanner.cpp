#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <iostream>
#include "scanner.h"

static int currentLine = 1;

//Column indicies must match driver table ordering:
// 0 → WS
// 1 → " or #
// 2 → Letter
// 3 → Digit
// 4 → Symbol ($ % & ' ( ) * + , - . /)
// 5 → EOF
int classifyChar(int c){

    //Handle EOF first
    if (c == EOF) return 5;

    unsigned char uc = static_cast<unsigned char>(c);

    if (std::isspace(uc)) return 0;

    if (uc == ' ' || uc == '#') return 1;

    if (std::isalpha(uc)) return 2;

    if (std::isdigit(uc)) return 3;

    if (uc >= 36 && uc <= 47) return 4;

    std::cerr << "SCANNER ERROR: invalid character '" << static_cast<char>(uc) <<
        "' at line " << currentLine << std::endl;

    exit(EXIT_FAILURE);
}

//-1 = ERROR, -2 = t1, -3 = t2, -4 = t3, -5 = EOFTk
static const int FSA[6][6] =
    {  0,  1,  3, -1,  5, -5,
      -1, -1, -1,  2, -1, -1,
      -2, -2, -2,  2, -2, -2,
      -1, -1,  3,  4, -1, -1,
      -3, -3, -3,  4, -3, -3,
      -4, -4, -4, -4, -4, -4,};
