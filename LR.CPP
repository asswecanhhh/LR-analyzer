#include <iostream>
#include <stack>
#include <string>
using namespace std;
typedef struct R {
	char origin;
	int length;
	char *array;
	void print(){
		cout<<origin<<"->";
		for(int i = 0;i < length;i++) cout<<array[i];
		cout<<endl;
	}
} R;

typedef struct type {
	char first;
	int second;
} type;

typedef struct status {
	int num[20];
	int length;
} status;

typedef struct ch {
	char charact[20];
	int length;
} ch;

status sta;
ch c;

char VT[6] = { 'i', '+', '*', '(', ')', '#' };
char VN[3] = { 'E', 'T', 'F' }; 
R r[6];
int i, j;



type ACTION[6][11];
	int GOTO[3][11];

void init(){
	r[0].origin = 'E';
	r[0].array = "E+T";
	r[0].length = 3;

	r[1].origin = 'E';
	r[1].array = "T";
	r[1].length = 1;

	r[2].origin = 'T';
	r[2].array = "T*F";
	r[2].length = 3;

	r[3].origin = 'T';
	r[3].array = "F";
	r[3].length = 1;

	r[4].origin = 'F';
	r[4].array = "(E)";
	r[4].length = 3;

	r[5].origin = 'F';
	r[5].array = "i";
	r[5].length = 1;

	
	for(i = 0; i < 20; i++){
		sta.num[i] = 0;
		if(i == 0) sta.length = 0;
	}

	for(i = 0; i < 20; i++){
		c.charact[i] = 0;
		if(i == 0) sta.length = 0;
	}


	for(i = 0; i < 6; i++)
	{
		for(int j = 0; j < 11 ;j++){
			ACTION[i][j].first = 'N';
			ACTION[i][j].second = '-1';
		}
	}

	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 11; j++){
			GOTO[i][j] = -1;
		}
	}

	ACTION[0][0].first = 's' ,ACTION[0][0].second = 5;
	ACTION[0][4].first = 's' ,ACTION[0][4].second = 5;
	ACTION[0][6].first = 's' ,ACTION[0][6].second = 5;
	ACTION[0][7].first = 's' ,ACTION[0][7].second = 5;

	ACTION[1][1].first = 's' ,ACTION[1][1].second = 6;
	ACTION[1][2].first = 'r' ,ACTION[1][2].second = 2;
	ACTION[1][3].first = 'r' ,ACTION[1][3].second = 4;
	ACTION[1][5].first = 'r' ,ACTION[1][5].second = 6;
	ACTION[1][8].first = 's' ,ACTION[1][8].second = 6;
	ACTION[1][9].first = 'r' ,ACTION[1][9].second = 1;
	ACTION[1][10].first = 'r' ,ACTION[1][10].second = 3;
	ACTION[1][11].first = 'r' ,ACTION[1][11].second = 5;

	ACTION[2][2].first = 's' ,ACTION[2][2].second = 7;
	ACTION[2][3].first = 'r' ,ACTION[2][3].second = 4;
	ACTION[2][5].first = 'r' ,ACTION[2][5].second = 6;
	ACTION[2][9].first = 's' ,ACTION[2][9].second = 7;
	ACTION[2][10].first = 'r' ,ACTION[2][10].second = 3;
	ACTION[2][11].first = 'r' ,ACTION[2][11].second = 5;

	ACTION[3][0].first = 's' ,ACTION[3][0].second = 4;
	ACTION[3][4].first = 's' ,ACTION[3][4].second = 4;
	ACTION[3][6].first = 's' ,ACTION[3][6].second = 4;
	ACTION[3][7].first = 's' ,ACTION[3][7].second = 4;

	ACTION[4][2].first = 'r' ,ACTION[4][2].second = 2;
	ACTION[4][3].first = 'r' ,ACTION[4][3].second = 4;
	ACTION[4][5].first = 'r' ,ACTION[4][5].second = 6;
	ACTION[4][8].first = 's' ,ACTION[4][8].second = 11;
	ACTION[4][9].first = 'r' ,ACTION[4][9].second = 1;
	ACTION[4][10].first = 'r' ,ACTION[4][10].second = 3;
	ACTION[4][11].first = 'r' ,ACTION[4][11].second = 5;

	ACTION[5][1].first = 'a' ,ACTION[5][1].second = 0;
	ACTION[5][2].first = 'r' ,ACTION[5][2].second = 2;
	ACTION[5][3].first = 'r' ,ACTION[5][3].second = 4;
	ACTION[5][5].first = 'r' ,ACTION[5][5].second = 6;
	ACTION[5][9].first = 'r' ,ACTION[5][9].second = 1;
	ACTION[5][10].first = 'r' ,ACTION[5][10].second = 3;
	ACTION[5][11].first = 'r' ,ACTION[5][11].second= 5;

	GOTO[0][0] = 1 ,GOTO[0][4] = 8;
	GOTO[1][0] = 2 ,GOTO[1][4] = 2 ,GOTO[1][6] = 9;
	GOTO[2][0] = 3 ,GOTO[2][4] = 3 ,GOTO[2][6] = 3, GOTO[2][7] = 10;
}

void main() {
	string s;
	int len ;
	init();
	cout<<"请输入输入串包含以下字符（i', +, *, (, )）并以#号结束:"<<endl;
	cin>>s;
	len = s.length();
	for(i = 0; i < len; i++) {
		switch(s[i])
		{
			case 'i':
			case '+':
			case '*':
			case '(':
			case ')': break;
			default: {
				cout<<"输入串含非法字符!"<<endl;
				exit(1);
				break;
			}
		}
	}
	cout<<"步骤\t\t"<<"状态栈\t\t"<<"符号栈\t\t"<<"输入串\t\t"<<"动作说明"<<endl;





	
}