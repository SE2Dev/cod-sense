#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <string.h>

#include "../parser/gsc.tab.hpp"

#include "operator_enum.h"
#include "symbol_enum.h"
#include "../util/location.h"
#include "../util/llist.h"

//
// A symbol consists of symbol meta-data
// and also represent's a linked-list of symbols
// for each child, a new list is defined
//
class Symbol : public LList<Symbol>
{
	protected:
		SYMBOL_TYPE type;
	
		Symbol* parent;
		
		Symbol* prev;
		Symbol* next;
		
		//
		// A list of children for this symbol
		//
		Symbol* children;
		
		Range location;		
		
	public:
		Symbol(void);
		Symbol(YYLTYPE loc);
		
		~Symbol();
		
		void AddChild(Symbol* child);
		virtual void PrintInfo();
		void PrintInfoRecursive(int indentLevel = 0);
		
		void _debug_override_type(SYMBOL_TYPE type);
};

//
// Include any child class types AFTER Symbol is defined
//
#include "include.h"
#include "animtree.h"
#include "function.h"

#include "expression.h"
#include "identifier.h"
#include "reference.h"
#include "pointer.h"
#include "string.h"
#include "group.h"
