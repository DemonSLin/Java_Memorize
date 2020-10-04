package practice1.shejimoshi.singleton;

public class Singleton {
    public static void main(String[] args) {
        SingletonTest1 singletonTest1= SingletonTest1.getInstance();
        SingletonTest2 singletonTest2= SingletonTest2.getInstance();
        SingletonTest3 singletonTest3= SingletonTest3.getInstance();
        SingletonTest4 singletonTest4= SingletonTest4.getInstance();
        SingletonTest5 singletonTest5= SingletonTest5.getInstance();
        SingletonTest6 singletonTest6= SingletonTest6.getInstance();
        SingletonTest7 singletonTest7= SingletonTest7.INSTANCE7;
    }
}
    /*饿汉式（静态变量直接实例化，静态代码块处实例化）
    懒汉式（非线程安全，线程安全，双重校验DCL）
    静态内部类
    枚举
    * */
    /*饿汉式在加载时会进行实例化操作，会造成一定的内存浪费。
    不管是否使用该实例，只要类加载就会实例化
    */
    //饿汉式（静态变量，线程安全）
    class SingletonTest1{
        private final static SingletonTest1 INSTANCE = new SingletonTest1();
        private SingletonTest1(){}
        public static SingletonTest1 getInstance(){
            return INSTANCE;
        }
    }

    //饿汉式（静态代码块，线程安全）
    class SingletonTest2{
        private static SingletonTest2 INSTANCE1;
        static{
            INSTANCE1=new SingletonTest2();
        }
        private SingletonTest2(){}
        public static SingletonTest2 getInstance(){
            return INSTANCE1;
        }
    }

    /*懒汉式解决了饿汉式内存浪费的问题
    * 只有在调用getInstance的时候才会进行实例化
    * 但是需要考虑线程安全问题*/
    //懒汉式（多线程不安全）
    class SingletonTest3{
        private static SingletonTest3 INSTANCE2;
        private SingletonTest3(){}
        public static SingletonTest3 getInstance(){
            if(INSTANCE2==null){
                INSTANCE2 = new SingletonTest3();
            }
            return INSTANCE2;
        }
    }
    //懒汉式（线程安全，加锁）
    class SingletonTest4{
        private static SingletonTest4 INSTANCE4;
        private SingletonTest4(){}
        public synchronized static SingletonTest4 getInstance(){
            if(INSTANCE4==null){
                INSTANCE4=new SingletonTest4();
            }
            return INSTANCE4;
        }
    }
    /*懒汉式（DCL双重检查单例模式，线程安全，推荐）
    * DCL是一个包含特别多知识点的实现方式
    * 为什么双重校验？
    * 为什么加volatile*/
    class SingletonTest5{
        private static volatile SingletonTest5 INSTANCE5;
        private  SingletonTest5(){}
        public static SingletonTest5 getInstance(){
            if(INSTANCE5==null){
                synchronized (SingletonTest5.class){
                    if(INSTANCE5==null){
                INSTANCE5=new SingletonTest5();
                    }
                }
            }
            return INSTANCE5;
        }
    }
    /*静态内部类（线程安全，推荐）
    * 解决内存浪费问题
    * 在外部类进行类加载的时候不会对他的内部类进行加载，
    * 当调用getInstance方法时，会对静态内部类Inner进行加载，
    * 并对外部类进行实例化无需考虑线程安全问题
    * 因为JVM层面保证了内加载的安全性，所以该方式和饿汉式一样都是线程安全的*/
    class SingletonTest6{
        private SingletonTest6(){}
        private static class Inner{
            private final static SingletonTest6 INSTANCE6=new SingletonTest6();
        }
        public static SingletonTest6 getInstance(){
            return Inner.INSTANCE6;
        }
    }
    //枚举（线程安全，可以防止反序列化创建新的对象，推荐）
    enum SingletonTest7{
        INSTANCE7;
    }