#ifndef __RAND_MAP_H__
#define __RAND_MAP_H__

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<stack>

#define ROW 49
#define COL 179
#define MAXSIZE 4

using namespace std;

typedef struct Position{
	int x;
	int y;
}Position;

typedef struct Room{
	Position leftup;
	Position size;
}Room;

typedef struct Map{
	Position size;
	int table[ROW][COL];
}Map;

void createRoad(Map&);
vector<Room> createRoom(Map&,int);
void joinRoad2Room(Map&,vector<Room>);
void displayMap(const Map);
void cutRoad(Map&);

#endif
