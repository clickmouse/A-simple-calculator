#include <stdio.h>
#include<stdlib.h>
typedef struct calculate
{
	int num;
	char symbol;
	struct calculate*next;
}CAL;
CAL *Creature_Cal();
void Print_Cal(CAL*head);
int main(int argc, char const *argv[])
{
	CAL*head=Creature_Cal();
	Print_Cal(head);
	return 0;
}
CAL* Creature_Cal(){
	CAL*head,*tail,*p;
	head=tail=NULL;
	int num;
	char symbol;
	scanf("%d%c",&num,&symbol);
	do{
		p=(CAL*)malloc(sizeof(CAL));
		p->num=num;
		p->symbol=symbol;
		p->next=NULL;
		if(head==NULL)
			head=p;
		else
			tail->next=p;
		tail=p;
		if(symbol=='=')
			break;
		scanf("%d%c",&num,&symbol);
	}while(p->symbol!='=');
	return head;
}
void Print_Cal(CAL*head){
	int num;
	char symbol;
	int store_num;
	char store_symbol;
	int flag=0;
	CAL*ptr1=head;
	if(head==NULL) return;
	num=ptr1->num;
	symbol=ptr1->symbol;
	do{
		ptr1=ptr1->next;
		if(ptr1==NULL){
/*C*/		printf("%d\n",num);
			return;
		}
		if((symbol=='+'||symbol=='-')&&(ptr1->symbol=='='))
/*AC*/		switch(symbol){
				case '+':
					ptr1->num+=num;
					break;
				default:
					ptr1->num-=num;
			}
		else if((symbol=='*'||symbol=='/')&&(ptr1->symbol=='=')){
/*BC*/		switch(symbol){
				case '*':
					ptr1->num*=num;
					break;
				default:
					ptr1->num/=num;
			}
			if(flag==1){
				switch(store_symbol){
					case '+':
						ptr1->num=store_num+ptr1->num;
						break;
					default:
						ptr1->num=store_num-ptr1->num;
				}
				flag=0;
			}
		}
		else if((symbol=='*'||symbol=='/')&&(ptr1->symbol=='*'||ptr1->symbol=='/'))
/*BB*/		switch(symbol){
				case '*':
					ptr1->num*=num;
					break;
				default:
					ptr1->num/=num;
			}
		else if((symbol=='+'||symbol=='-')&&(ptr1->symbol=='+'||ptr1->symbol=='-'))
/*AA*/		switch(symbol){
				case '+':
					ptr1->num+=num;
					break;
				default:
					ptr1->num-=num;
			}
		else if((symbol=='*'||symbol=='/')&&(ptr1->symbol=='+'||ptr1->symbol=='-')){
/*BA*/		switch(symbol){
				case '*':
					ptr1->num*=num;
					break;
				default:
					ptr1->num/=num;
			}
			if(flag==1){
				switch(store_symbol){
					case '+':
						ptr1->num=store_num+ptr1->num;
						break;
					default:
						ptr1->num=store_num-ptr1->num;
				}
				flag=0;
			}
		}
		else if((symbol=='+'||symbol=='-')&&(ptr1->symbol=='*'||ptr1->symbol=='/')){
/*AB*/		store_num=num;
			store_symbol=symbol;
			flag=1;		
		};
		num=ptr1->num;
		symbol=ptr1->symbol;
	}while(ptr1->symbol!='=');
	printf("%d\n",num);
}