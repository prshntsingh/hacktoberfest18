#include<stdio.h>
int main(){
	int n;
	printf("Enter a Number\n");
	scanf("%d",&n);
	int a[n];
	for (int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for (int i=0;i<n-1;i++){
		for (int j=0;j<n-i-1;j++){
			if(a[j+1]<a[j]){
				int t = a[j+1];
				a[j+1]= a[j];
				a[j] = t;
			}
		}
	}
	int s;
	printf("Enter a number to search");
	scanf("%d",&s);
	int r = n-1;
	int l = 0;
	int t3=1;
	while(l<=r){
		int t1  = l + (r - l) / 2;
		if(a[t1]==s){
			printf("The Number is found at %d th Location",t1+1);
			t3 =0;
			break;
		}
		if(a[t1]<s){
			l = t1+1;
		}
		else{
			r = t1-1;
		}
	}
	if(t3){
		printf("Sorry Not found");
	}
	printf("\n");
	for (int i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
}
