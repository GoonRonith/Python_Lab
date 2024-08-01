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
if(visited[k]==-1) return false;
return true;
}


//dfs  +    cycle checking
void dfs(int v,int g[v][v],int visited[v],int starting_vertex){
    bool isCycle=false;
    push(starting_vertex);
    visited[starting_vertex]=0;
    printf("\t%d",starting_vertex);
    bool backTrack=false;
    while (top!=NULL)
    {
        int currentNode=peek();
       
      
       for (int i = 0; i < v; i++)
       {
        if(g[currentNode][i]!=0 && !isVisited(i,v,visited)){
            push(i);
            visited[i]=0;
            printf("\t%d",i);
            currentNode=i;
            i=-1;
            backTrack=false;
        }
        else if (g[currentNode][i]!=0 && visited[i]==0)
        {
           isCycle=true;
        }
        
        else{
            backTrack=true;
        }
       }
       while (backTrack)
       {
        int cur=pop();
        visited[cur]=1;
        if (top!=NULL)
        {
        int topValue=peek();
         for (int k = 0; k < v; k++)
               {
                if(g[topValue][k]!=0 && !isVisited(k,v,visited)){
                    backTrack=false;
                    break;
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
    dfs(v,g,visited,0);
    
    // int oddDegree_vertices=0;
    // int evenDegree_vertices=0;

    // for (int  i = 0; i < v; i++)
    // {
    //     int cnt=0;
    //     for (int j = 0; j < v; j++)
    //     {
    //         if(g[i][j]!=0){
    //             cnt++;
    //         }
    //     }
    // if(cnt%2==0){
    //     evenDegree_vertices++;
    // }
    // else{
    //     oddDegree_vertices++;
    // }
    // }

    // printf("\noddDegree_vertices=>%d",oddDegree_vertices);
    // printf("\nevenDegree_vertices=>%d",evenDegree_vertices);

    // // get edges
	// int edges=0;
	// 	for(int i=0;i<v;i++){
	// 	for(int j=0;j<v;j++){
	// 		if(g[i][j]!=0){
	// 			edges++;
	// 		}
	// 	}
		
	// }
	// printf("\ntotal edges->%d",edges);
	// //complete graph or not
	// if(edges==((v*(v-1))/2)){
	// 	printf("\ncomplete graph");
	// }
	// else{
	// 	printf("\nnot a complete graph");
	// }
    
}