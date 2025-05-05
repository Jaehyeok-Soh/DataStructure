#pragma once

#define USED		true
#define NOT_USED	false

#define SUCCESS		true
#define FAIL		false

#define GRAPH_UNDIRECTED	1
#define GRAPH_DIRECTED		2

#define SAFE_DELETE(p) if(p) { delete p; p = nullptr; }
#define SAFE_DELETE_ARRAY(p) if(p) { delete[] p; p = nullptr; }