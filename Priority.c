#include<stdio.h>
int arr[100];
int prio[100];
int f=-1, r=-1;
void sort(){
	for(int i=f+1;i<=r;i++){
		for(int j=f+1;j<=i;j++){

			if(prio[j]<prio[j+1]){
				int t= prio[j];
				prio[j] = prio[j+1];
				prio[j+1] = t;
				t=arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = t; 
			}
		}
	}
}
int Dequeue(){
	if(r==f){
		printf("\n Sorry Can't Dequeue");
		return 0;
	}
	sort();
	f++;
	printf("\n The Dequeued Number is %d \n",arr[f]);
	printf("\n The Dequeued Number priority is %d \n",prio[f]);
	return 1;

}
int insert(){
	printf("\nEnter a Number");
	r++;
	scanf("%d",&arr[r]);
	printf("\nEnter Number piority in integer ");
	scanf("%d",&prio[r]);
	
	return 1;
}
int display(){
	if(r==f){
		printf("Sorry Can't Dequeue \n");
		return 0;
	}
	sort();
	printf("\nThe Display Number is %d \n",arr[f+1]);
	printf("\n The Dequeued Number priority is %d \n",prio[f+1]);
	return 1;
}
int main(){

int n=0;

while(n!=4){
	printf("Enter Your Choice  \n1->\tDequeue  \n2->\tInsert  \n3->\tDISPLAY  \n4->\tEXIT \n");
	scanf("%d",&n);
	if(n==1){
		Dequeue();
	}
	if(n==2){
		insert();
	}
	if(n==3){
		display();
	}
	if(n==4){
		return 1;
	}
}
}
