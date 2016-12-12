#include"randMap.h"

int main(){
	Map m;
	m.size.x=ROW;
	m.size.y=COL;
	for(int i=0;i<m.size.x;++i)
		for(int j=0;j<m.size.y;++j)
			m.table[i][j]=0;
	vector<Room> rooms=createRoom(m,80);
	createRoad(m);
	joinRoad2Room(m,rooms);
	cutRoad(m);
	displayMap(m);
	return 0;
}
