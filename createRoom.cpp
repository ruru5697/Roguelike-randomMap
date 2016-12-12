#include"randMap.h"

bool isCollisider(Room a,Room b);

vector<Room> createRoom(Map& m,int count){
	vector<Room> rooms;
	srand(time(0));
	while(count--){
		Room r;
		r.leftup.x=(rand()%(m.size.x/2)+1)*2;
		r.leftup.y=(rand()%(m.size.y/2)+1)*2;
		r.size.x=((rand()%(MAXSIZE))+2)*2;
		r.size.y=((rand()%(MAXSIZE))+2)*2;
		if(r.leftup.x+r.size.x>=m.size.x||r.leftup.y+r.size.y>=m.size.y)continue;
		vector<Room>::iterator it;
		for(it=rooms.begin();it!=rooms.end();++it){
			if(isCollisider(*it,r))break;
		}
		if(it!=rooms.end())
			continue;
		rooms.push_back(r);
		//for(int i=r.leftup.x;i<=r.leftup.x+r.size.x;++i)
		//	m.table[i][r.leftup.y]=m.table[i][r.leftup.y+r.size.y]=2;
		//for(int i=r.leftup.y;i<=r.leftup.y+r.size.y;++i)
		//	m.table[r.leftup.x][i]=m.table[r.leftup.x+r.size.x][i]=2;
		for(int i=r.leftup.x;i<=r.leftup.x+r.size.x;++i)
			for(int j=r.leftup.y;j<=r.leftup.y+r.size.y;++j)
				m.table[i][j]=1;
	}
	return rooms;
}

bool isCollisider(Room a,Room b){
	if(a.leftup.x>b.leftup.x&&a.leftup.x>b.leftup.x+b.size.x)
		return false;
	else if(a.leftup.x<b.leftup.x&&b.leftup.x>a.leftup.x+a.size.x)
		return false;
	else if(a.leftup.y>b.leftup.y&&a.leftup.y>b.leftup.y+b.size.y)
		return false;
	else if(a.leftup.y<b.leftup.y&&b.leftup.y>a.leftup.y+a.size.y)
		return false;
	return true;
}
