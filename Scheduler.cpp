#include <bits/stdc++.h>
#include<vector>
#include<conio.h>
using namespace std;

vector<vector<bool> > Adj_matrix;

class Subjects{
    public:
    string subject_name,subject_code;
    vector<int> semester;
    void getInpput()
    {
        int sem,semesterCount;
        cout<<"\n\n\t\t\t\t\t\t\t\tEnter number of semesters this course appears:";
        cin>>semesterCount;
        cout<<"\n";
        for(int i=0;i<semesterCount;i++){
            cout<<"\t\t\t\t\t\t\t\tSemester Appearance "<<i+1<<":";
            cin>>sem;
            semester.push_back(sem);
        }
        
		cout<<"\n\t\t\t\t\t\t\t\tSubject name:";
        cin.ignore();
        getline(cin,subject_name);
        
		cout<<"\n\t\t\t\t\t\t\t\tSubject code:";
        cin>>subject_code;
    }
};

vector<Subjects> allSubject;

void displayColors(int color[])
{
  vector<vector<int> > cls;
  for(int i=0;i<Adj_matrix.size();i++)
  {
    vector<int> temp;
    for(int j=0;j<Adj_matrix.size();j++)
    {
      if(color[j]==(i+1))
      {
        temp.push_back(j);
      }
    }
    cls.push_back(temp);
  }
  cout<<endl;
  for(int i=0;i<Adj_matrix.size();i++)
  {
    if(!cls[i].empty())
    {
      cout<<"\t\t\t\t\t\t\t\t=================";
      cout<<"\n\t\t\t\t\t\t\t\tSlot-->"<<i+1<<endl;
      cout<<"\t\t\t\t\t\t\t\t=================\n";
      cout<<"\n\t\t\t\t\t\t\t";
      cout<<setw(35);
      cout<<"Subject Name:";
      cout<<setw(35);
      cout<<"\tSubject Code:\n ";
      for(int j=0;j<cls[i].size();j++)
      {
        cout<<"\t\t\t\t\t\t\t\t";
      cout<<setw(30);
        cout<<allSubject[cls[i][j]].subject_name;
      cout<<setw(30);
        cout<<allSubject[cls[i][j]].subject_code<<"\n";
      }
    }
  }
}

void Display(int color[]) {
  cout << "\n\n\t\t\t\t\t\t\t\tThe colors given to vertices are:\n" << endl;
  for (int i = 0; i < Adj_matrix.size(); i++)
    cout << "\t\t\t\t\t\t\t\tVertex " << i + 1 << " is given color:" << color[i] << endl;
  cout << endl;
}

bool satisfyConstraints(int v, vector<vector<bool> > Adj_matrix, int color[], int c)
{
  for (int i = 0; i < Adj_matrix.size(); i++) {
    if (Adj_matrix[v][i] && c == color[i])
      return false;
  }
  return true;
}

bool m_Coloring_Helper(vector<vector<bool> > Adj_matrix, int m, int color[], int v) {

  if (v == Adj_matrix.size())
    return true;

  for (int c = 1; c <= m; c++) {

    if (satisfyConstraints(v, Adj_matrix, color, c)) {
      color[v] = c;

      if (m_Coloring_Helper(Adj_matrix, m, color, v + 1) == true)
        return true;

      color[v] = 0;
    }
  }

  return false;
}

bool m_Coloring(vector<vector<bool> > Adj_matrix, int m) {

  int color[Adj_matrix.size()];
  for (int i = 0; i < Adj_matrix.size(); i++) {
    color[i] = 0;
  }
  if (m_Coloring_Helper(Adj_matrix, m, color, 0) == false) {
    cout << "\t\t\t\t\t\t\t\tNo such arrangement exists!!";
    return false;
  }

  Display(color);
  displayColors(color);
  return true;
}

void displayMatrix() {
   int i, j;
   cout<<"\n\n";
   for(i = 0; i < Adj_matrix.size(); i++) {
      cout<<"\t\t\t\t\t\t\t\t\t";
	  for(j = 0; j < Adj_matrix.size(); j++) {
         cout<< Adj_matrix[i][j] << " ";
      }
      cout << endl;
   }
}
void add_edge(int u, int v) {
   Adj_matrix[u][v] = 1;
   Adj_matrix[v][u] = 1;
}

int main() {
	system("cls");
	cout<<"\n\n\n\n\n\t\t\t\t\t\t**********************************************************************************\n\n";
	cout<<"\n\t\t\t\t\t\t\t\t*****COURSE SCHEDULER FOR UNIVERSITY STUEDNTS*****\n\n\n\t\t\t\t\t\t**********************************************************************************\n\n\n\t\t\t\t\t\t\t\t\t(IMPLEMENTED USING GRAPH COLORING)\n\n\t\t\t\t\t\t\t\tCREDITS:\n\n\t\t\t\t\t\t\t\tPresented to you by:\n\n\t\t\t\t\t\t\t\t\tPrasath K\n\n\t\t\t\t\t\t\t\t\tSanjay T\n\n\t\t\t\t\t\t\t\t\tSamuel Tennyson T\n\n\t\t\t\t\t\t\t\t\tPradesh G V\n\n";
    int choice;
    cout<<"\t\t\t\t\t\tEnter any key to continue...";
    getch();
    do{
        system("cls");
        Subjects S;
        cout<<"\n\n\t\t\t\t\t\t**********************************************************************************\n\n";
		cout<<"\n\n\t\t\t\t\t\t\t\tYOUR CHOICES ARE:\n\n";
        cout<<"\n\t\t\t\t\t\t\t\t\t1.Add course\n\n\t\t\t\t\t\t\t\t\t2.View Schedule\n\n\t\t\t\t\t\t\t\t\t3.View Courses\n\n\t\t\t\t\t\t\t\t\t4.Exit\n";
        cout<<"\n\n\n\n\t\t\t\t\t\t\t\tEnter your preferred choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:
                S.getInpput();
                allSubject.push_back(S);
                cout<<"\t\t\t\t\t\tEnter any key to continue...";
                getch();
                system("cls");
                break;
            case 2:
                Adj_matrix.clear();
                for(int i=0;i<allSubject.size();i++)
                {
                  vector<bool> temp;
                  for(int j=0;j<allSubject.size();j++)
                  {
                    temp.push_back(0);
                  }
                  Adj_matrix.push_back(temp);
                }

                for(int i=0;i<allSubject.size();i++)
                {
                    for(int j=0;j<allSubject.size();j++)
                    {
                        if(i!=j)
                        {
                            for(int k=0;k<allSubject[i].semester.size();k++)
                            {
                                for(int l=0;l<allSubject[j].semester.size();l++)
                                {
                                    if(allSubject[i].semester[k]==allSubject[j].semester[l])
                                    {
                                        add_edge(i,j);
                                    }
                                }
                            }
                        }
                    }
                }
                displayMatrix();
                m_Coloring(Adj_matrix,allSubject.size());
                cout<<"\n\t\t\t\t\t\tEnter any key to continue...";
                getch();
                system("cls");
                break;
            case 3:
              cout<<setw(35);
              cout<<"\n\t\t\t\t\t\t\t\tSubject Name";
              cout<<setw(35);
              cout<<"\tSubject Code\n";
              for(int i=0;i<allSubject.size();i++)
              {
                  cout<<"\n\t\t\t\t\t\t\t\t";
                  cout<<setw(30);
                  cout<<allSubject[i].subject_name;
                  cout<<setw(30);
                  cout<<allSubject[i].subject_code;
              }
                cout<<"\n\t\t\t\t\t\tEnter any key to continue...";
                getch();
                system("cls");
              break;
            case 4:
                system("cls");
                cout<<"\n--Thank you--\n";
                exit(0);
        }
    }while(1);
  return 0;
}
