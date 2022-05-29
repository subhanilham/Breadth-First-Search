#include <iostream>
#include <queue>
using namespace std;

queue<int> q, q1 , qCheck;

// q is main queue for adding and removing number
// q1 is queue for output/at last 
// qCheck is queue for checking input/number is used or not




void mainFunc(int root){
    bool a = true;
    string b;
    while(a){
        cout << "There are any connected number? Y/N: ";
        cin >> b;
        if(b == "Y"){
            cout << "Give the number: ";
            int c;
            cin >> c;
            int check = 0;
            while (!qCheck.empty())
            {
                if(qCheck.front() == c){
                    check++;
                }

                qCheck.pop();
                
            }
            if(check != 1){
                q.push(c);
                q1.push(c);
                qCheck = q1;
            }
            else{
                qCheck = q1;
            }
        }
        else{
            a = false;
        }


    }
        q.pop();
        root = q.front();
        if(!q.empty()){
            cout << "--------------------------------------------------------------------------------------------------" << endl;
            cout << "Now give the numbers connected to " << q.front() << endl;
        }
    while (!q.empty())
    {
        mainFunc(root);
    }
    

}

int main(){
    cout << "---------------------------------------------------------------------------------------------------" << endl;
    cout << "Give the root first of all: ";
    int root;
    cin >> root;
        q.push(root);
        q1.push(root);
        qCheck.push(root);
        mainFunc(root);
    cout << "-----------------------------------------------RESULT----------------------------------------------" << endl;
        while (!q1.empty())
        {
            cout << q1.front() << " ";
            q1.pop();
        }
    
    cout << "\n";
    cout << "---------------------------------------------------------------------------------------------------" << endl;
}