//ANAGRAMS WITH HASHTABLE

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct node{
	char* string;
	struct node* next;
};
struct node* NewNode(char string[]){
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->string = (char*)malloc(sizeof(char)*strlen(string));
	strcpy(temp->string,string);
	temp->next = NULL;
	return temp;
}
struct node** INSERT(struct node* T[],char string[]){
	int val =0;
	if(strchr(string,'a')!=NULL)val = val+1;
	if(strchr(string,'b')!=NULL)val = val+2;
	if(strchr(string,'c')!=NULL)val = val+4;
	if(strchr(string,'d')!=NULL)val = val+8;
	if(strchr(string,'e')!=NULL)val = val+16;
	if(strchr(string,'f')!=NULL)val = val+32;
	if(strchr(string,'g')!=NULL)val = val+64;
	if(strchr(string,'h')!=NULL)val = val+128;
	if(strchr(string,'i')!=NULL)val = val+256;
	
	if(T[val] == NULL){
		T[val] = NewNode(string);
	}
	else{
		struct node* temp = T[val];
		if(strcmp(temp->string,string)>0 && temp->next == NULL){
			struct node* ptr = NewNode(temp->string);
			strcpy(temp->string,string);
			ptr->next = temp->next;
			temp->next = ptr;
			return T;
		}
		while(temp->next != NULL){
			if(strcmp(temp->string,string)>0){
				struct node* ptr = NewNode(temp->string);
				strcpy(temp->string,string);
				ptr->next = temp->next;
				temp->next = ptr;
				break;
			}
			else{
			temp = temp->next;}
		}
		if(temp->next == NULL)temp->next = NewNode(string);
	}
	return T;
}

void PRINT(struct node* T[]){
	int i;
	for(i=0;i<255;i++){
		if(T[i] != NULL){
			struct node* temp = T[i];
			while(temp!= NULL){
				printf("%s",temp->string);
				if(temp->next!= NULL)printf(" ");
				temp = temp->next;
			}
			printf("\n");
		}
	}
}
void main(){
	int i,n;
	
	scanf("%d",&n);
	//int* A = (int*)malloc(sizeof(int)*n);
	
	struct node** T=(struct node**)malloc(sizeof(struct node*)*255);
	for(i=0;i<255;i++)T[i]=NULL;
	char string[50];
	for(i=0;i<n;i++){
		scanf("%s",string);
		T = INSERT(T,string);
	}
	//printf("%s",string);
	PRINT(T);
}
