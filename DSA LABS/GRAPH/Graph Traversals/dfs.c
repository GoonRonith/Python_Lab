#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct stack
{
    int data;
    struct stack *next;
};

struct stack *top=NULL;

void push(int data){
     struct stack* newNode=(struct stack *)malloc(sizeof(struct stack));
     newNode->data=data;
     newNode->next=NULL;
    if(top==NULL){
        top=newNode;
        
    }
    else{
        newNode->next=top;
        top=newNode;
    }
}

int pop(){
    if(top==NULL){
        printf("stack is empty");
    }
    else{
        int data=top->data;
        top=top->next;
        return data;
    }
     return -1;
}

int peek(){
    return top->data;
}

void display(){
    struct stack *temp=top;
    while (temp!=NULL)
    {
        printf("\t%d",temp->data);
        temp=temp->next;
    }
    
}
bool isVisited(int k,int v,int visited[v]){
if(visited[k]==1) return true;
return false;
}
bool isAllVisited(int v,int visited[v]){
    for(int i=0;i<v;i++){
        if(visited[i]==0){
            return false;
        }
    }
    return true;
}
void dfs(int v,int g[v][v],int visited[v]){
    bool backStep=false;
    push(0);
    visited[0]=1;
    int starting_vertex=0;
    printf("\t%d",starting_vertex);
    for (int i = starting_vertex; i < v; i++)
    {
        if(!isAllVisited(v,visited)){
        for (int j = 0; j < v; j++)
        {
            if(g[i][j]!=0 && !isVisited(j,v,visited)){
                printf("\t%d",j);
                push(j);
                visited[j]=1;
                i=j-1;
                backStep=false;
                break;
            }
            else{
                backStep=true;
            }

        }
        if(backStep){
            bool flag=true;
            while (flag)
            {
               pop();
               int topValue=peek();
               for (int k = 0; k < v; k++)
               {
                if(g[topValue][k]!=0 && !isVisited(k,v,visited)){
                    i=topValue-1;
                    flag=false;
                    break;
                }
               }
               
            }
            
        }
        }
       

        
    }
    
}



int main(){
	int v;
	printf("\nEnter no of vertices->");
	scanf("%d",&v);
	int g[v][v];
	int visited[v];
	for (int i = 0; i <= v; i++)
	{
		visited[i]=0;
	}
	
	// set path
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
    
    printf("\n");
    printf("dfs traversal->");
    dfs(v,g,visited);
    




}