#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<string>

using namespace std;


string get_good_indexing(int no_of_spaces, string data){
    int size = data.size();
    string to_append;
    if(size > no_of_spaces){
        return data.substr(0,no_of_spaces);
    }
    else{
        for(int i=0;i<no_of_spaces-size;i++){
            data=data+" ";
        }
        return data;
    }
}

class portfolio {
    int marks_obtained;

    public:
    string course_name;
    int credit_of_course;
    int semester_of_course;

    portfolio(string course_name, int marks_obtained, int credit_of_course, int semester_of_course){
        this->course_name = course_name;
        this->marks_obtained = marks_obtained;
        this->credit_of_course = credit_of_course;
        this->semester_of_course = semester_of_course;
        //log
        cout<<"Log: Initialized Object for these details (see 4 lines below)"<<endl;
        this->print_portfolio();
        cout<<"-----------------------------------------------------------------"<<endl;
    }

    portfolio(string course_name){
        this->course_name = course_name;
        this->marks_obtained = 0;
        this->credit_of_course = 0;
        this->semester_of_course = 0;
        //log
        cout<<"Log: Initialized Object for these details (see 4 lines below)"<<endl;
        this->print_portfolio();
        cout<<"-----------------------------------------------------------------"<<endl;
    }

    void print_portfolio(){
        cout<<"Course Name: "<<this->course_name<<endl;
        cout<<"Marks Obtained: "<<this->marks_obtained<<endl;
        cout<<"Credits Obtained: "<<this->credit_of_course<<endl;
        cout<<"Semester: "<<this->semester_of_course<<endl;
    }

    void print_portfolio_list_style(){
        cout<<get_good_indexing(60,this->course_name)<< get_good_indexing(10,to_string(this->marks_obtained))<< get_good_indexing(10,to_string(this->credit_of_course))<< get_good_indexing(10,to_string(this->semester_of_course));
    }

    int get_marks_obtained(){
        //log
        cout<<"Log: Returning Marks for "<<this->course_name<<endl;
        cout<<"-----------------------------------------------------------------"<<endl;
        return marks_obtained;
    }

    int change_marks_obtained(int new_marks){
        this->marks_obtained = new_marks;
        //log
        cout<<"Log: New Marks for "<<this->course_name<<" is "<<this->marks_obtained<<endl;
        cout<<"-----------------------------------------------------------------"<<endl;
    }
};

vector<portfolio> data_loader(string filename){
    ifstream infile(filename);
    //declarations
    string deq;
    vector<portfolio> port_vector;
    port_vector.clear();
    string temp;

    while(infile>>deq){
        //cout<<deq<<endl;
        stringstream s(deq);

        //create declarations temporarily
        string sub_temp;
        int marks_temp;
        int cred_temp;
        int sem_temp;

        //assign values according to excel columns
        getline(s,temp,',');
        sub_temp = temp;
        getline(s,temp,',');
        marks_temp = stoi(temp);
        getline(s,temp,',');
        cred_temp = stoi(temp);
        getline(s,temp,',');
        sem_temp = stoi(temp);

        //create new object instance
        portfolio temp_object(sub_temp, marks_temp, cred_temp, sem_temp);
        
        port_vector.push_back(temp_object);
    }
    return port_vector;
}

void get_filename_from_user(string* filename){
    cout<<"Enter File Name if different from \"gradesheet\" else enter \"N\": ";
    cin>>*filename;
    if(*filename == "N")
    *filename = "gradesheet";
    *filename = *filename + ".csv";
}

void list_view_data(vector<portfolio> obj_vector){
    cout<<get_good_indexing(60,"Subjects")<<get_good_indexing(10,"Marks")<<get_good_indexing(10,"Credits")<< get_good_indexing(10,"Semester")<<endl;
    for (int i = 0; i < obj_vector.size(); i++){
        obj_vector[i].print_portfolio_list_style();
        cout<<endl;
    }
}

int main(){
    string filename;
    get_filename_from_user(&filename);
    vector<portfolio> obj_vector = data_loader(filename);

    list_view_data(obj_vector);

    int x;
    cout<<"\nPress any key and hit enter to end...";
    cin>>x;
    return 0;
}