#include<stdio.h>
int matrix[1000][1000];
void rowSwap(int matrix[][1000],int x,int y);
void colSwap(int matrix[][1000],int x,int y);
void rowAdd(int matrix[][1000],int x,int y);
void colAdd(int matrix[][1000],int x,int y);
void operate(int matrix[][1000],int a,int x,int y);
int main()
{
	int T,n,m,q;
	scanf("%d",&T);
	while(T--){
		int i,j,a,x,y;
		scanf("%d %d %d",&n,&m,&q);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				scanf("%d",&matrix[i][j]);
		while(q--){
		    scanf("%d %d %d",&a,&x,&y);
			operate(matrix,a,x,y);
		}
		for(i=0;i<n;i++){
			for(j=0;j<m;j++)
				printf("%d ",matrix[i][j]);
			printf("\n");
		}
	}

	return 0;
}

void rowSwap(int matrix[][1000],int x,int y)
{
	if(x>1000||y>1000||x<0||y<0)
		return ;
	int temp[1000];
	for(int i=0;i<1000;i++){
		temp[i] = matrix[x-1][i];
		matrix[x-1][i] = matrix[y-1][i];
		matrix[y-1][i] = temp[i];
	}
}
void colSwap(int matrix[][1000],int x,int y)
{
	if(x>1000||y>1000||x<0||y<0)
		return ;
	int temp[1000];
	for(int i=0;i<1000;i++){
		temp[i] = matrix[i][x-1];
		matrix[i][x-1] = matrix[i][y-1];
		matrix[i][y-1] = temp[i];
	}
}
void rowAdd(int matrix[][1000],int x,int y)
{
	if(x>1000||y>1000||x<0||y<0)
		return ;
	for(int i=0;i<1000;i++){
		matrix[x-1][i] += y;
	}
}
void colAdd(int matrix[][1000],int x,int y)
{
	if(x>1000||y>1000||x<0||y<0)
		return ;
	for(int i=0;i<1000;i++){
		matrix[i][x-1] += y;
	}
}
void operate(int matrix[][1000],int a,int x,int y)
{
	if(a<1 || a> 4)return;
	switch(a){
	    case 1:rowSwap(matrix,x,y);break;
		case 2:colSwap(matrix,x,y);break;
		case 3:rowAdd(matrix,x,y);break;
		case 4:colAdd(matrix,x,y);break;
	    default:break;
	}
}
