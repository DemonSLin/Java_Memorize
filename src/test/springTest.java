import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import pojo.Student;
import servlet.StudentTestServlet;


public class springTest {
    @Test
    public void test(){
        ApplicationContext applicationContext=new
                ClassPathXmlApplicationContext("beans-config.xml");
        StudentTestServlet stu =(StudentTestServlet)applicationContext.getBean("StudentTestServlet");
        stu.add();
        Student student=(Student)applicationContext.getBean("student");
        System.out.println(student);
    }
}
