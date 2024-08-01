#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct queue
{
    int data;
    struct queue *next;
};

struct queue *rear=NULL;
struct queue *front=NULL;

void enQ(int data){
    struct queue* node=(struct queue*)malloc(sizeof(struct queue));
    node->next=NULL;
    node->data=data;
    if(front==NULL && rear==NULL){
        front=node;
        rear=node;
    }
    else{
        rear->next=node;
        rear=node;
    }
}

int deQ(){
    if(front==NULL && rear==NULL){
        return -1;
    }
    else if (rear==front)
    {
        int data=front->data;
        front=NULL;
        rear=NULL;
        return data;
    }
    else
    {
        int data=front->data;
        front=front->next;
        return data;
    }
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

void bfs(int v,int g[v][v],int visited[v]){
	int s=0;
	visited[s]=1;
	printf("\n%d",s);
	for (int i = 0; i < v; i++)
	{
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
			int data=deQ();
			printf("\t%d",data);
			i=data-1;
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
