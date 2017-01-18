#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <algorithm> //sort
using namespace std;
int sze=0;
bool keep=false;
struct student{
    int id;
    string name;
    float score;
    string phone;
    int age;
    string city;
    string email;
};
struct student arr_of_students[1000];
void menu();
vector<string>  parse(string x){

    vector<string> v;
    int start=0;

    for(int i=0;i<x.size();i++){
        if(x[i]==','){
            string k="";
            for(int j=start;j<i;j++){
                k+=x[j];
            }
            start=i+1;
            v.push_back(k);
        }

    }
    string k="";
    for(int i=start;i<x.size();i++){
        k+=x[i];
    }
    v.push_back(k);
    return v;
}
void load_all(){

    string line;
  ifstream myfile("students.txt");
  if(sze==0){
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
        vector<string> v;
        v=parse(line);
       stringstream ss1( v[1] );
       int id;
       ss1 >> id;
       stringstream ss2( v[5] );
       int age;
       ss2 >> age;
       stringstream ss3( v[6] );
       float score;
       ss3 >> score;
       arr_of_students[sze].name=v[0];
       arr_of_students[sze].id=id;
       arr_of_students[sze].city=v[2];
       arr_of_students[sze].phone=v[3];
       arr_of_students[sze].email=v[4];
       arr_of_students[sze].age=age;
       arr_of_students[sze].score=score;
       sze++;

    }

    myfile.close();
  }else{
      return;
  }
  }
  return ;

}
bool  get_student(int id){
    load_all();
    bool found=false;
    for(int i=0;i<sze;i++){
        if(arr_of_students[i].id==id){
                found=true;
            cout<<"STUDENT FOUND"<<endl<<endl;

            cout<<"STUDENT'S ID : "<<arr_of_students[i].id<<endl<<endl;
            cout<<"STUDENT'S NAME : "<<arr_of_students[i].name<<endl<<endl;
            cout<<"STUDENT'S SCORE : "<<arr_of_students[i].score<<endl<<endl;
            cout<<"STUDENT'S AGE : "<<arr_of_students[i].age<<endl<<endl;
            cout<<"STUDENT'S EMAIL : "<<arr_of_students[i].email<<endl<<endl;
            cout<<"STUDENT'S PHONE : "<<arr_of_students[i].phone<<endl<<endl;
            cout<<"STUDENT'S CITY : "<<arr_of_students[i].city<<endl;
        return found;
        }

    }
    cout<<"NOT FOUND!! "<<endl;
    return false;
}
bool add_student(int id,string name,string phone,string city,string email,int age,float score){
load_all();
vector<student> v_s;
for(int i=0;i<sze;i++){
    if(arr_of_students[i].id==id){
    return false;
    }
    v_s.push_back(arr_of_students[i]);
}
student s;
s.id=id;
s.name=name;
s.phone=phone;
s.city=city;
s.email=email;
s.age=age;
s.score=score;
v_s.push_back(s);
sze++;
    int x=0;
    for(int i=0;i<sze;i++){
        arr_of_students[i].id=v_s[i].id;
        arr_of_students[i].name=v_s[i].name;
        arr_of_students[i].phone=v_s[i].phone;
        arr_of_students[i].city=v_s[i].city;
        arr_of_students[i].email=v_s[i].email;
        arr_of_students[i].age=v_s[i].age;
        arr_of_students[i].score=v_s[i].score;
    }
    return true;
}
void print(){
    load_all();
    int ids[sze];
    if(!sze){
        cout<<"NO STUDENTS FOUND !! "<<endl;
    }
    student students[sze];
    for(int i=0;i<sze;i++){
        ids[i]=arr_of_students[i].id;
    }
    sort(ids,ids+sze);
    for(int i=0;i<sze;i++){
        for(int j=0;j<sze;j++){
            if(ids[i]==arr_of_students[j].id){
                cout<<endl<<"======================"<<endl;
                cout<<"== STUDENT NUMBER "<< i+1<<" =="<<endl;
                cout<<"======================"<<endl<<endl;
                cout<<"STUDENT'S NAME : "<<arr_of_students[j].name<<" "<<endl<<endl;
                cout<<"STUDENT'S ID : "<<arr_of_students[j].id<<" "<<endl<<endl;
                cout<<"STUDENT'S AGE : "<<arr_of_students[j].age<<" "<<endl<<endl;
               cout<<"STUDENT'S EMAIL : "<<arr_of_students[j].email<<" "<<endl<<endl;
               cout<<"STUDENT'S PHONE : "<<arr_of_students[j].phone<<" "<<endl<<endl;
                cout<<"STUDENT'S CITY : "<<arr_of_students[j].city<<" "<<endl<<endl;
                cout<<"STUDENT'S SCORE : "<<arr_of_students[j].score<<" "<<endl<<endl;

            }
        }
    }
}
void statistics(){
    bool counted=false;
    load_all();
    float scores[sze];
    student top_students[sze];
    float av=0;
    int counter=0;
    for(int i=0;i<sze;i++){
        scores[i]=arr_of_students[i].score;
        av+=scores[i];
        counted=true;
        counter++;
    }
    if(counted && counter>=4){
    sort(scores,scores+sze);
    for(int i=0;i<sze;i++){
        for(int j=0;j<sze;j++){
                if(scores[i]==arr_of_students[j].score){
                top_students[i].name=arr_of_students[i].name;
                top_students[i].id=arr_of_students[i].id;
                top_students[i].score=arr_of_students[i].score;

        }
    }
    }
    cout<<endl<<"TOP 5 STUDENTS : " <<endl<<endl;
    for(int i=sze-1;i>sze-6;i--){

        cout<<"STUDENT'S ID : "<<top_students[i].id <<endl<<"STUDENT'S NAME : "<<top_students[i].name<<endl<<"STUDENT'S SCORE : "<<top_students[i].score<<endl<<endl<<endl;


    }
    av=av/(float)sze;
    float MIN,MAX;
    MIN=scores[0];
    MAX=scores[sze-1];
    cout<<"AVERAGE SCORE OF ALL STUDENTS : "<<av <<endl;
    cout<<"MINIMUM SCORE OF ALL STUDENTS : "<<MIN<<endl;
    cout<<"MAXIMUM SCORE OF ALL STUDENTS : "<<MAX<<endl;
    }else{
        cout<<"NO STUDENTS FOUNDED !!"<<endl;
    }
}
bool update_score(int id,float score){
    load_all();
    for(int i=0;i<sze;i++){
        if(arr_of_students[i].id==id){
            arr_of_students[i].score=score;
            return true;
        }
    }
    return false;
}
bool delete_student(int id){
    load_all();
vector<student> v_s;
bool founded=false;
for(int i=0;i<sze;i++){
    if(arr_of_students[i].id!=id){
    v_s.push_back(arr_of_students[i]);
    }else{
        founded=true;
    }
}
//cout<<v_s.size()<<" "<<sze;
if(founded){
cout<<endl<<"STUDENT OF ID "<< id <<" DELETED "<<endl;
}else{
    cout<<"NO STUDENT FOUND IN DATABASE" <<endl;
    return false;
}
for(int i=0;i<sze-1;i++){
    arr_of_students[i].id=v_s[i].id;
    //cout<<arr_of_students[i].id<<" ";
    arr_of_students[i].name=v_s[i].name;
    //cout<<arr_of_students[i].name<<" ";
    arr_of_students[i].city=v_s[i].city;
    //cout<<arr_of_students[i].city<<" ";
    arr_of_students[i].email=v_s[i].email;
    //cout<<arr_of_students[i].email<<" ";
    arr_of_students[i].phone=v_s[i].phone;
    //cout<<arr_of_students[i].phone<<" ";
    arr_of_students[i].age=v_s[i].age;
    //cout<<arr_of_students[i].age<<" ";
    arr_of_students[i].score=v_s[i].score;
    //cout<<arr_of_students[i].score<<" ";
    //cout<<endl;
}
arr_of_students[sze-1].id=0;
arr_of_students[sze-1].name="";
arr_of_students[sze-1].city="";
arr_of_students[sze-1].email="";
arr_of_students[sze-1].phone="";
arr_of_students[sze-1].age=0;
arr_of_students[sze-1].score=0;
if(founded){
return true;
}
else{
    return false;
}
}
bool save(){
    //load_all();
    keep=false;
    remove("students.txt");
    ofstream newFile("students.txt", std::ios_base::app);
    string a[sze];
    if(newFile.is_open()){
    for(int i=0;i<sze;i++){
    if(arr_of_students[i].id>0){
     newFile<<arr_of_students[i].name<<","<<arr_of_students[i].id<<","<<arr_of_students[i].city<<","<<arr_of_students[i].phone<<","<<arr_of_students[i].email<<","<<arr_of_students[i].age<<","<<arr_of_students[i].score<<endl;
    }
    }
    newFile.close();
    keep=true;
    return true;
    }
    return false;

}
void exit(){
    if(keep==true){
    exit(0);
    }else{
        cout<<"PRESS ANY KEY TO SAVE AND EXIT OR PRESS 0 TO BACK TO MAIN MENU WITHOUT SAVING : ";
        string x;cin>>x;
        if(x.size()>0 && x!="0"){
            save();
        }
        else{
       menu();
        }
    }
}
void menu(){
    system("CLS");
    int x ;
    cout<<"                                     "<<endl;
    cout<<"                                   =============================================="<<endl;
    cout<<"                                   == WELCOME TO STUDENT MANAGMENT APPLICATION =="<<endl;
    cout<<"                                   =============================================="<<endl<<endl;
    cout<<endl;
    cout<<"                                   PRESS 1 TO ADD NEW STUDENT "<<endl;
    cout<<endl;
    cout<<"                                   PRESS 2 TO SEARCH FOR STUDENT BY ID "<<endl;
    cout<<endl;
    cout<<"                                   PRESS 3 TO PRINT ALL STUDENTS INFORMATION "<<endl;
    cout<<endl;
    cout<<"                                   PRESS 4 TO SHOW STUDENT'S STATISTICS"<<endl;
    cout<<endl;
    cout<<"                                   PRESS 5 TO DELETE STUDENT'S INFORMATION  "<<endl;
    cout<<endl;
    cout<<"                                   PRESS 6 TO UPDATE STUDENT'S SCORE "<<endl;
    cout<<endl;
    cout<<"                                   PRESS 7 TO EXIT THE APPLICATION "<<endl;
    cout<<endl;
    cout<<"                                   ENTER YOUR CHOICE :  ";cin>>x;
    cout<<endl<<"================================================================================"<<endl<<endl;
    system("CLS");
    if (x==1){
        cout<<"ADD NEW STUDENT : "<<endl<<endl;
        int id;string name;string phone;string city;string email;int age;float score;
        cout<<"ENTER STUDENT'S ID : ";
        cin>>id;
        cout<<endl<<"ENTER STUDENT'S NAME : ";
        cin>>name;
        cout<<endl<<"ENTER STUDENT'S PHONE : ";
        cin>>phone;
        cout<<endl<<"ENTER STUDENT'S CITY : ";
        cin>>city;
        cout<<endl<<"ENTER STUDENT'S EMAIL : ";
        cin>>email;
        cout<<endl<<"ENTER STUDENT'S AGE : ";
        cin>>age;
        cout<<endl<<"ENTER STUDENT'S SCORE : ";
        cin>>score;
        if(add_student(id,name,phone,city,email,age,score)){
        save();
        cout<<endl<<"STUDENT DATA SAVED ! \nPRESS ENTER TO BACK TO MAIN MENU";
        }else{
            cout<<endl<<"STUDENT DATA SAVED ! \nSTUDENT MAY BE EXIST OR DATA IS NOT RIGTH \nPRESS ENTER TO BACK TO MAIN MENU";
        }

        cin.ignore();
		cin.get();
		menu();
    }
    else if (x==2){
            cout<<"SEARCH FOR STUDENT BY ID : "<<endl<<endl;
            cout<<"ENTER STUDENT'S ID : ";
        int x;
        cin>>x;
        cout<<endl;
        get_student(x);
        cout<<endl<<"PRESS ENTER TO BACK TO MAIN MENU";
        cin.ignore();
		cin.get();
		menu();
        // not found user
    }
    else if (x==3){
        cout<<"PRINT ALL STUDENT DATA : "<<endl<<endl;
        print();
        cout<<endl<<"PRESS ENTER TO BACK TO MAIN MENU";
        cin.ignore();
		cin.get();
		menu();

    }
    else if (x==4){
        cout<<"SHOW STATISTICS : "<<endl;
        statistics();
        cout<<endl<<"PRESS ENTER TO BACK TO MAIN MENU";
        cin.ignore();
		cin.get();
		menu();
    }
    else if(x==5){
        int x;
        cout<<"DELETE STUDENT DATA :"<<endl<<endl;
        cout<<"ENTER STUDENT ID: ";
        cin>>x;
        if(!delete_student(x)){
        save();
        }
        cout<<endl<<"PRESS ENTER TO BACK TO MAIN MENU";
        cin.ignore();
		cin.get();
		menu();

    }
    else if (x==6){
    int x;
    float y;
    cout<<"UPDATE STUDENT'S DATA : "<<endl<<endl;
    cout<<"ENTER STUDENT ID : ";
    cin>>x;
    cout<<endl<<"ENTER NEW STUDENT SCORE : ";
    cin>>y;
        if(update_score(x , y)){
        save();
         cout<<endl<<"STUDENT OF ID "<<x <<" SCORE EQUAL  "<<y<<endl;
        }else{
            cout<<"STUDENT OF ID "<<x<<" is not exist"<<endl;
        }
        cout<<endl<<"PRESS ENTER TO BACK TO MAIN MENU";
        cin.ignore();
		cin.get();
		menu();

    }
    else if (x==7){
        cout<<"EXITING PROGRAM \n"<<endl;
        exit();
    }
    else {
        cout<<"WRONG CHOICE ... TRY AGAIN"<<endl;
        cout<<endl<<"PRESS ENTER TO BACK TO MAIN MENU";
        cin.ignore();
		cin.get();
		menu();
    }
}


int main()
{
   menu();
}
