#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 1000 
#include<conio.h>
struct chuhu{
	char idnum[9];//账户 
	char name[10];//姓名
	char idnumber[20];//省份证号
   char password[7];//密码 
   double cunkuan;//存款 
}hu[N]; 

void date();//显示当前日期
int a,a1;//主界面选择变量 
void Flag1();//主界面
void Flag2();//用户界面 
void Flag3();//用户功能选择界面
void zhuce();//注册 
int yanzheng();//验证存单号或密码 
//&&&&&&&&&&&&&&&&&&&&&&&
void qukaun();//取款
void cunkaun();//存款
void display();//查询
void zhuan();//转账 
void xiugai();//密码修改 
void display();//查找 
//&&&&&&&&&&&&&&&&&&&&&&&&&&
 int A,key;//开户人数 
 int i;//控制密码循环 
 char ch='y';//是否继续注册 
 double jin;//存的钱 
 int t;

 char id[11],password[7];

int main(){
system("COLOR 0A"); int b;
	Flag1();//引入主界面
	do{

	printf("\n\n\t\t##请输入你的选择：");
	scanf("%d",&a); 
	switch(a){
		case 1:{
			zhuce();//zhuce
			Flag1(); 
			break;
		}
		case 2:{
			b=yanzheng();
			fflush(stdin);///好东西，以防跳过数据
			Flag2();
			break;
		} 
		case 3:exit(0);break;
		default:printf("\n\n\n\t\t您输入的数据不符合要求!!!\n\n\n\n\n");
		
	}

	}while(1);
}


void Flag1(){
	printf("\n#################################################################################\n");
    printf("\n▓                          * 银行定期储蓄管理系统  *                           ▓\n");
    printf("\n#################################################################################\n");
	printf("\n          ◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆\n");
	printf("          |◆|******|◆|                                     |◆|******|◆|\n");
	printf("          |◆|******|◆|       ☆ 开户业务    请按 1         |◆|******|◆|\n"); 
	printf("          |◆|******|◆|       ☆ 登录系统    请按 2         |◆|******|◆|\n");
	printf("          |◆|******|◆|       ☆ 退出        请按 3         |◆|******|◆|\n");
	printf("          |◆|******|◆|                                     |◆|******|◆|\n");
	printf("          ◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆\n");
	printf("\n#################################################################################\n");
	
} 
//********************************************************************************************************************

//用户界面 
void Flag2(){
       int a,b;//选择功能的变量
	   do{
	   	printf("\n\n按ENTER键进入、返回主菜单 " ) ;
	   	fflush(stdin);
	   	scanf("%c",&ch);
	   	system("cls");//清屏
		   date(); 
	printf("\n#################################################################################\n");
    printf("\n▓                               * 欢迎使用  *                                 ▓\n");
    printf("\n#################################################################################\n");
	printf("\n          ◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆\n");	
	printf("          |◆|******|◆|        ☆ 存款业务       请按 1        |◆|******|◆|\n"); 
	printf("          |◆|******|◆|        ☆ 取款业务       请按 2        |◆|******|◆|\n");
	printf("          |◆|******|◆|        ☆ 查询业务       请按 3        |◆|******|◆|\n"); 
	printf("          |◆|******|◆|        ☆ 转账业务       请按 4        |◆|******|◆|\n");
	printf("          |◆|******|◆|        ☆ 修改密码       请按 5        |◆|******|◆|\n");
	printf("          |◆|******|◆|        ☆ 退出系统       请按 6        |◆|******|◆|\n"); 
	printf("          |◆|******|◆|                                        |◆|******|◆|\n");
	printf("          ◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆◆\n");
    printf("\n#################################################################################\n");
    printf("\n▓                          *******************************                    ▓\n");
    printf("\n#################################################################################\n");
	printf("\n\n\t\t##请输入你的选择：");
	fflush(stdin);
	scanf("%d",&a);
	switch(a){//注册
		case 1: { system("cls");fflush(stdin);cunkaun();break;//存款
			
		} 
		case 2:  {system("cls");fflush(stdin);qukaun();break;//取款
	
		}
		case 3: {display();//查询业务
			break;
		}
		case 4:{system("cls");fflush(stdin);zhuan();break;//转账 
		
		}
		case 5: {system("cls");fflush(stdin);xiugai();break;//密码修改
		
		}
		case 6: exit(0);
		default:printf("您输入的选择有误，请输入正确的选项：");
	                                            	         
	}
	 } while(1);
} 
//********************************************************************************************************************
//用户功能选择界面 
void Flag3(){
	printf("\n\n\t\t##请输入你的选择：");
	scanf("%d",&a1);
	switch(a1){
		case 1:printf("存款业务");break; 
		case 2:printf("取款业务");break; 
		case 3:printf("查询业务");break; 
		case 4:printf("转账业务");break; 
		case 5:printf("密码修改");break;
		case 6:printf("退出");break;  
	} 
}
//********************************************************************************************************************
//开户 
void zhuce(){
	FILE *nchuhu=fopen("chuh.txt","r");
	FILE *fchuhu=fopen("chuh.txt","a");
	int i;
	if((nchuhu=fopen("chuh.txt","r"))==NULL) printf("文件无，系统创建\n"); 
	do{
	 system("cls");
	date();//显示当前日期 
	printf("\n\n\t\t请输入新储户的信息：");
	fscanf(nchuhu,"%s\t%s\t%s\t%s\t%lf\n",&hu[A].idnum,&hu[A].name,&hu[A].idnumber,&hu[A].password,&hu[A].cunkuan); 
	
	printf("\n\n\t\t储户存单：");
	fflush(stdin);
	gets(hu[A].idnum);
	printf("\n\t\t姓名：");
	fflush(stdin);
	gets(hu[A].name);
	printf("\n\t\t储户密码（6位）：");
	for(i=0;i<6;i++){
		fflush(stdin);
		hu[A].password[i]=getch();
		printf("*");
	//	scanf("%d",&hu[A].password[i]);
	} 
	
	do{
		printf("请输入省份证号码(18位)：");
		fflush(stdin);
		gets(hu[A].idnumber);
		if(strlen(hu[A].idnumber)!=18)//strlen 代表的意思
		printf("\n\t\t输入错误！\n\t\t身份证请输入18位数字或者字母\n");
		for(i=0;i<A;i++)
		if(strcmp(hu[A].idnumber,hu[i].idnumber)==0&&strcmp(hu[A].name,hu[i].name)==0) 
		break;
		
		if(i<A) 
		  printf("\n\n\t\t前面已经有人用此身份证注册过\n\n\t\t请重新输入省份证号：\n");
		  	 
	}while((strlen(hu[A].idnumber)!=18)||(strcmp(hu[A].idnumber,hu[i].idnumber)==0)&&(strcmp(hu[A].name,hu[i].name)!=0) );
	
	printf("输入存储的金额：");
	fflush(stdin);
	scanf("%lf",&hu[A].cunkuan);
	
	fprintf(fchuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[A].idnum,hu[A].name,hu[A].idnumber,hu[A].password,hu[A].cunkuan);
	A++;
	printf("是否继续是(y)/否(n)?");
	fflush(stdin);
	scanf("%c",&ch); 
	}while(ch=='y'||ch=='Y');
	printf("存入成功！");
//	system("pause");
	system("cls");
	fclose(nchuhu);
	fclose(fchuhu);
}
//********************************************************************************************************************
//验证存单号或密码 
int yanzheng(){
	FILE *fchuhu=fopen("chuh.txt","r");
	int count=0;
	char id[9];
	for(i=0;i<=100;i++){
		fscanf(fchuhu,"%s\t%s\t%s\t%s\t%lf\n",&hu[i].idnum,&hu[i].name,&hu[i].idnumber,&hu[i].password,&hu[i].cunkuan);
	}
	do{
		system("cls");
			    printf("\n\n\n\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
				printf("\t\t|#|                                                          |#|\n");
				printf("\t\t|#|                    ☆☆☆☆☆☆☆☆☆☆                  |#|\n");
				printf("\t\t|#|                    ☆                ☆                  |#|\n");
				printf("\t\t|#|             ☆   存单号或者密码有误自动返回   ☆         |#|\n");
				printf("\t\t|#|                    ☆                ☆                  |#|\n");
				printf("\t\t|#|                    ☆☆☆☆☆☆☆☆☆☆                  |#|\n");
				printf("\t\t|#|                                                          |#|\n");
				printf("\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
		printf("\n\n\n\t\t      请输入您的存单号：  ");
		scanf("%s",&id);
		printf("\n\n\n\t\t      请输入您的密码：  ");
		for(i=0;i<6;i++){
			fflush(stdin);
		password[i]=getch();
			printf("*");
		} 
		password[6]='\0';
		fflush(stdin);
		scanf("c",&ch);
		printf("\n\n\t\t");
		for(i=0;i<99;i++){
			if(strcmp(id,hu[i].idnum)==0&&strcmp(password,hu[i].password)==0){
				fclose(fchuhu);
				return 0;
			}
		}
		
		
	}while(count==0);
	fclose(fchuhu);
	return count;
}
//********************************************************************************************************************
//********************************************************************************************************************
//存款
void cunkaun(){
	FILE *fchuhu=fopen("chuh.txt","r");
	FILE *achuhu=fopen("back.txt","w");
	char id[9];int i;
	if(!fchuhu) printf("不能打开文件：");
	if(!achuhu) printf("不能创建文件");
	for(i=0;i<=100;i++){
	fscanf(fchuhu,"%s\t%s\t%s\t%s\t%lf\n",&hu[i].idnum,&hu[i].name,&hu[i].idnumber,&hu[i].password,&hu[i].cunkuan);
	}	//
	int x=0;
		date();
		printf("\n\n\t\t##请再次输入并确认存单：");
		scanf("%s",&id);
		for(i=0;i<=100;i++){
			if(strcmp(id,hu[i].idnum)==0){		
		   printf("\n\n"); 
	 		printf("\t\t||================================================================||\n");
	 		printf("\t\t||                           *存款金额*                           ||\n");
	 		printf("\t\t||================================================================||\n");
	 		printf("\t\t||                                                                ||\n");
	 		printf("\t\t||                                                                ||\n");
	 		printf("\t\t||         1、200        2、400        3、600        4、800       ||\n");
	 		printf("\t\t||                                                                ||\n");
	 		printf("\t\t||                                                                ||\n");
	    	printf("\t\t||         5、1000        6、2000        7、4000        8、6000   ||\n");
	 		printf("\t\t||                                                                ||\n");
	 		printf("\t\t||================================================================||\n");
	 		printf("\t\t||================================================================||\n");
	 		printf("\n\n\t\t\t请输入你的取款金额：");
	 		scanf("%d",&a);
	 		switch(a){
	 			case 1:{jin=200;
	 				 printf("\t\t\t存款%lf元",jin);
			     	printf("\n\n\n\t\t\t^^^^存款成功^^^^"); 
			    	hu[i].cunkuan+=jin;
			    	printf("\n\n\t\t\t$您的余额为：%lf",hu[i].cunkuan);
			    	fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				 }
				 case 2:{jin=400;
	 			    printf("\t\t\t存款%lf元",jin);
			     	printf("\n\n\n\t\t\t^^^^存款成功^^^^");  
			    	hu[i].cunkuan+=jin;
			    	printf("\n\n\t\t\t$您的余额为：%lf",hu[i].cunkuan);
				    fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				 }
				 case 3:{
				 	jin=600;
				 	 printf("\t\t\t存款%lf元",jin);
			     	printf("\n\n\n\t\t\t^^^^存款成功^^^^");  
			    	hu[i].cunkuan+=jin;
			    	printf("\n\n\t\t\t$您的余额为：%lf",hu[i].cunkuan);
			    	fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				 }
				 case 4:{
				 		jin=800;
				  printf("\t\t\t存款%lf元",jin);
			     	printf("\n\n\n\t\t\t^^^^存款成功^^^^"); 
			    	hu[i].cunkuan+=jin;
			    	printf("\n\n\t\t\t$您的余额为：%lf",hu[i].cunkuan);
			    	fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				 }
				 	 			case 5:{jin=1000;
	 			 printf("\t\t\t存款%lf元",jin);
			     	printf("\n\n\n\t\t\t^^^^存款成功^^^^"); 
			    	hu[i].cunkuan+=jin;
			    	printf("\n\n\t\t\t$您的余额为：%lf",hu[i].cunkuan);
			    	fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				 }
				 case 6:{jin=2000;
	 			 printf("\t\t\t存款%lf元",jin);
			     	printf("\n\n\n\t\t\t^^^^存款成功^^^^"); 
			    	hu[i].cunkuan+=jin;
			    	printf("\n\n\t\t\t$您的余额为：%lf",hu[i].cunkuan);
				    fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				 }
				 case 7:{
				 	jin=4000;
				  printf("\t\t\t存款%lf元",jin);
			     	printf("\n\n\n\t\t\t^^^^存款成功^^^^"); 
			    	hu[i].cunkuan+=jin;
			    	printf("\n\n\t\t\t$您的余额为：%lf",hu[i].cunkuan);
			    	fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				 }
				 case 8:{
				 		jin=6000;
				 	 printf("\t\t\t存款%lf元",jin);
			     	printf("\n\n\n\t\t\t^^^^存款成功^^^^"); 
			    	hu[i].cunkuan+=jin;
			    	printf("\n\n\t\t\t$您的余额为：%lf",hu[i].cunkuan);
			    	fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				 }
				 default:printf("\n\n\n\t\t\t您的选择金额不在服务范围内！！！\n\n\n\t\t\t请重新选择业务："); 
				 
			 }			
				fclose(fchuhu);
	            fclose(achuhu);
            	system("del chuh.txt");
              	rename("back.txt","chuh.txt");//rename(旧的，新的） 
                break;		
				}
				}
			}

//*******************************************************************************************************************
//取款 
void qukaun(){
	FILE *fchuhu=fopen("chuh.txt","r");
	FILE *achuhu=fopen("back.txt","w");
	int i;
	char id[9];
	if(!fchuhu) printf("不能打开文件：");
	if(!achuhu) printf("不能创建新文件：");
	for(i=0;i<=100;i++){
	fscanf(fchuhu,"%s\t%s\t%s\t%s\t%lf\n",&hu[i].idnum,&hu[i].name,&hu[i].idnumber,&hu[i].password,&hu[i].cunkuan);
	}

	 	date();
	 	printf("\n\n\t\t请再次输入并确认存单：");
	 	scanf("%s",&id);
	 	for(i=0;i<=99;i++){
	 		if(strcmp(id,hu[i].idnum)==0){
	 	    printf("\n\n"); 
	     	printf("\t\t||================================================================||\n");
	 		printf("\t\t||                           *取款金额*                           ||\n");
	 		printf("\t\t||================================================================||\n");
	 		printf("\t\t||                                                                ||\n");
	 		printf("\t\t||                                                                ||\n");
	 		printf("\t\t||         1、200        2、400        3、600        4、800       ||\n");
	 		printf("\t\t||                                                                ||\n");
	 		printf("\t\t||                                                                ||\n");
	    	printf("\t\t||         5、1000        6、2000        7、4000        8、6000   ||\n");
	 		printf("\t\t||                                                                ||\n");
	 		printf("\t\t||================================================================||\n");
	 		printf("\t\t||================================================================||\n");
	 		printf("\n\n\t\t\t请输入你的取款金额：");
	 		scanf("%d",&a);
	 		switch(a){
	 			case 1:{jin=200;
	 				printf("\t\t\t取出%lf元",jin);
			     	printf("\n\n\n\t\t\t^^^^取款成功^^^^"); 
			    	hu[i].cunkuan-=jin;
			    	printf("\n\n\t\t\t$您的余额为：%lf",hu[i].cunkuan);
			    	fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				 }
				 case 2:{jin=400;
	 				printf("\t\t\t取出%lf元",jin);
			     	printf("\n\n\n\t\t\t^^^^取款成功^^^^"); 
			    	hu[i].cunkuan-=jin;
			    	printf("\n\n\t\t\t$您的余额为：%lf",hu[i].cunkuan);
				    fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				 }
				 case 3:{
				 	jin=600;
				 printf("\t\t\t取出%lf元",jin);
			     	printf("\n\n\n\t\t\t^^^^取款成功^^^^");  
			    	hu[i].cunkuan-=jin;
			    	printf("\n\n\t\t\t$您的余额为：%lf",hu[i].cunkuan);
			    	fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				 }
				 case 4:{
				 		jin=800;
				 printf("\t\t\t取出%lf元",jin);
			     	printf("\n\n\n\t\t\t^^^^取款成功^^^^"); 
			    	hu[i].cunkuan-=jin;
			    	printf("\n\n\t\t\t$您的余额为：%lf",hu[i].cunkuan);
			    	fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				 }
				 	 			case 5:{jin=1000;
	 				printf("\t\t\t取出%lf元",jin);
			     	printf("\n\n\n\t\t\t^^^^取款成功^^^^"); 
			    	hu[i].cunkuan-=jin;
			    	printf("\n\n\t\t\t$您的余额为：%lf",hu[i].cunkuan);
			    	fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				 }
				 case 6:{jin=2000;
	 			printf("\t\t\t取出%lf元",jin);
			     	printf("\n\n\n\t\t\t^^^^取款成功^^^^"); 
			    	hu[i].cunkuan-=jin;
			    	printf("\n\n\t\t\t$您的余额为：%lf",hu[i].cunkuan);
				    fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				 }
				 case 7:{
				 	jin=4000;
				 printf("\t\t\t取出%lf元",jin);
			     	printf("\n\n\n\t\t\t^^^^取款成功^^^^"); 
			    	hu[i].cunkuan-=jin;
			    	printf("\n\n\t\t\t$您的余额为：%lf",hu[i].cunkuan);
			    	fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				 }
				 case 8:{
				 		jin=6000;
				 printf("\t\t\t取出%lf元",jin);
			     	printf("\n\n\n\t\t\t^^^^取款成功^^^^"); 
			    	hu[i].cunkuan-=jin;
			    	printf("\n\n\t\t\t$您的余额为：%lf",hu[i].cunkuan);
			    	fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
					break;
				 }
				 default:printf("\n\n\n\t\t\t您的选择金额不在服务范围内！！！\n\n\n\t\t\t请重新选择业务："); 
				 
			 }
				fclose(fchuhu);
     	        fclose(achuhu);
             	system("del chuh.txt");
             	rename("back.txt","chuh.txt");
				break;
			 }

		 }

}
//********************************************************************************************************************
//转账
void zhuan(){
	FILE *fchuhu=fopen("chuh.txt","r+");
	int i;
	char id[9];
	if(!fchuhu) printf("不能打开文件：");

	for(i=0;i<=100;i++){
	fscanf(fchuhu,"%s\t%s\t%s\t%s\t%lf\n",&hu[i].idnum,&hu[i].name,&hu[i].idnumber,&hu[i].password,&hu[i].cunkuan);
	}

	 	date();
	 	printf("\n\n\t\t请输入转账人的存单号：");
	 	scanf("%s",&id);
	 	for(i=0;i<=99;i++){
	 		if(strcmp(id,hu[i].idnum)==0){
	 	      printf("\n\n\t\t请输入要转账的金额：");
			   scanf("%lf",&jin);
			   printf("\n\n\t\t请确认数目：%lf",jin); 
				 hu[i].cunkuan+=jin;
				 printf("\n\n\n转账成功"); 
				 	fprintf(fchuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[A].idnum,hu[A].name,hu[A].idnumber,hu[A].password,hu[A].cunkuan);
				 		fclose(fchuhu);
	fclose(fchuhu);

				 break;
			 }

		 }

	
} 
//********************************************************************************************************************

//********************************************************************************************************************
void xiugai(){
	FILE *fchuhu=fopen("chuh.txt","r");
	FILE *achuhu=fopen("back.txt","w");
	int j,i;
	char id[9];
	if(!fchuhu) printf("不能打开文件：");
	if(!achuhu) printf("不能创建新文件：");
	for(i=0;i<=100;i++){
	fscanf(fchuhu,"%s\t%s\t%s\t%s\t%lf\n",&hu[i].idnum,&hu[i].name,&hu[i].idnumber,&hu[i].password,&hu[i].cunkuan);
	}

	 	date();
	 	printf("\n\n\t\t请再次输入并确认存单：");
	 	scanf("%s",&id);
	 	for(i=0;i<=99;i++){
	 		if(strcmp(id,hu[i].idnum)==0){
	 		printf("请输入新的密码：\n");
	 			printf("\n\t\t储户密码（6位）：");
	for(j=0;j<6;j++){
		fflush(stdin);
		hu[i].password[j]=getch();
		printf("*");

	} 
				 printf("\n\n\t\t新的密码：%s\n",hu[i].password);
			 
				 printf("\n\n\t\t修改成功"); 
				 	fprintf(achuhu,"%s\t%s\t%s\t%s\t%lf\n",hu[A].idnum,hu[A].name,hu[A].idnumber,hu[A].password,hu[A].cunkuan);
				 		fclose(fchuhu);
	fclose(achuhu);
	system("del chuh.txt");
	rename("back.txt","chuh.txt");
				 break;
			 }

		 }

}

//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//查询信息 
void display(){
	FILE *fchuhu=fopen("chuh.txt","r");
	int i,n=0;
	char fnumb[9];
	system("cls");
	for(i=0;i<=100;i++){
			fscanf(fchuhu,"%s\t%s\t%s\t%s\t%lf\n",&hu[i].idnum,&hu[i].name,&hu[i].idnumber,&hu[i].password,&hu[i].cunkuan);
	}
	
	printf("\n\n●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●\n");
	printf("\n\n              ●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●●                      \n");
	printf("\n\n                              ●●●●●●●●●●●●●●●●●●●●●●●●●●                                              \n");
	printf("\n\n\n\t\t\t\t\t请输入你的存单号：");
	scanf("%s",&fnumb);
	printf("\n\n\n");
	printf("\t\t\t\t\t您的个人信息如下：");
	printf("\n\n");
	for(i=0;i<=99;i++)
		if(strcmp(fnumb,hu[i].idnum)==0){
				printf("存单号：%s\t姓名：%s\t身份证：%s\t密码：%s\t存款金额：%lf\n",hu[i].idnum,hu[i].name,hu[i].idnumber,hu[i].password,hu[i].cunkuan);
				n=1;
				fclose(fchuhu);
				system("pause"); 
	            break; 
		}
if(n==0) printf("此账单不存在！！！\n");
fclose(fchuhu);

}

//********************************************************************************************************************
void date(){//显示当前日期
printf("当前日期：");
system("date/t");
printf("当前时间：");
system("time/t"); 
	
}

