#ifndef PCH_H
#define PCH_H

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

//////////////////////////////////////////////////////
#include "Define.h"
#include "ArrayList.h"
#include "LinkedList.h"
#include "CircularList.h"
#include "DoublyLinkedList.h"
#include "ArrayStack.h"
#include "LinkedStack.h"

#include "Sort.h"
#include "Search.h"
//////////////////////////////////////////////////////

#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 

#endif
#endif

#endif //PCH_H