#include<stdio.h>
 struct Account
{
	
	char name[100];
	char tel[12];
	char Idcard[19];
	char Username[100];
	char password[7];
	float money;
	
};

typedef struct Account Account;

void showChinese()
{
	printf("��1,����\n");
	printf("��2,��¼\n");

}

void showEnglish()
{
	printf("Press 1 , Sign Up\n");
	printf("Press 2 , Sign In\n");
	
}

Account a;
void signUp()
{
	printf("�������������:\n");
	scanf("%s,a.name");
	
	printf("��������ĵ绰:\n");
	scanf("%s,a.tel");
	
	printf("������������֤:\n");
	scanf("%s,a.Idcard");
	
	printf("�������˺�:\n");
	scanf("%s,a.Uesrname");
	
	printf("����������:\n");
	scanf("%s,a.password");
	
	a.money=0.0f;
	
	printf("��ϲ�㣬���ע�ᣡ\n");
	
}

void Englishsignup()
{
	printf("Please enter your name:\n");
	scanf("%s,a.name");
	
	printf("Please enter your tel:\n");
	scanf("%s",a.tel);
	
	printf("Please enter your Idcard:\n");
	scanf("%s",a.Idcard);
	
	printf("Please enter your account:\n");
	scanf("%s",a.Username);
	
	printf("Please enter your password:\n");
	scanf("%s",a.password);
	
	a.money=0.0f;
	
	printf("Finish it !\n");
}

void Signin()
{
	
	
}

void printAccount(Account a)
{
	printf("%s %s %s %s %f\n",a.name,a.tel,a.Idcard,a.Username,a.money);
}

int main()
{
	printf("��1��������ʾ\n");
	printf("Press 2 ,Show English\n");
	int n;
	scanf("%d",&n);
	if(n==1)
	{
		showChinese();
	}
	else if(n==2)
	{
		showEnglish();
	}
	
	int k;
	scanf("%d",&k);
	if(k==1)
	{
		if(n==2)
		{
			Englishsignup();
			printAccount(a);
		}
		else if(n==1)
		{
			signUp();
			printAccount(a);
		}
	}
	else if(k==2)
	{
		Signin();
	}
	
	return 0;
}

