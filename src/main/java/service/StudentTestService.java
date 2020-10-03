package service;

import dao.StudentTest;

public class StudentTestService {
    private StudentTest stuDao;
    public void setStuDao(StudentTest stuDao){
        this.stuDao = stuDao;
    }
    public void add(){
        stuDao.add();
    }
}
