#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct stack{
    struct stack *next;
    int data;
};

struct stack *top=NULL;

void push(int data){
    struct stack *newNode=(struct stack*)malloc(sizeof(struct stack));
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
    if(top==NULL) return -1;
    int data=top->data;
    top=top->next;
    return data;
}

int peek(){
    return top->data;
}

bool isVisited(int k,int v,int visited[v]){
if(visited[k]==-1) return false;
return true;
}

void dfs(int v,int g[v][v],int visited[]){
    bool backTrack=false;
    bool isCycle=false;
    int starting_vertex=0;
    push(starting_vertex);
    printf("\n\t%d",starting_vertex);
    visited[starting_vertex]=0;
    while (top!=NULL)
    {
        int current_vertex=peek();
        for (int i = 0; i < v; i++)
        {
            if(g[current_vertex][i]!=0 && !isVisited(i,v,visited)){
                push(i);
                visited[i]=0;
                printf("\t%d",i);
                backTrack=false;
                i=-1;
                current_vertex=i;
            }
            else if (g[current_vertex][i]!=0 && visited[i]==0)
            {
                isCycle=true;
            }
            
            else{
                backTrack=true;
            }
        }
        while (backTrack)
        {
            int currentPopedNode=pop();
            visited[currentPopedNode]=1;
            if(top!=NULL){
                int topNode=peek();
                for (int j = 0; j <v; j++)
                    {
                    if(g[topNode][j]!=0 && !isVisited(j,v,visited)){
                    backTrack=false;
                }
                
            }
            }
            else{
                break;
            }
           
        }
        
        
    }
       if(isCycle){
        printf("\nthis graph contains cycle");
    }
    else{
    printf("\nthis graph does not contain cycle");
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
		visited[i]=-1;
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

