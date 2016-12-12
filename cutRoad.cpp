#include"randMap.h"

void cut(Map&,int,int);
int getcount(Map,int,int);

void cutRoad(Map& m){
	for(int i=0;i<ROW;++i){
		for(int j=0;j<COL;++j){
			if(getcount(m,i,j)==1)
				cut(m,i,j);
		}
	}
}

int getcount(Map m,int i,int j){
	int count=0;
	if(i>0&&m.table[i-1][j])++count;
	if(i<m.size.x-1&&m.table[i+1][j])++count;
	if(j>0&&m.table[i][j-1])++count;
	if(j<m.size.y-1&&m.table[i][j+1])++count;
	return count;
}

void cut(Map& m,int i,int j){
	while(getcount(m,i,j)==1){
		m.table[i][j]=0;
		if(i>0&&m.table[i-1][j])--i;
		else if(i<m.size.x-1&&m.table[i+1][j])++i;
		else if(j>0&&m.table[i][j-1])--j;
		else if(j<m.size.y-1&&m.table[i][j+1])++j;
	}
}
