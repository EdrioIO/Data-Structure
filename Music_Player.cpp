#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
int counter;

struct music{
	char name[100];
	int angka;
	struct music *next;
}*head,*tail,*curr;

char musics[11][100]={	  "IDGAF - Dua Lipa",
					      "FRIENDS - Marshmello, Anne-Marie",
						  "The Middle - Zedd, Maren Morris, Grey",
						  "Best Part - H.E.R., Daniel Caesar",
						  "All The Stars (with SZA) - Kendrick Lamar, LZA",
						  "Wolves - Selena Gomez, Marshmello",
						  "God's Plan - Drake",
						  "Rewrite The Stars - Zac Efron, Zendaya",
						  "Havana - Camila Cabello, Young Thug",
						  "Perfect - Ed Sheeran"};

void push(int angka){
	struct music *temp = (struct music*)malloc(sizeof(struct music));
	temp->angka = angka;
		if(head==NULL){
			head = tail = temp;
			tail->next = NULL;
		}
			else{
				tail->next = temp;
				tail = temp;
				tail->next = NULL;		
			}	
}

void nextMusic(){
	if(!head){
		printf("\nPut some music into the queue first!\n");
		getchar();
	}
	else{
	printf("\nNow Playing : %s\n",musics[(head->angka)-1]);
	system("pause");
	curr = head;
	head = head->next;
	free(curr);
	}
}

void popMusicExist(){
	curr = head;
	if(head==tail){
		free(head);
		head = tail = NULL;
	}
	else{
		while(curr->next!=tail){
		curr= curr->next;
		}
		tail = curr;
		free(tail->next);
		tail->next = NULL;
	}
}

void clearQueue(){
	if(!head){
		printf("\nPut some music into the queue first!\n");
		getchar();
	}
	else{
			while(head){
			popMusicExist();
			}
			printf("\nYour music queue has been cleared!");getchar();
	}
}

void view(){
	if(!head){
		printf("Oh no.. The queue is empty..\n");
	}
	else{
		counter = 1;
		curr = head;
		while(curr){
			printf("%d) %s\n",counter++,musics[(curr->angka)-1]);
			curr = curr->next;
		}
	}
}

int main(){
	int choose;
	int angka;

	do{
		do{	system("cls");
			printf("SONG LIST\n");
			for(int i = 0 ; i < 10 ; i++ ){
				printf("%d) %s\n",i+1,musics[i]);
			}
			puts("\n");
			printf("NEXT IN QUEUE\n");
			//TODO : VIEW LINKLIST
			view();
			puts("\n");
			printf("Main Menu\n");
			printf("1. Add Music Into Queue\n");
			printf("2. Next Music\n");
			printf("3. Clear Queue\n");
			printf("4. Exit\n");
			printf("Input your choice: ");
			scanf("%d",&choose);getchar();
				switch(choose){
					case 1 :
						do{ 
							printf("What music number will be added into the queue [1..10] ?\n");
							scanf("%d",&angka);getchar();
							if(angka<1 || angka > 10){
								printf("ERROR: The music number must be between 1 and 10!\n");
							}
						}while(angka < 1 || angka > 10);
						push(angka);
						printf("The Music \"%s\" is added to queue!\n",musics[angka-1]);
						getchar();
						break;
					case 2 :
						nextMusic();
						break;
						
					case 3 :
						clearQueue();
						
						break;
						
					case 4 :
						exit(0);
						break;
				}
			
		}while(choose < 1 || choose > 4);
	}while(1);
	
	return 0;
}
