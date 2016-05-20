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
	int length ;
	void printStauts(){ //打印操作
		for(int i =0; i < length; i++){
			cout<<num[i];
		}
	}

	void add(int i){  //元素压入栈中
		num[length] = i;
		length++;
	}
	
	int getTop(){  //获取栈顶元素
		return num[length-1];
	}

	void del(int key){   //删除栈顶key个元素
		for(int i = 0; i < key; i++){
			length--;
		}
	}

} status;

typedef struct ch {
	char charact[20];
	int length;

	void printCh(){  //打印栈
		for(int i =0; i < length; i++){
			cout<<charact[i];
		}
	}

	void add(char c){  //元素压进栈中
		charact[length] = c;
		length++;
	}

	char getTop(){  //获取栈顶元素
		return charact[length-1];
	}

	void del(int key){  //删除栈中key个元素
		for(int i = 0; i < key; i++){
			length--;
		}
	}
} ch;

status sta;
ch c;

char VT[6] = { 'i', '+', '*', '(', ')', '#' };
char VN[3] = { 'E', 'T', 'F' }; 
R r[7];
int i, j;



type ACTION[6][11];
	int GOTO[3][11];


	int getVT(char c){ //获取终结符位置
	for(int i = 0; i < 6; i++) {
		if(VT[i] == c) return i;	
	}
	return -1;
}

int getVN(char c){   //获取非终结符位置
	for(int i = 0; i < 3; i++) {
		if(VN[i] == c) return i;
	}
	return -1;
}


void init(){ //初始化
	r[1].origin = 'E';   //初始化产生式
	r[1].array = "E+T";
	r[1].length = 3;

	r[2].origin = 'E';
	r[2].array = "T";
	r[2].length = 1;

	r[3].origin = 'T';
	r[3].array = "T*F";
	r[3].length = 3;

	r[4].origin = 'T';
	r[4].array = "F";
	r[4].length = 1;

	r[5].origin = 'F';
	r[5].array = "(E)";
	r[5].length = 3;

	r[6].origin = 'F';
	r[6].array = "i";
	r[6].length = 1;

	
	for(i = 0; i < 20; i++){
		sta.num[i] = 0;
		if(i == 0) sta.length = 0;
	}

	for(i = 0; i < 20; i++){
		c.charact[i] = 0;
		if(i == 0) c.length = 0;
	}


	for(i = 0; i < 6; i++)
	{
		for(int j = 0; j < 12 ;j++){
			ACTION[i][j].first = 'N';
			ACTION[i][j].second = '-1';
		}
	}

	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 12; j++){
			GOTO[i][j] = -1;
		}
	}
	//初始分析表
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

bool isACTION(type Table){   //判断执行ACTION操作 还是归约操作
	if(Table.first == 's') return true;
	else return false;
}


void print(int &k){
		k++;
		cout<<k<<"\t\t";
		sta.printStauts();
		cout<<"\t\t";
		c.printCh();
		cout<<"\t\t";
}



void main() {
	string s;
	int len ;
	int index;
	int k = 0;
	int mstatus;
	char mchract;
	char x;
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
			case ')':
			case '#':break;
			default: {
				cout<<"输入串含非法字符!"<<endl;
				exit(1);
				break;
			}
		}
	}
	cout<<"步骤\t\t"<<"状态栈\t\t"<<"符号栈\t\t"<<"输入串"<<"\t\t"<<"操作说明"<<endl;
	sta.add(0);
	c.add('#');
	do{
		print(k);
		for(int i = s.length()-len; i < s.length(); i++) cout<<s[i];
		cout<<"\t\t";

		index = s.length() - len;
		x = s[index]; //字符串首字母
		mstatus = sta.getTop(); //状态栈首字母
		if(isACTION(ACTION[getVT(x)][mstatus])){
			sta.add(ACTION[getVT(x)][mstatus].second);
			c.add(x);
			len--;
			
			cout<<ACTION[getVT(x)][mstatus].first<<ACTION[getVT(x)][mstatus].second<<"状态"<<ACTION[getVT(x)][mstatus].second<<"入栈"<<endl;
			
			index = s.length() - len;
			x = s[index];//指针移向下一位
		} 
		else {
			if(ACTION[getVT(x)][mstatus].first == 'a') {
				cout<<"acc分析成功"<<endl;break;
			}
			
			cout<<ACTION[getVT(x)][mstatus].first<<ACTION[getVT(x)][mstatus].second<<"归约"<<r[ACTION[getVT(x)][mstatus].second].origin<<"->";
			for(int i = 0; i < r[ACTION[getVT(x)][mstatus].second].length; i++){
				cout<<r[ACTION[getVT(x)][mstatus].second].array[i];
			}
			cout<<endl;

			sta.del(r[ACTION[getVT(x)][mstatus].second].length);
			c.del(r[ACTION[getVT(x)][mstatus].second].length);
			c.add(r[ACTION[getVT(x)][mstatus].second].origin);
			mstatus = sta.getTop();
			mchract = c.getTop();
			sta.add(GOTO[getVN(mchract)][mstatus]);
		}
		

	}while(len != 0);
}