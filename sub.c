#include <stdio.h>
#include<stdlib.h>
#include <math.h>
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
	int store_num_plus;
	char store_symbol_plus;
	int store_num_multi;
	char store_symbol_multi;
	int flag_plus=0;
	int flag_multi=0;
	CAL*ptr=head;
	if(head==NULL) return;
	num=ptr->num;
	symbol=ptr->symbol;
	do{
		ptr=ptr->next;
		if(ptr==NULL){
/*C*/		printf("%d\n",num);
			return;
		}
		if((symbol=='+'||symbol=='-')&&(ptr->symbol=='='))
/*AC*/		switch(symbol){
				case '+':
					ptr->num+=num;
					break;
				default:
					ptr->num-=num;
			}
		else if((symbol=='*'||symbol=='/')&&(ptr->symbol=='=')){
/*BC*/		switch(symbol){
				case '*':
					ptr->num*=num;
					break;
				default:
					ptr->num/=num;
			}
			if(flag_plus==1){
				switch(store_symbol_plus){
					case '+':
						ptr->num=store_num_plus+ptr->num;
						break;
					default:
						ptr->num=store_num_plus-ptr->num;
				}
				flag_plus=0;
			}
		}
		else if((symbol=='*'||symbol=='/')&&(ptr->symbol=='*'||ptr->symbol=='/'))
/*BB*/		switch(symbol){
				case '*':
					ptr->num*=num;
					break;
				default:
					ptr->num=num/ptr->num;
			}
		else if((symbol=='+'||symbol=='-')&&(ptr->symbol=='+'||ptr->symbol=='-'))
/*AA*/		switch(symbol){
				case '+':
					ptr->num+=num;
					break;
				default:
					ptr->num=num-ptr->num;
			}
		else if((symbol=='*'||symbol=='/')&&(ptr->symbol=='+'||ptr->symbol=='-')){
/*BA*/		switch(symbol){
				case '*':
					ptr->num*=num;
					break;
				default:
					ptr->num=num/ptr->num;
			}
			if(flag_plus==1){
				switch(store_symbol_plus){
					case '+':
						ptr->num=store_num_plus+ptr->num;
						break;
					default:
						ptr->num=store_num_plus-ptr->num;
				}
				flag_plus=0;
			}
		}
		else if((symbol=='+'||symbol=='-')&&(ptr->symbol=='*'||ptr->symbol=='/'||ptr->symbol=='^')){
/*AB*/		store_num_plus=num;
			store_symbol_plus=symbol;
			flag_plus=1;		
		}
		else if((symbol=='*'||symbol=='/')&&(ptr->symbol=='^')){
			store_num_multi=num;
			store_symbol_multi=symbol;
			flag_multi=1;
		}
		else if((symbol=='^')&&(ptr->symbol=='=')){
/*DC*/		ptr->num=pow(num,ptr->num);
			if(flag_multi==1){
				switch(store_symbol_multi){
					case '*':
						ptr->num=store_num_multi*ptr->num;
						break;
					default:
						ptr->num=store_num_multi/ptr->num;
				}
				flag_multi=0;
			}
			if(flag_plus==1){
				switch(store_symbol_plus){
					case '+':
						ptr->num=store_num_plus+ptr->num;
						break;
					default:
						ptr->num=store_num_plus-ptr->num;
				}
				flag_plus=0;
			}
		}
		else if((symbol=='^')&&(ptr->symbol=='+'||ptr->symbol=='-')){
/*DA*/		ptr->num=pow(num,ptr->num);
			if(flag_multi==1){
				switch(store_symbol_multi){
					case '*':
						ptr->num=store_num_multi*ptr->num;
						break;
					default:
						ptr->num=store_num_multi/ptr->num;
				}
				flag_multi=0;
			}
			if(flag_plus==1){
				switch(store_symbol_plus){
					case '+':
						ptr->num=store_num_plus+ptr->num;
						break;
					default:
						ptr->num=store_num_plus-ptr->num;
				}
				flag_plus=0;
			}
		}
		else if((symbol=='^')&&(ptr->symbol=='*'||ptr->symbol=='/')){
/*DB*/		ptr->num=pow(num,ptr->num);
			if(flag_multi==1){
				switch(store_symbol_multi){
					case '*':
						ptr->num=store_num_multi*ptr->num;
						break;
					default:
						ptr->num=store_num_multi/ptr->num;
				}
				flag_multi=0;
			}
		}
		else if(symbol=='^'&&ptr->symbol=='^')
/*DD*/		ptr->num=pow(num,ptr->num);
		num=ptr->num;
		symbol=ptr->symbol;
	}while(ptr->symbol!='=');
	printf("%d\n",num);
}
