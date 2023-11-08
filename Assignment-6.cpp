// Author : Divya Prakash

// Page Replacement Algorithms

#include<bits/stdc++.h>

using namespace std;

#define empty 99999

int np, nf;
vector<int>pgRefSeq, currCol;
int hit = 0, pgFault = 0;

int getHitIndex(int data){
    for(int i = 0; i < nf; i++){
        if (currCol[i] == data) return i;
    }

    return -1;
}

void dispPages(){
    for(int i = 0; i < nf; i++){
        if (currCol[i] != empty) cout<<currCol[i]<<" ";
    }
    cout<<'\n';
}

void takeInput(){
    cout<<"Enter the total number of page requests : ";
    cin>>np;

    cout<<"Enter the number of frames : ";
    cin>>nf;

    pgRefSeq.resize(np);
    currCol.resize(nf, empty);

    cout<<"Enter the page reference sequence : ";
    for(int i = 0; i < np; i++) cin>>pgRefSeq[i];
}

void initialize(){
    pgFault = 0;
    hit = 0;
    currCol.clear();
    currCol.resize(nf, empty);
}

void fcfs(){
    int k = 0;

    for(int i = 0; i < np; i++){
        cout<<pgRefSeq[i]<<" ";

        if (getHitIndex(pgRefSeq[i]) == -1){
            cout<<" : Page Fault!!\n";
            pgFault++;

            currCol[k] = pgRefSeq[i];
            k = (k+1)%nf;
        }
        else{
            cout<<" : Page Hit!!\n";
            hit++;
        }

        dispPages();
        cout<<endl;
    }

    cout<<"Page Hits : "<<hit<<"\nPage Faults : "<<pgFault<<endl;
}

void optimal(){
    for(int i = 0; i < np; i++){
        cout<<pgRefSeq[i]<<" ";

        if (getHitIndex(pgRefSeq[i]) == -1){
            cout<<" : Page Fault!!\n";
            pgFault++;

            vector<int>nearFront(nf, empty);
            
            for(int k = 0; k < nf; k++){
                if (k == empty) continue;
                for(int j = i+1; j < np; j++){
                    if (pgRefSeq[j] == currCol[k]){
                        nearFront[k] = j;
                        break;
                    }
                }
            }

            int mx = -1, mxind = -1;
            for(int j = 0; j < nf; j++){
                if (nearFront[j] > mx){
                    mx = nearFront[j];
                    mxind = j;
                }
            }

            currCol[mxind] = pgRefSeq[i];
        }
        else{
            cout<<" : Page Hit!!\n";
            hit++;
        }

        dispPages();
        cout<<endl;
    }

    cout<<"Page Hits : "<<hit<<"\nPage Faults : "<<pgFault<<endl;
}

void lru(){
    for(int i = 0; i < np; i++){
        cout<<pgRefSeq[i]<<" ";

        if (getHitIndex(pgRefSeq[i]) == -1){
            cout<<" : Page Fault!!\n";
            pgFault++;

            vector<int>nearBack(nf, -1);
            
            for(int k = 0; k < nf; k++){
                if (k == empty) continue;
                for(int j = i-1; j >= 0; j--){
                    if (pgRefSeq[j] == currCol[k]){
                        nearBack[k] = j;
                        break;
                    }
                }
            }

            int mn = INT_MAX, mnind = -1;
            for(int j = 0; j < nf; j++){
                if (nearBack[j] < mn){
                    mn = nearBack[j];
                    mnind = j;
                }
            }

            currCol[mnind] = pgRefSeq[i];
        }
        else{
            cout<<" : Page Hit!!\n";
            hit++;
        }

        dispPages();
        cout<<endl;
    }

    cout<<"Page Hits : "<<hit<<"\nPage Faults : "<<pgFault<<endl;
}

int main(){
    int run = 1, choice = 0;
    
    while(run){
        cout<<"Choose the desired option : \n";
        cout<<" 1. Take Input\n 2. FCFS\n 3. Optimal\n 4. LRU\n * Press any other numeric key to exit\n";

        cin>>choice;

        switch(choice){
            case 1: 
                takeInput();
                break;
            case 2:
                initialize();
                fcfs(); 
                break;
            case 3:
                initialize();
                optimal();
                break;
            case 4:
                initialize();
                lru();
                break;
            default:
                run = 0;
        }
    }
}