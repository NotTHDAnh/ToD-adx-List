#include <iostream>
#include <string>
#include <list>

using namespace std;

class Todoitem{
    private:
        int id;
        string description;
        bool isDone;
    public:

        Todoitem(): id(0), description(""), isDone(false) {}
        ~Todoitem() = default;
        
        bool IsCompleted(){return isDone;}
        string getDescription() {return description;}
        int getId(){return id;}

        void create(string new_description,int id){
            this->id = id;
            description = new_description;
        }

        void mark(bool done){
            this->isDone = done;
        }
};

int main(){
    string version = "v.0.0";
    list <Todoitem> TodoitemList;
    list <Todoitem>::iterator it;
    
 //    Todoitem test;
 //    test.create("This is a test",1);
 //    TodoitemList.push_back(test);
 // 
 //    Todoitem test1;
 //    test1.create("This is a test number 1",2);
 //    TodoitemList.push_back(test1);
 //
 //    Todoitem test2;
 //    test2.create("This is a test 2",3);
 //    TodoitemList.push_back(test2);

    char input_user;
    string input_add;
    int input_mark;
    int cnt = 0;

    while(1){
        system("cls");
        cout << "Welcome to To D[adx] list " << version << endl;


        for(it = TodoitemList.begin(); it != TodoitemList.end();++it){
            string status = (it->IsCompleted() ? "Done" : "Not Done");
            cout << it->getId() << " | " << it->getDescription() << " | " << status << endl;
        }
        cout << endl << endl;

        //if there is no task
        if(TodoitemList.empty()){
            cout << "Add your first to do" << endl;
        }
        cout << endl << endl;

        //menu
        cout << "[a]dd new to do" << endl;
        cout << "[m]ark the task is done"<<endl;
        cout << "[q]uit" << endl;
        
        cout << "Choose your choice: ";
        cin >> input_user;
        if(input_user == 'q'){
            break;
        }
        else if(input_user == 'a'){
            cout << "Node down your description:";
            cin.clear();
            cin.ignore();
            getline(cin,input_add);
            ++cnt; 
            Todoitem Add;
            Add.create(input_add,cnt);
            TodoitemList.push_back(Add);
        }
        else if(input_user == 'm'){
            cout << "Choose the task's ordered you want to mark:";
            cin >> input_mark;
            for(it = TodoitemList.begin(); it != TodoitemList.end();++it){
                if(input_mark == it->getId()){
                    it->mark(true);
                    break;
                }
            }
        }
        else{
            cout << "Please choose the correct letter";
        }
    }
    return 0;
}
