﻿#include "Lexer.h"
#include <iostream>
#include <iomanip>

static const char* const names[]{
	"Identifier", "Integer", "Float", "HexNumber", "BigFloat", "BinaryNumber", "Char",
	"String", "Keyword", "LeftRoundBracket", "RightRoundBracket",
	"LeftSquareBracket", "RightSquareBracket", "LeftCurlyBracket", "RightCurlyBracket",
	"LessThan", "GreaterThan", "Equal", "Assignment",
	"Plus", "Minus", "Asterisk", "Slash", "Backslash", "Dot",
	"Comma", "Colon", "Semicolon",
	"End", "EndLine", "Unexpected"
};

int main()
{
	setlocale( LC_ALL, "Russian" );
	Lexer lexer( "in.txt" );
	Token token;
	while ( (token = lexer.GetToken()).type != TokenType::End )
	{
		std::cout << std::setw( 30 ) << std::left << names[token.type];
		std::cout << std::setw( 5 ) << token.row << std::setw( 5 ) << token.col;
		std::cout << std::left << " |" << token.value << "|\n"; 
	}
	std::cout << std::setw( 30 ) << std::left << names[token.type];
	std::cout << std::setw( 5 ) << token.row << std::setw( 5 ) << token.col;
	std::cout << std::left << " |" << token.value << "|\n";
	system( "pause" );
}
