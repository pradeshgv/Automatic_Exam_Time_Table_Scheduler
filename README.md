AIM:
To develop a automatic exam timetable scheduler usinggraphcoloring method in C++ programming language. PROBLEM STATEMENT:
PROBLEM:
 Exam time table scheduling problem Every education system faces this problem.  Due to vast number of students in offered courses.  Graph colouring approach is used to solve this problem. SOLUTION:
For solving this problem, we make vertices of total numberofsubject, and assign every vertex to one subject. Then we makeedgebetween all subject of every semester. KEY FUNCTIONS OF THE PROJECT:
displayColors()
This function is used to display all the allocated slots withtheirrespective subject names and codes. It’s return type is void. Display()
This function used to display the colors given to vertices(subjects)explicitly for better understanding. It’s return type is void. satisfyConstraints()
This function used to check whether the color is assignedandwhether it has an edge or not. It’s return type is bool.
m_Coloring_Helper()
This function is used to help the m_Coloring functionbyallocatingcolors to each vertex and check whether it is valid or not. It’sreturntype is bool. m_Coloring()
This function is used to color all the vertices(subjects). It’sreturntype is bool. displayMatrix()
This function is used to display the adjacency matrix. It’sreturntype is void. add_edge()
This function is used to add edge between vertices(subjects)bymanipulating adjacency matrix. It’s return type is void. getInpput()(Member Function of Class Subjects)
This function is used to get the all the details of a course/Subject.It’s return type is void. CLASSES USED IN THE PROJECT:
Subjects
 Data Members
 Subject_name(stores subject name)
 Subject_code(stores subject code)
 Semester(stores the semesters in which the subject appears) Member functions
 getInpput()
FUNCTIONALITY OF THE PROJECT:
Add course
This functionality of the project is used to addvarioussubjects along with their information so that the programcanschedulethe subjects with the given information. View schedule
This functionality of the project is used to viewthescheduledtime table for the given subjects with the set of informationprovided.View Course
This functionality of the project is used to viewtheset ofinformation provided so that user can verify. Exit
This functionality of the project is to exit the application.DATA STRUCTURES AND THEIR USE INTHEPROJECT: DATA STRUCTURES USED:
Graphs
 Use in the project:
 We have used undirected graph in this project, eachvertex of the graph represents each subject enteredbytheuser. Each edge of the graph between twoverticesdepictsthe fact that those two subjects cannot be slottedtogether. Adjacency matrix of the graph is createdandwiththehelp of the adjacency matrix coloring of verticesisdoneand the timetable is scheduled.
