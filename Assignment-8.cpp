// Author : Divya Prakash

// Disk Scheduling Algorithms

#include<bits/stdc++.h>

using namespace std;

int n = 0, initialHead = 0, currHead = 0, finish = 0;
vector<int>reqQueue;

void sstf(){
    int headMovement = 0;

    currHead = initialHead;
    cout<<currHead<<' ';

    vector<int>v = reqQueue;

    for(int i = 0; i < n; i++){
        int mndiff = INT_MAX, ind = -1;
        for(int j = 0; j < n; j++){
            if (v[j] == currHead) v[j] = INT_MAX;
            else if (abs(currHead - v[j]) < mndiff){
                mndiff = abs(currHead - v[j]);
                ind = j;
            }
        }

        headMovement += abs(v[ind] - currHead);
        currHead = v[ind];
        cout<<currHead<<" ";
    }

    cout<<"\nHead Movement : "<<headMovement<<endl;
}

void scan(){
    int dir = 1, headMovement = 0;
    
    cout<<"\n Enter the direction \n1. Up\n0. Down\n";
    cin>>dir;

    vector<int>v = reqQueue;
    sort(v.begin(), v.end());

    cout<<initialHead<<" ";
    currHead = initialHead;

    if (dir == 1){
        int ind = lower_bound(v.begin(), v.end(), currHead) - v.begin();
        
        for(int i = ind; i < n; i++){
            cout<<v[i]<<" ";
            headMovement += abs(currHead - v[i]);
            currHead = v[i];
        }

        cout<<finish<<" ";
        headMovement += abs(currHead - finish);
        currHead = finish;

        for(int i = ind-1; i >= 0; i--){
            cout<<v[i]<<" ";
            headMovement += abs(currHead - v[i]);
            currHead = v[i];
        }
    }
    else if (dir == 0){
        int ind = lower_bound(v.begin(), v.end(), currHead) - v.begin();

        for(int i = ind-1; i >= 0; i--){
            cout<<v[i]<<" ";
            headMovement += abs(currHead - v[i]);
            currHead = v[i];
        }

        cout<<0<<" ";
        headMovement += abs(currHead - 0);
        currHead = 0;

        for(int i = ind; i < n; i++){
            cout<<v[i]<<" ";
            headMovement += abs(currHead - v[i]);
            currHead = v[i];
        }
    }

    cout<<"\nHead Movement : "<<headMovement<<endl;
}

void clook(){
    int dir = 1, headMovement = 0;
    
    cout<<"\n Enter the direction \n1. Up\n0. Down\n";
    cin>>dir;

    vector<int>v = reqQueue;
    sort(v.begin(), v.end());

    cout<<initialHead<<" ";
    currHead = initialHead;

    if (dir == 1){
        int ind = lower_bound(v.begin(), v.end(), currHead) - v.begin();

        for(int i = ind; i < n; i++){
            cout<<v[i]<<" ";
            headMovement += abs(currHead - v[i]);
            currHead = v[i];
        }

        for(int i = 0; i < ind; i++){
            cout<<v[i]<<" ";
            headMovement += abs(currHead - v[i]);
            currHead = v[i];
        }
    }
    else if (dir == 0){
        int ind = lower_bound(v.begin(), v.end(), currHead) - v.begin();

        for(int i = ind-1; i >= 0; i--){
            cout<<v[i]<<" ";
            headMovement += abs(currHead - v[i]);
            currHead = v[i];
        }

        for(int i = n-1; i >= ind; i--){
            cout<<v[i]<<" ";
            headMovement += abs(currHead - v[i]);
            currHead = v[i];
        }
    }

    cout<<"\nHead Movement : "<<headMovement<<endl;
}

void takeInput(){
    cout<<"\nEnter the total number of cylinders : ";
    cin>>finish;
    finish--;

    cout<<"\nEnter the number of requests : ";
    cin>>n;

    reqQueue.resize(n);

    cout<<"\nEnter the request sequence : ";
    for(int i = 0; i < n; i++){
        cin>>reqQueue[i];
    }

    cout<<"\nEnter the initial head position : ";
    cin>>initialHead;
}

int main(){
    bool run = 1;
    int choice = 0;

    while(run){
        cout<<"\nChoose the desired option : \n";
        cout<<" 1. Take Input\n 2. SSTF\n 3. SCAN\n 4. C-LOOK\n *. Press any other numeric key to exit\n";
    
        cin>>choice;

        switch(choice){
            case 1:
                takeInput(); 
                break;
            case 2:
                sstf();
                break;
            case 3:
                scan();
                break;
            case 4:
                clook();
                break;
            default:
                run = 0;
        }
    }
}