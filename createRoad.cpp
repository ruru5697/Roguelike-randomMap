#include"randMap.h"

void createRoad(Map& m){
	stack<Position> s;
	Position p;
	char direction[5];
	int len=0;
	srand(time(0));
	p.x=p.y=0;
	m.table[0][0]=1;
	s.push(p);
	while(!s.empty()){
		p=s.top();
		len=0;
		if(p.x+2<m.size.x&&m.table[p.x+2][p.y]==0)direction[len++]='U';
		if(p.x-2>=0&&m.table[p.x-2][p.y]==0)direction[len++]='D';
		if(p.y+2<m.size.y&&m.table[p.x][p.y+2]==0)direction[len++]='R';
		if(p.y-2>=0&&m.table[p.x][p.y-2]==0)direction[len++]='L';
		if(len==0){
			s.pop();
			continue;
		}
		len=rand()%len;
		switch(direction[len]){
			case 'U':
				m.table[p.x+1][p.y]=1;
				p.x+=2;
				break;
			case 'D':
				m.table[p.x-1][p.y]=1;
				p.x-=2;
				break;
			case 'L':
				m.table[p.x][p.y-1]=1;
				p.y-=2;
				break;
			case 'R':
				m.table[p.x][p.y+1]=1;
				p.y+=2;
				break;
		}
		m.table[p.x][p.y]=1;
		s.push(p);
	}
}
