//
// Created by Богдан Козлов on 22.12.2022.
//
#include <iostream>
#include <stdlib.h>

struct Node{
    int date;
    struct Node *next;
};

struct Steck{
    Node *head = (Node *)malloc(sizeof(Node));
    Node *tail = (Node *)malloc(sizeof(Node));
    int size;
    Steck() {
        head->next = tail;
        tail->next = NULL;
        size = 0;
    }
    void add(int dates){
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->date = dates;
        new_node->next = head->next;
        head->next = new_node;
        size++;
    }
    int udalit(){
        int date = head->next->date;
        head->next = head->next->next;
        size--;
        return date;
    }
};

int main(){
    std :: string a;
    while(std::cin >> a){
        Steck stc;
        bool n = true;
        for(int i = 0;i<a.size();i++){
            if(a[i] == '(' || a[i] == '['){
                stc.add(a[i]);
            }
            else if(a[i] == ')'){
                if(stc.size == 0){
                    n = false;
                    break;
                }
                char b = stc.udalit();
                if(b != '('){
                    n = false;
                }
            }
            else if(a[i] == ']'){
                if(stc.size == 0){
                    n = false;
                    break;
                }
                char bb = stc.udalit();
                if(bb != '['){
                    n = false;
                }
            }
        }
        if(stc.size != 0){
            n = false;
        }
        if(n){
            std::cout << "YES\n";
        }
        else{
            std::cout << "NO\n";
        }
    }
    return 0;
}