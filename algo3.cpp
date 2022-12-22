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
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    Steck stc;
    int n;
    std :: cin >> n;
    for (int i = 0; i < n; i++) {
        std::string oper;
        std::cin >> oper;
        if (oper == "+") {
            int a;
            std::cin >> a;
            stc.add(a);
        }
        if (oper == "-") {
            std::cout << stc.udalit() << "\n";
        }
    }
    return 0;
}