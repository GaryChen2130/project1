#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

char map1[22][52] = {0},map2[22][52] = {0};
int t,c[4],m[9],mp,rpos,cpos;

void position(int row,int col){

int temp = 1;
rpos = row;cpos = col;
while(map1[rpos][cpos] != ' '){

	if(temp > 3){++cpos;rpos = row;temp = 1;}
	else{++rpos;++temp;}

}

return;

}


int castle(int row,int col){

int i,j,num = 0;
for(i = row;i <= row + 4;++i){

	for(j = col;j <= col + 4;++j){
		if(map1[i][j] != ' ')++num;
	}

}

return num;

}


void protect(int row,int col){

int i,j,temp = 1;

for(i = 0;i < 4;++i){

	if(m[c[i]] <= mp){

		position(row,col);
		cout << 1 << c[i] << rpos << cpos << endl;
		mp -= m[c[i]];

	}

}

return;

}


int main(){

//my cas (9,11);oppisite cas (40 42)
int i,j,k,usg,upr,dsg,dpr,sg,pr,turn = 1,mcas1 = 10,mcas2 = 10,mcas3 = 10,ocas1 = 10,ocas2 = 10,ocas3 = 10,g = 0;
m[1] = 5;m[2] = 3;m[3] = 4;m[4] = 7;m[5] = 1;m[6] = 4;m[7] = 9;m[8] = 5;

cout << "4 2 6 3 1 5 7 8\n";

while(1){

cin >> t >> mp >> c[0] >> c[1] >> c[2] >> c[3];
if(t == 0)break;

sg = 0,pr = 0,usg = 0,upr = 0,dsg = 0,dpr = 0;

for(i = 0;i <= 21;++i){
	for(j = 0;j <= 27;++j){
		map1[i][j] = getchar();
		//if((map1[i][j] == 4) && (i <= 10))++usg;
		//else if((map1[i][j] == 2) && (i <= 10))++upr;
		//else if((map1[i][j] == 4) && (i > 10))++dsg;
		//else if((map1[i][j] == 2) && (i > 10))++dpr;
	}
	for(j = 28;j <= 52;++j)map1[i][j] = getchar();

}

//sg = usg + dsg;
//pr = upr + dpr;

for(i = 0;i <= 21;++i){
	for(j = 0;j <= 52;++j)map2[i][j] = getchar();
}

/*
if(map2[10][3] < mcas2)protect(9,9);
else if(map2[4][8] < mcas1)protect(3,11);
else if(map2[16][8] < mcas3)protect(15,11);
*/
//else{
/*
	for(i = 0;i < 4;++i){

		if(sg > 0){
		
			if(((c[i] == 3) || (c[i] == 6)) && (mp >= m[c[i]])){
			
				if(dsg > 0){
					position(16,20);
					cout << 1 << c[i] << rpos << cpos << endl;
					mp -= m[c[i]];
				}
			
				else if(usg > 0){
					position(5,20);
					cout << 1 << c[i] << rpos << cpos << endl;
					mp -= m[c[i]];
				}

			}

			if(((c[i] == 2) || (c[i] == 5)) && (mp >= m[c[i]]) && (pr < 3)){

				if(dsg > 0){
					position(16,20);
					cout << 1 << c[i] << rpos << cpos << endl;
					mp -= m[c[i]];
				}

				else if(usg > 0){
					position(5,20);
					cout << 1 << c[i] << rpos << cpos << endl;
					mp -= m[c[i]];
				}

			}

		}


		if((c[i] == 8) && (mp >= m[c[i]])){

			if(ocas3 >= 3){
				position(16,20);
				cout << 1 << c[i] << rpos << cpos << endl;
				mp -= m[c[i]];
			}

			else if(ocas1 >= 3){
				position(5,20);
				cout << 1 << c[i] << rpos << cpos << endl;
				mp -= m[c[i]];
			}

			else if((ocas2 >= 3) && (map2[16][43] == ' ')){
				position(16,20);
				cout << 1 << c[i] << rpos << cpos << endl;
				mp -= m[c[i]];
			}

			else if((ocas2 >= 3) && (map2[5][43] == ' ')){
				position(5,20);
				cout << 1 << c[i] << rpos << cpos << endl;
				mp -= m[c[i]];
			}

		}
*/
/*		if((c[i] == 4) && (mp >= m[c[i]])){

			if(dsg == 0){
				position(16,20);
				cout << 1 << c[i] << rpos << cpos << endl;
				mp -= m[c[i]];
			}

			else if(usg == 0){
				position(5,20);
				cout << 1 << c[i] << rpos << cpos << endl;
				mp -= m[c[i]];
			}

		}

	}
*/
//	for(i = 0;i < 4;++i){

		if(mp >= m[c[g]]){

			if(turn%3 != 0){position(16,20);++turn;}
			else{position(5,20);++turn;}
			cout << "1 " << c[g] << " " << rpos << " " << cpos << "\n";
			mp -= m[c[g]];
			++g;

		}
		
		if(g == 3)g = 0;

//	}

//}
/*
mcas1 = map2[4][8];
mcas2 = map2[10][3];
mcas3 = map2[16][8];
ocas1 = map2[4][43];
ocas2 = map2[10][48];
ocas3 = map2[16][43];
*/
cout << "0\n";

}



}



