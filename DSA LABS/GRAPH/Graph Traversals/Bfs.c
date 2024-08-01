#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct queue{
    int data;
    struct queue *next;
};

struct queue *rear=NULL;
struct queue *front=NULL;

void enQ(int item){
    struct queue* newNode=(struct queue *)malloc(sizeof(struct queue));
	newNode->data=item;
    if(rear==NULL && front==NULL){
    front=newNode;
    rear=newNode;
    }
    else{
        rear->next=newNode;
        rear=newNode;
    }
}



int deQ(){
    if(rear==NULL && front==NULL){
        printf("queue is empty..");
    }
	else if (rear==front)
	{
		 int item=front->data;
		// printf("\n%d=",item);
		rear=front=NULL;
        return item;
	}
	
    else{
        int item=front->data;
        front=front->next;
		// printf("\n%d=",item);
        return item;
    }
    return -1;
}

void displayQ(){
	struct queue* temp=front;
	printf("\nQueue::");
	while(temp!=rear)
	{
		printf("\t%d",temp->data);
		temp=temp->next;
	}
	printf("\t%d",temp->data);
}

bool isPresent(int k,int v,int visited[v]){
if(visited[k]==1) return true;
return false;
}

//  void bfs(int v,int g[v][v],int visited[v]){
// 	printf("\n");
	
// 	for (int i = 1; i <= v+1; i++)
// 	{	
		
// 		if(rear==NULL && front==NULL){
// 				enQ(i);
// 				visited[i]=1;
// 			}
// 			else{
// 				int deleItem=deQ();
// 				printf("\t%d",deleItem);

// 					for (int k = 1; k <= v; k++){
// 						if(g[deleItem][k]!=0){
// 							// printf("\n%d push hba",k);
// 							if(!isPresent(k,v,visited)){
// 							enQ(k);
// 							visited[k]=1;
// 							}
							
							
// 						}
// 					}
				 
// 			}
	
			
// 	}

// }

void bfs(int v,int g[v][v],int visited[v]){
	int s=0;
	visited[s]=1;
	printf("\t%d",s);
	for(int i=0;i<v;i++){
		for (int j = 0; j < v; j++)
		{
			if(g[i][j]!=0){
				if(!isPresent(j,v,visited)){
					enQ(j);
					visited[j]=1;
				}
			}
		}
		if(rear!=NULL && front!=NULL){
			int item=deQ();
			printf("\t%d",item);
			i=item-1;
		}
	}
}

int main(){
	int v;
	printf("\nEnter no of vertices->");
	scanf("%d",&v);
	int g[v][v];
	int visited[v+1];
	for (int i = 0; i < v; i++)
	{
		visited[i]=0;
	}
	
	//set path
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			printf("enter the distance between %d -> %d =>",i,j);
			scanf("%d",&g[i][j]);
		}
	}
	// display AdjacencyList
		for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			printf("\t%d",g[i][j]);
		}
		printf("\n");
	}
    bfs(v,g,visited);
	// displayQ();
     
	
}