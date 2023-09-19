/* Write a program to declare the array of objects and initialize and display its value*/

#include <bits/stdc++.h>
using namespace std;

class Player{
    private:
    string name;
    int age;

    public:
    void input(void);

    void display(void);

};

void Player:: input(){
    cout<<"enter the name"<<endl;
    cin>>name;
    cout<<"enter the age"<<endl;
    cin>>age;
}

void Player:: display(){
    cout<<"Name  "<<name<<endl;
    cout<<"Age  "<<age<<endl;
}

int main(){
    Player a[3];
    for(int i=0; i<3; i++){
        a[i].input();
        a[i].display();
    }
}

