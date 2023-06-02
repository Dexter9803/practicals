/*
You have a business with several offices;
you want to lease phone lines to connect them up with each other;
and the phone company charges different amounts of money to connect different pairs of cities.
You want a set of lines that connects all your offices with a minimum total cost.
Solve the problem by suggesting appropriate data structures
*/
#include<iostream>
using namespace std;
#define ROW 10
#define COL 10
#define infi 9999
class prims
{
    int graph[ROW][COL], nodes;

    public:
    void createGraph();
    void primsAlgo();

};

void prims::createGraph()
{
    cout<<"Enter total no, of Offices: ";
    cin>>nodes;

    cout<<"-----Enter Adjancecy Matrix------";

    //make array infinity all
    for (int i = 0; i < nodes; i++)
    {
        for(int j=0; j<nodes; j++)
        {
            graph[i][j] = infi;
        }
    }

    //entering values to array
    for (int i = 0; i <  nodes; i++)
    {
        for(int j = i; j < nodes; j++)
        {
            cout<<"Enter distance between "<<i<<" & "<<j<<": ";
            cin>>graph[i][j];
            graph[j][i] = graph[i][j];
        }
        cout<<endl;
    }
}

void prims::primsAlgo()
{
    int visited[ROW];
    int end=0;
    int x,y,i,j;
    int min = 0;
    int cost = 0;

    //making visited 0
    for (int i = 0; i < nodes; i++)
    {
        visited[i] = 0;
    }

    visited[0] = 1;

    //traversing 
    while(end < nodes-1)
    {
        min = infi;
        for (i = 0; i < nodes; i++)
        {
            if(visited[i] == 1)             //visited
            {
                for(j = 0; j < nodes; j++)
                {
                    if(visited[j] == 0)     //not visited
                    {
                        if(min > graph[i][j])
                        {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        visited[y] = 1;
        cout<<"\n";
        cout<<x<<"->"<<y;
        cost += graph[x][y];
        end++; 
    }

    cout<<"\nTotal Cost: "<<cost<<endl;

}


int main()
{
    prims MST;
    cout << "\n-----Prims Algorithm to connect several offices-----\n";
    MST.createGraph();
    MST.primsAlgo();

    
    return 0;  
    
}