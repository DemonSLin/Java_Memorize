package www.lsl.com.Aug;
//模板设计模式------泡咖啡
public class TestTemplateDesignPattern {
    public static void main(String[] args) {
       /* Coffee coffee=new Coffee();
        coffee.prepare();
        Tea tea=new Tea();
        tea.prepare();*/
        System.out.println("Drink1 制作流程");
       Drink drink1=new Coffee();
        drink1.prepare();
        System.out.println("Drink2 制作流程");
        Drink drink2 =new Tea(false);

        drink2.prepare();
        System.out.println("Drink3制作流程");
        Drink drink3=new Tea();
        drink3.prepare();
    }
}
/*模板设计模式
1.子类与父类的继承关系
2.抽象类，定义每一步执行的方法，由实现类完成方法的实现（覆写）
* **/
abstract class Drink{
    //制作饮品的步骤
    public  void prepare() {
        //1.烧水
        boilWater();
        //2.添加主料
        addMaterial();
        //3.倒入杯子
        cup();
        //4.添加辅料
        if(this.isAddMinorMaterial()){
        addMinorMaterial();
        }
    }
    public abstract void boilWater();
    public abstract void addMaterial();
    public abstract void cup();
    public abstract void addMinorMaterial();
    public boolean isAddMinorMaterial(){
        return true;
    }
}
class Coffee extends Drink {
    /*public void prepare() {
        //1.烧水
        boilWater();
        //2.添加主料
        addMaterial();
        //3.倒入杯子
        cup();
        //4.添加辅料
        addMinorMaterial();
    }*/

    public void boilWater() {
        System.out.println("1.煮咖啡烧水");
    }
    public void addMaterial() {
        System.out.println("2.往水中加咖啡");
    }
    public void cup() {
        System.out.println("3.泡好的咖啡倒入杯子");
    }
    public void addMinorMaterial() {
        System.out.println("4.泡好的咖啡中加糖");
    }
}
class Tea extends Drink {
    private boolean addMinorMaterial=true;
    public  Tea(){
    }
        /*public void prepare() {
            //1.烧水
            boilWater();
            //2.添加主料
            addMaterial();
            //3.倒入杯子
            cup();
            //4.添加辅料
            addMinorMaterial();
        }*/
public Tea(boolean addMinorMaterial){
    this.addMinorMaterial=addMinorMaterial;
}
        public void boilWater() {
            System.out.println("1.煮茶烧水");
        }
        public void addMaterial() {
            System.out.println("2.往水中加茶叶");
        }
        public void cup() {
            System.out.println("3.泡好的茶倒入杯子");
        }
        public void addMinorMaterial() {
            System.out.println("4.泡好的茶中加柠檬");
        }
        public  void setAddMinorMaterial(boolean flag){
            this.addMinorMaterial=addMinorMaterial;
        }
        public boolean isAddMinorMaterial(){
            return addMinorMaterial;
        }
    }

