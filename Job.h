#ifndef Job_h
#define Job_h 1

class Job { 

public:
    int     id;           
    CString name;         

    CTime   startTime;    
    CTime   endTime;      
    int     days;         
    int     hours;        

    Job*    nextJob;      
    Job*    previousJob;  

    int     dispFlag;     
    int     x1,y1,x2,y2;  

};

#endif
