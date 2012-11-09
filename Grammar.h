#ifndef Grammar_h
#define Grammar_h

#include "LinkedList.h"
#include "utils.h"

typedef struct production{
	char from;
	char * word;
}production;

typedef production * Production;

typedef struct grammar{
	char * name;
	char dist;
	char * nonTerminals;
	char * terminals;
	List productions;
}grammar;

typedef grammar * Grammar;


Grammar newGrammar();
void addNonTerminal(Grammar g, char * from);
void addTerminal(Grammar g, char * from);
Production newProduction(Grammar g);
void addProduction(Grammar g, Production p);
Production getLastProduction(Grammar g);
void removeNonTerminal(Grammar g, char c);
void addWord(Production p, char * word);
void printGrammar(Grammar g);

#endif
