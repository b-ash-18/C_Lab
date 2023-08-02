#include<iostream>
#include<limits.h>
#include<algorithm>

using namespace std;

int minimum(int *dist, bool* sel,int size){
        int min = INT_MAX, minIndex;
        for(int v = 0; v < size; v++){
                if(sel[v] == false && dist[v] < min){
                        min = dist[v];
                        minIndex = v;
                }
        }
        return minIndex;
}

void dijkstra(){
        int v;
        cout << "Enter the number of vertices :";
        cin >> v;
        
        int *dist = new int[v];
        int weight[v][v];
        int src;
        bool selected[v];
        char c_src;


        for(int i=0; i < v-1; i++){
                dist[i] = INT_MAX;
                selected[i] = false;
                for(int j = i+1; j<v; j++){
                        cout << "Enter the weight between " << (char)(i+65) <<" and " << (char)(65+j) <<": ";
                        cin >> weight[i][j];
                        weight[j][i] = weight[i][j];
                }
        }
        cout<<"Enter the source :";
        cin >> c_src;
        src = (int)c_src - 65;
        if(src > 25){
                src -= 32;
        }

        dist[src] = 0;
        dist[v-1] = INT_MAX;
        selected[v-1] = false;
        for(int i = 0; i < v-2; i++){
                int u = minimum(dist,selected,v);
                cout<<"ustar is "<<(char)(65+u)<<endl;
                selected[u] = true;
                for(int j=0; j < v; j++){
                        if(!selected[j] && weight[u][j] != 0 && (dist[u] + weight[u][j] < dist[j])){
                                cout << "Changed distance of " << (char)(j+65) << endl;
                                dist[j] = dist[u] + weight[u][j];
                                cout << "distance btw " << (char)(65+u) << " and "<<(char)(65+j) << " is " <<dist[j] << endl;
                        }
                }
        }
        cout<<"vertex distance from source : ";
        for(int i = 0; i < v; i++){
                cout << dist[i] << " ";
        }
        cout << endl;
}

int main(){
        dijkstra();
}
