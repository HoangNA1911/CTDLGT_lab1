#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Examinee
{
string id;
	float math, literature, physic, chemistry, biology, history, geography, civic_education, natural_science, social_science, foreign_language;
};
float convertStrinToFloat(string x){
    float n;
	if (x != "")
	{
		n = stof(x);
	}
	else{
	
	    n = 0;
	}
	return n;
}
vector<Examinee> readExamineeList(string file_name){
    ifstream fin;
    fin.open(file_name,ios::in);
    vector<Examinee> result;
    string line1="";
    getline(fin,line1);
    if(!fin){
        cout<<"khong mo duoc";
    }
    else {
        while(!fin.eof()){
            string temp;
            Examinee s;
            getline(fin,temp,',');
            s.id=temp;
            getline(fin,temp,',');
            getline(fin,temp,',');
            s.math=convertStrinToFloat(temp);
            getline(fin,temp,',');
            s.literature=convertStrinToFloat(temp);
            getline(fin,temp,',');
            s.physic=convertStrinToFloat(temp);
            getline(fin,temp,',');
            s.chemistry=convertStrinToFloat(temp);
            getline(fin,temp,',');
            s.biology=convertStrinToFloat(temp);
            getline(fin,temp,',');
            s.history=convertStrinToFloat(temp);
            getline(fin,temp,',');
            s.biology=convertStrinToFloat(temp);
            getline(fin,temp,',');
            s.civic_education=convertStrinToFloat(temp);
            getline(fin,temp,',');
            s.natural_science=convertStrinToFloat(temp);
            getline(fin,temp,',');
            s.social_science=convertStrinToFloat(temp);
            getline(fin,temp,',');
            s.foreign_language=convertStrinToFloat(temp);
            getline(fin,temp);
            result.push_back(s);
        }
    }
    fin.close();
    return result;
}
void writeTotal(vector<Examinee> examinee_list, string out_file_name){
    ofstream fout;
    fout.open(out_file_name, ios::out);
    if(!fout){
        cout<<"khong mo duoc file ";
    }
    else {
        for(int i=0;i<examinee_list.size();i++){
            float total[examinee_list.size()];
            examinee_list[i].natural_science=examinee_list[i].physic
                    +examinee_list[i].chemistry+examinee_list[i].biology;
            examinee_list[i].social_science=examinee_list[i].history
                    +examinee_list[i].geography+examinee_list[i].civic_education;
            total[i]=examinee_list[i].math+examinee_list[i].literature
                    +examinee_list[i].foreign_language+examinee_list[i].natural_science+examinee_list[i].social_science;
            fout<<examinee_list[i].id<<" "<<total[i]<<endl;
        }
    }
    fout.close();
}
int main(){
    vector<Examinee> data;
    data=readExamineeList("data.txt");
    writeTotal(data,"total.txt");

    return 0;
}
