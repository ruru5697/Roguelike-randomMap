#include"randMap.h"

void displayMap(const Map m){
	for(int i=0;i<m.size.x;++i){
		for(int j=0;j<m.size.y;++j){
			if(m.table[i][j])cout<<m.table[i][j];
			else cout<<" ";
		}
		cout<<endl;
	}
}
