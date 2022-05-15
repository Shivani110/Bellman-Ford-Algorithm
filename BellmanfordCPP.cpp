#include<iostream>
#define max 100
using namespace std;

typedef struct EDGE
{
  int S;
  int D;
  int w;
}EDGE;

void Bellman(int nV,EDGE E[],int SGraph,int nE)
{
  int m,n,wght,x,y=0;
  int Dist[max];
  
  for(x=0;x<nV;x++)
  {
    Dist[x]=9999;
  }
    
  Dist[SGraph]=0;
  
  for(x=0;x<nV-1;x++)
  {
    for(y=0;y<nE;y++)
    {
      m=E[y].S;
      n=E[y].D;
      wght=E[y].w;
    

      if(Dist[m]!=9999 && Dist[m]+wght < Dist[n])
      {
        Dist[n]=Dist[m]+wght;
      }  
    }
    
  }
  
  for(y=0;y<nE;y++)
  {
    m=E[y].S;
    n=E[y].D;
    wght=E[y].w;
    
    if(Dist[m]+wght < Dist[n])
    {
      cout<<"\n\nNegative Cycle is present.....\n";
      return;
    }  
  }
  
  cout<<"\nVertex"<<"  Distance";
  for(m=1;m<=nV;m++)
  {
    cout<<"\n"<<m<<"\t"<<Dist[m];
  }

}


int main()
{
  int nV,nE,SGraph;
  EDGE E[max];
  
  cout<<"Enter the number of vertices: ";
  cin>>nV;  
  printf("Enter the source vertex of the graph: ");
  cin>>SGraph;  
  
  cout<<"\nEnter number of edges: ";
  cin>>nE;
  
  for(int m=0;m<nE;m++)
  {
    cout<<"\nFor "<<m+1<<"=>";
    cout<<"\nEnter source vertex :";
    cin>>E[m].S;
    cout<<"Enter destination vertex :";
    cin>>E[m].D;
    cout<<"Enter weight :";
    cin>>E[m].w;  
  }
  
  Bellman(nV,E,SGraph,nE);
  
  return 0;
}
