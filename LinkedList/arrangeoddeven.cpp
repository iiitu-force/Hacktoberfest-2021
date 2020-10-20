
#include<iostream>

#define ll long long
using namespace std;

class node {
public:
    node *next;
    ll data;

    node(ll d) {
        data = d;
        next = NULL;
    }
};

node *rearrange(node *head) {
    if (head == NULL) {
        return head;
    }
    node *oh = NULL;
    node *ot = NULL;
    node *eh = NULL;
    node *et = NULL;
    node *temp = head;
    bool odd = 1;
    while (temp != NULL) {
        if (odd) {
            if (oh == NULL) {
                oh = temp;
                ot = temp;
            } else {
                ot->next = temp;
                ot = temp;
            }
            temp = temp->next;
            ot->next = NULL;
            odd = 0;
        } else {
            if (eh == NULL) {
                eh = temp;
                et = temp;
            } else {
                et->next = temp;
                et = temp;
            }
            temp = temp->next;
            et->next = NULL;
            odd = 1;
        }
    }
    ot->next = eh;
    return oh;
}

void insertion_at_tail(node *&head, int d) {
    if (head == NULL) {
        head = new node(d);
    } else {
        node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        node *temp2 = new node(d);
        temp->next = temp2;
    }
}

void print(node *head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    node *head = NULL;
    ll n;
    cin >> n;
    while (n--) {
        ll d;
        cin >> d;
        insertion_at_tail(head, d);
    }
    head = rearrange(head);
    print(head);
    return 0;
}
