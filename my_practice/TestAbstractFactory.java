package www.lsl.com.Aug;

import java.util.Scanner;

public class TestAbstractFactory{
    public static void main(String[] args) {
        //定义客户端
        Client client=new Client();
        ComputerFactory factory=new MacProComputerFactory();
        client.buyComputer(factory.createComputer(),factory.createOperationOS());
    }
}
class Client{
    public void buyComputer(Computer computer,OperationOS os) {
        computer.printComputer();
        os.printOperationOS();
    }
}
//抽象工厂模式
interface ComputerFactory{
    //计算机
    Computer createComputer();
    //操作系统
    OperationOS createOperationOS();
}
//计算机
interface Computer{
    /*
    * 打印具体计算机信息**/
    void printComputer();
}
//操作系统
interface OperationOS{
    void printOperationOS();
}
class windows10 implements OperationOS{

    @Override
    public void printOperationOS() {
        System.out.println("windows10 操作系统，简单，好用");
    }
}
class MacOS implements OperationOS{

    @Override
    public void printOperationOS() {
        System.out.println("MacOS 操作系统，漂亮，好用");
    }
}
class MacProComputer implements Computer {
    public void printComputer() {
        System.out.println("Mac Pro 漂亮，贵，好用");
    }
}
class MacProComputerFactory implements ComputerFactory{

    @Override
    public Computer createComputer() {
        //实际开发中逻辑很复杂
        return new MacProComputer();
    }
    public  OperationOS createOperationOS(){
        return new MacOS();
    }
}
class SurfaceBookComputer implements Computer {
    public void printComputer() {
        System.out.println("Surface 屏幕可旋转，微软出品，必是精品");
    }
}
class SurfaceBookComputerFactory implements ComputerFactory{

    @Override
    public Computer createComputer() {
        return new SurfaceBookComputer();
    }
    public  OperationOS createOperationOS(){
        return new windows10();
    }
}