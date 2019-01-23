#include<cstdio> 
#include<ctime> 
#include<conio.h> 
#include<windows.h>
#include<cstdlib> 
#include<cstring>
#include<iostream>
#include <cmath>
#include<fstream>
#define SIZE 200

#define MYPI 3.141592/////bioriddum  
using namespace std;
/////////����ϰԺ��̱����ؼ� �Լ�����Ѱ� �տ� ����  
char* salloc(int len);	//0.���ڿ� �����Ҵ� 
void input_data(char *buf, char *who);	//1.���ڿ��� �Է¹��� c
char* search_question(char *input, int teach);	//2.������ ���� ����� ã�Ƽ� ����, ������ "" 
void print_answer(char *output);	//3.����� ����Ʈ ���� 
void teach_answer(char *buf);	//4.����� ���Ͽ� �Է��ϰ��� 
void next_line(FILE *file, int line);	//5.line��ŭ �����ٷ� �̵� 
char* nfgets(char *buf, int max, FILE *file);	//6.���๮�ڸ� ���� �����Է� 
void log_save(char* input, char* output, char* user_name); //7.Log���� ���� 
int filtering(char *input);	//8.�� ���͸� 
void textcolor(int color_number);	//0 - ������/*1 - �Ķ���2 - �ʷϻ�3 - ����4 - ������5 - ���ֻ�6 - �����7 - ���8 - ȸ��9 - ���� �Ķ���
void calendar(int year,int month);///�޷±�� �߰� ���ؼ�  
int isLunarYear(int _year);
int howManyDaysInMonthOfYear(int _year, int _month);
int howManyDays(int _year, int _month, int _day);

static int TODAY_DAY=21;
static int TODAY_YEAR=2017;
static int TODAY_MONTH=12;
class baseballgame 
{ 
private:  
  int number[3]; // 3�ڸ� ���ڸ� ���������
public: 
  baseballgame(){
  srand((unsigned)time(NULL)); 
  number[0] = rand() % 10; 
  // �Ʒ� do while�� ù��° ���ڿ� �ߺ����� �ʰ� �ϱ� ���ؼ�. 
  do{ 
      number[1] = rand()%10; //������ 
  } while(number[0] == number[1]); 
 
  do { 
      number[2] = rand()%10; //  ������ 
  } while((number[2] == number[1]) || (number[2] == number[0])); 
} 
  
  int CountOfStrike(int parm_guess[]){
  	int count = 0; 
  for(int i = 0; i < 3; i++){ 
      if(number[i] == parm_guess[i]) count++; 
  } 

  return count; 
} 
  
  int CountOfBall(int parm_guess[]){
  	int count = 0; 

  for(int i = 0; i < 3; i++){ 
      for(int j = 0; j < 3; j++) 
          if((i != j) && (number[i] == parm_guess[j])) count++; 
  } 

  return count; 
} 
  
  void ShowScoreData(){
  	cout << "������ [" << number[0] << number[1] << number[1] << "]�Դϴ�." << endl;
  }
}; 


/////////////////////////////���⼭���� �����Լ�  
int main() { 
MessageBoxA(NULL, "jarvis�� ������ ������ ����մϴ�   \n jarvis �� ����ġ�� �ʹٸ� \"/t ����\" �������� ���ּ���. \n+)��ȭ�� �����ϰ� �ʹٸ� \"���� \"�� �Է��� �ּ���\n ������: ���ؼ�", "jarvis ��뼳��", MB_OK); 
int i, j, k; 
char *buf; int teach; char *input; char *output; char user_name[20]; 
buf = salloc(SIZE); 
srand((unsigned)time(NULL)); input_data(user_name, "����� �̸�");
while (true) { teach = 0;  
input_data(buf, user_name); //buf�� �Է¹��� 
input = salloc(strlen(buf) + 1); //input�� bufũ�⸸ŭ �����Ҵ�(�ι��� ����) 
strcpy(input, buf); //input�� buf�� ���� //INPUT CHECK 
if (filtering(input) == 1) { //������ intput free�ϰ� continue() 
free(input); continue; }	
if (!strcmp("����", input)) {	//"�߰�"�Է½� �ɽ��� ���� 
MessageBoxA(NULL, "jarvis�� �����մϴ�. \n������ : ������,���ؼ� ", "jarvis : ���δ� ������ �˰ڽ��ϴ�", MB_OK); 
break; } 
if(!strcmp("����",input)){
	
	MessageBoxA(NULL, "�߱����� 20ȸ�ȿ� ���߾���մϴ�. ", "jarvis : ���δ� ������ ���� �غ��߽��ϴ�.", MB_OK); 
	 

	baseballgame mygame; 
  int strike = 0, ball = 0, guess[3];  /////���� ��������  
    for(int count = 1; count <= 20; count++){ 
      cout << endl << "[" << count << "] ���ڸ� ���ڸ� �����غ��ʼ�> :"; 
       for(int i = 0; i < 3; i++){
	    cin >> guess[i];
	    
	}	
      strike = mygame.CountOfStrike(guess);  // ��Ʈ����ũ�� ������ ���ϴ� �Լ� ȣ�� 
      ball = mygame.CountOfBall(guess);      // ���� ������ ���ϴ� �Լ� ȣ��.. 

      cout << "[" << strike << "]��Ʈ����ũ [" << ball << "]��" << endl; 

      // ��Ʈ����ũ�� 3����� ���ڸ� ������̴�. 
      if(strike == 3){ 
          cout << count + 1 << "ȸ���� �����ϼ̽��ϴ�.���δ� " << endl; 
          
          break;
		  
      } 

      if(strike != 3 && count == 19){ 
          cout << "20ȸ�� Ƚ���� �ʰ��Ͽ����ϴ� ���δ� " << endl; 
          mygame.ShowScoreData(); 
          break; 
      } 
  }  


} 
if (!strcmp("�޷�",input)){
		MessageBoxA(NULL, "�޷� ����� �����մϴ� ", "jarvis : ���δ� ���ϴ� �⵵�� ���� �Է��Ͻø� �˴ϴ� .", MB_OK);
			
				int year=0,month=0;
	cout<<"������ �Է��Ͻÿ�";cin>>year;
	cout<<endl;
	cout<<"�޼��� �Է��ϼ���";cin>>month;
	cout<<endl;
	cout<<"��\t ��\t ȭ\t ��\t ��\t ��\t ��"<<endl;
	calendar(year,month);
} 
if(!strcmp("���̿�����",input)){
	MessageBoxA(NULL,"���̿� ������ �����մϴ� ","jarvis:���δ��� ���� ��ü,����,���� ��ġ�������ϰڽ��ϴ�",MB_OK);
	int y;
	int m;
	int d;
	cout<<"�¾ �⵵�� �Է��ϼ��� ";cin>>y;
	cout<<endl;
	cout<<"�¾ ���� �Է��ϼ��� ";cin>>m;
	cout<<"�¾ ���� �Է� �ϼ��� ";cin>>d;
	int days = howManyDays(y, m, d);
	cout<<"�������"<<y<<"��"<<m<<"��"<<d<<"�� �����"<<endl; 
	cout<<"���δ���"<<TODAY_YEAR<<"��"<<TODAY_MONTH<<"��"<<TODAY_DAY<<"�ϱ�������"<<days<<"�� ��ŭ ��̽��ϴ�"<<endl;
	double physical = sin((2.0*MYPI*days) / 23.0);
	double emotional = sin((2.0*MYPI*days) / 28.0);
	double intelligence = sin((2.0*MYPI*days) / 33.0);
	cout<<"��ü����:"<<physical<<endl;
	cout<<"��������:"<<emotional<<endl;
	cout<<"��������:"<<intelligence<<endl;
	

	
	
}
if (!strncmp(input, "/t ", 3)) { //if �ɽ��� ����ġ�� /t ���� ���� �϶� 
input = input + 3; //�տ� '/t '�� input���� ���� 
teach = 1; }

strcpy(buf, search_question(input, teach)); 
//input�� �´� output�� ã�Ƽ� buf�� ����, ������ NULL 
output = salloc(strlen(buf) + 1); //output�� bufũ�⸸ŭ �����Ҵ�(�ι��� ����) 
strcpy(output, buf); //output�� buf�� ���� 

if (strcmp(output, "")) { //-������ ���� ���������� 
if (teach == 1) { // ����ġ�� �����϶� 
cout<<"�̹� jarvis�� �˰��ִ� �����Դϴ�"<<endl<<endl;
input = input - 3; //�Ҵ� ���� ��ŭ free�ϱ� ���� �ٽ� input�� ũ�⸦ ������� ���� 
} 
else { log_save(input, output,user_name); //INPUT�� OUTPUT�� ���������� ��µǾ����� ���� 
} 
print_answer(output); //output�� ��� 
} 
else { //-������ ��ġ�ϴ� ����� ������� 
cout<<"jarvis�� �н��ɷ����ִ·κ��Դϴ� ������ �ּ���"<<endl<<endl; 
teach_answer(input); //jarvis ����ġ�� 
if (teach == 1) 
input = input - 3; //�Ҵ� ���� ��ŭ free�ϱ� ���� �ٽ� input�� ũ�⸦ ������� ���� 
} //FREE 
free(input); 
free(output); }
 }

char* salloc(int len) { 
return (char*)malloc(sizeof(char)*len); //len ��ŭ �����Ҵ� 
}

void input_data(char *buf, char *who) { 
fflush(stdin); //�Է���ġ �ʱ�ȭ 
while (true) { //�ƹ��͵� �Է¾��ϸ� �ݺ� -> �Է��Ҷ� ���� �ݺ�	//���� : 
textcolor(2); cout<<who<<":";  
textcolor(7); nfgets(buf, SIZE, stdin); cout<<endl; //������ SIZE��ŭ ����Ʈ stdin -> �����ġ 
if (strcmp(buf, "")) 
break; //�ԷµǸ� �ݺ��� Ż�� 
} 
}

char* search_question(char *input, int teach) { 
FILE *fp; int output_num, random, check = 0, i; 
char *buf; char *similar; buf = salloc(SIZE); similar = salloc(SIZE); 
if ((fp = fopen("������.txt", "r")) == NULL) 
return ""; //������ ������ ���� 

for (i = 0; i < 2; i++) { //�� 2�� ������ Ž�� i - 0.�Ϻ��� ��ġ�ϴ°�, 1.���� ��ġ�ϴ°� 
while (!feof(fp)) { //���� ������ Ž�� 
fscanf(fp, "%d", &output_num); //������ ���� ����� output_num�� ���� 
nfgets(buf, SIZE, fp); //buf�� ���� ���� 
if (i == 0 && !strcmp(input, buf)) check = 1;//������ �Ϻ��� ��ġ�ϴ°� 
if (i == 1 && strlen(buf) > 3 && strstr(input, buf) != NULL) { //if ������ ������ �ִ°� 
check = 1; 
if (teach == 0) 
printf("\n���ϴ� ����� �ƴҰ�� \"/t ����\" �� ���� ������ �ּ���.\n\n"); } 
if (check == 1) { 
random = rand() % output_num; //������ ���� ����� ���� �������� ���� 
next_line(fp, random); //����� ������� �̵� 
nfgets(buf, SIZE, fp); //����� buf�� ���� 
fclose(fp); return buf; //������ ����� ���� 
} 
next_line(fp, output_num + 1); //���� ������ �ִ� ������ġ�� �̵� 
} 
if (teach == 1) 
break; 
rewind(fp); //����Ž�� ��ġ�� ó������ ���� 
} fclose(fp); 
return ""; }

void print_answer(char *output) { textcolor(14); 
cout<<"����jarvis��������������������������������������������������������������������"<<endl; 
cout<<output<<endl; 
cout<<"��������������������������������������������������������������������������������"<<endl<<endl; 
textcolor(10); 
}

void teach_answer(char *input) { 
char buf[SIZE]; int num, i; FILE *fp; fp = fopen("������.txt", "a"); 
textcolor(14); printf("����ĥ ����� ������ �Է��� �ּ���( 0 �Է½� ��ŵ )"); 
textcolor(7); scanf("%s", &buf); num = atoi(buf); 
if (num == 0) { 
fclose(fp); return; 
} 
fprintf(fp, "%d%s\n", num, input); //����� ������ ������ ���� 3�ȳ�
for (i = 0; i < num; i++) { //����� ������ŭ for�� �ȳ�ȳ� 
input_data(buf, "TEACH"); //TEACH : ����� �Է¹��� �� �ȳ� 
fprintf(fp, "%s\n", buf); //�Է¹��� ����� ���Ͽ� ���� �ݰ��� 
} fprintf(fp, " \n"); //���� ó�� 
fclose(fp); }

void next_line(FILE *file, int line) { 
int i;
 for (i = 0; i < line; i++) { 
 while (!feof(file)) { if (fgetc(file) == '\n') 
 break; 
 }
  }
   } 

char* nfgets(char *buf, int max, FILE *file) { 
fgets(buf, max, file); //���ٺҷ��� 
buf[strlen(buf) - 1] = '\0'; //���๮��(����)�� �������� 
return buf; //���๮�� �����Ѱ� ����
 }

void log_save(char* input, char* output, char* user_name){ 
FILE *fp; 
fp = fopen("��ȭ���.txt", "a"); 
fprintf(fp, "%s : %s \n jarvis : %s\n", user_name, input, output); fclose(fp); 
}

int filtering(char *input) { int i, j; if (strstr(input, "�ù�") != NULL || strstr(input, "������") != NULL) { 
for (i = 0; i < 5; i++) { 
MessageBoxA(NULL, "������������.\n���δ� ?\n���Ͻǰ���??", "���������ô�!", MB_OK); { } 
for (j = 0; j < 2; j++){ 
MessageBoxA(NULL, "������������.\n jarvis�¿� �Ƚ��ϴ� ?\n��¥��¥��¥���Ͻǰ���??", "���������ô�!", MB_OK); 
}
 } 
 return 1; 
 } 
 return 0; 
 }
 
 void calendar(int year,int month){
	int day[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int days=0;
	int firstdate=0;
	int count=0;
	days=(year-1)*365+(year-1)/4-(year-1)/100+(year-1)/400;
	for(int i=0;i<month-1;i++){
		if(i==1){
			if((year%4==0&&year%100!=0)||year%400==0)
			day[1]=29;
			else
		day[1]=28;
		}
		days+=day[i];
	}
	firstdate=days%7;
	for(int i=0;i<=firstdate;i++){
		printf("\t");
		count++;
	}
	for(int i=1;i<=day[month-1];i++){
		if(count>=7){
			cout<<endl;
			count=0;
		}
		cout<<i<<"\t";
		count++;
	}
	cout<<endl<<endl;

}
int isLunarYear(int _year)
{
	if (((_year % 4) == 0 && (_year % 100) != 0) || 
		(_year % 400) == 0)
	{
		return 1;
	}
	return 0;

}

int howManyDaysInMonthOfYear(int _year, int _month)
{
	int monthData[] = {0,31, 28, 31, 30, 31, 30, 31,31,30,31,30,31 };
	
	if (isLunarYear(_year) == 1 && _month == 2)
	{
		return 29;
	}
	else
	{
		return monthData[_month];
	}
}

int howManyDays(int _year, int _month, int _day)
{
	int days = 0;
	// year-based counting
	for (int i = _year+1; i < TODAY_YEAR; i++)
	{
		if (isLunarYear(i) == 1)
		{
			days = days + 366;
		}
		else
		{
			days = days + 365;
		}
	}
	for (int i = _month + 1; i <= 12; i++)
	{
		days = days + howManyDaysInMonthOfYear(_year, i);
	}
	for (int i = 1; i <= (TODAY_MONTH-1); i++)
	{
		days = days + howManyDaysInMonthOfYear(TODAY_YEAR, i);
	}
	days = days + TODAY_DAY;
	days = days + (howManyDaysInMonthOfYear(_year, _month) - _day);

	return days;
}
void textcolor(int color_number) { 
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number); 
}


