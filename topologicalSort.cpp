#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;

// using source removal technique

// int** input(){
//     int v;
//     cout << "Enter the number of vertices";
//     cin >> v;

//     int **graph = new int*[v];
//     int *count = new int[v];
//     for(int i=0; i < v; i++){
//         graph[i] = new int[v];
//     }
//     for(int i=0; i < v; i++){
//         for(int j = j+1; j < v; j++){
//             cout << "Enter the edge from " << (char)(i+65) << " to " << (char)(j+65) << " : ";
//             cin >> graph[i][j];
//             if(graph[i][j] > 0){
//                 count[j]++;
//             }
//         }
//     }
//     return graph;
// }

void topological(){
    int v;
    cout << "Enter the number of vertices : ";
    cin >> v;

    int **graph = new int*[v];
    int *count = new int[v];

    for(int i=0; i < v; i++){
        graph[i] = new int[v];
    }
    // for(int i=0; i < v; i++){
    //     for(int j = 0; j < v; j++){
    //         if(i != j){
    //             cout << "Enter the edge from " << (char)(i+65) << " to " << (char)(j+65) << " : ";
    //             cin >> graph[i][j];
    //             if(graph[i][j] > 0){
    //                 count[j]++;
    //             }
    //         }
    //     }
    // }
    cout << "Enter the adjacency matrix" << endl << "  ";
    for(int i = 0; i < v; i++){
        cout << (char)(i+65) << " ";
    }
    cout << endl;
    for(int i = 0; i < v; i++){
        cout << (char)(i+65) << " ";
        for(int j = 0; j < v; j++){
            cin >> graph[i][j];
            if(graph[i][j] > 0){
                    count[j]++;
            }
        }
    }

    for(int i=0; i<v;i++){
            cout << count[i] << " ";
    }
    cout << endl << "The traversal is : ";
    for(int i = 0; i < v; i++){
        int* select = min_element(count,count+v);
        *select = INT_MAX;
        cout << (char)(select - count + 65) << " ";
        for(int j = 0; j < v; j++){
            if(graph[select - count][j]){
                count[j]--;
            }
        }
    }
    
    

}

int main(){
    topological();
}
