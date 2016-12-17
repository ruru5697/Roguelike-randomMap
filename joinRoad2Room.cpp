#include"randMap.h"

void joinRoad2Room(Map& m,vector<Room> rooms){
	srand(time(0));
	int len=4;
	Position wallPos,nextPos;
	for(vector<Room>::iterator it=rooms.begin();it!=rooms.end();++it){
	char direction[5]="UDLR";
		int doorCnt=rand()%3+1;
		while(doorCnt){
			int index=rand()%len;
			len=4;
			switch(direction[index]){
				case 'U':
					wallPos.x=it->leftup.x+rand()%(it->size.x-1)+1;wallPos.y=it->leftup.y;
					nextPos.x=wallPos.x;nextPos.y=wallPos.y-2;
					break;
				case 'D':
					wallPos.x=it->leftup.x+rand()%(it->size.x-1)+1;wallPos.y=it->leftup.y+it->size.y;
					nextPos.x=wallPos.x;nextPos.y=wallPos.y+2;
					break;
				case 'L':
					wallPos.y=it->leftup.y+rand()%(it->size.y-1)+1;wallPos.x=it->leftup.x;
					nextPos.x=wallPos.x-2;nextPos.y=wallPos.y;
					break;
				case 'R':
					wallPos.y=it->leftup.y+rand()%(it->size.y-1)+1;wallPos.x=it->leftup.x+it->size.x;
					nextPos.x=wallPos.x+2;nextPos.y=wallPos.y;
					break;
			}
			if(nextPos.x>=m.size.x||nextPos.x<0||nextPos.y>=m.size.y||nextPos.y<0)
				continue;
			if(m.table[nextPos.x][nextPos.y]){
				m.table[(wallPos.x+nextPos.x)/2][(wallPos.y+nextPos.y)/2]=1;
				char t=direction[index];
				direction[index]=direction[len];
				direction[len--]=t;
				--doorCnt;
			}
		}
	}
}
