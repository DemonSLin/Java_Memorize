package servlet;

import service.StudentTestService;

public class StudentTestServlet {
    private StudentTestService studentTestService;
    public void setStudentTestService
            (StudentTestService studentTestService){
        this.studentTestService=studentTestService;
    }
    public void add(){
        studentTestService.add();
    }
}
