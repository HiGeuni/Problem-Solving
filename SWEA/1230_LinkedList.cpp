#include<iostream>
using namespace std;
//Single Linked List
#define MAX_NODE 10000

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node node[10000];
int nodeCnt;
Node* head;

Node* getNode(int data) {
    node[nodeCnt].data = data;
    node[nodeCnt].prev = nullptr;
    node[nodeCnt].next = nullptr;
    return &node[nodeCnt++];
}

void init()
{
    nodeCnt = 0;
    head = getNode(-1);
}

void addNode2Tail(int data)
{
    Node * ptr = head;
    Node * tmp = getNode(data);
    while(ptr->next){
        ptr = ptr->next;
    }
    ptr->next = tmp;
    tmp->prev = ptr;
}

void addNode2Num(int data, int num)
{
    Node * tmp = getNode(data);
    Node * ptr = head;
    int cnt = 1;
    while(ptr){
        if(cnt==num){
            tmp->next = ptr->next;
            tmp->prev = ptr;
            if(ptr->next)
                ptr->next->prev = tmp;
            ptr->next = tmp;
            break;
        }
        ptr = ptr->next;
        cnt += 1;
    }
}


void removeNode(int idx)
{
    Node * ptr = head;
    int cnt = 0;
    while(ptr){
        if(cnt == idx){
            ptr->prev->next = ptr->next;
            if(ptr->next)
                ptr->next->prev = ptr->prev;
            ptr->prev = nullptr;
            ptr->next = nullptr;
            break;
        }
        ptr = ptr->next;
        cnt += 1;
    }
}

void getList()
{
    Node * ptr = head->next;
    for(int i=0;ptr!= nullptr; ++i) {
        cout << ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}

int main(){
    for(int testCase = 1; testCase<=10; ++testCase){
        init();
        int N, tmp, cmd;
        cin>>N;
        for(int i=0;i<N; ++i){
            cin>>tmp;
            addNode2Tail(tmp);
        }
        cin>>cmd;
        char command;
        int x, y, s;
        for(int i=0;i<cmd; ++i){
            cin>>command;
            if(command == 'I'){
                cin>>x>>y;
                for(int j=0; j<y; ++j){
                    cin>>tmp;
                    addNode2Num(tmp, x+j+1);
                }
            }else if (command == 'D'){
                cin>>x>>y;
                for(int j=0;j<y; ++j){
                    removeNode(x+1);
                }

            }else if(command == 'A'){
                cin>>x;
                for(int j=0; j<x; ++j){
                    cin>>tmp;
                    addNode2Tail(tmp);
                }
            }
            getList();
        }
        cout<<"#"<<testCase<<" ";

    }
    return 0;
}