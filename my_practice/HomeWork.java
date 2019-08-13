package www.lsl.com.Aug.practice;

import java.util.Scanner;

//结算时打印购物小票
class Order{
    //折扣
    private Integer discount=10;
    //支付金额
    private Double pay;
    //商品信息
    private Goods[] goodsArray;
    public  void setDiscount(Integer discount){
        this.discount=discount;
    }
    public  void setPay(Double pay){
        this.pay=pay;
    }
    public void setGoodsArray(Goods[] goodsArray){
        this.goodsArray=goodsArray;
    }
    //打折之后的总金额
    public Double getTotalPrice(){
        Double total =0.0;
        for(int i=0;i<goodsArray.length;i++){
            total+=goodsArray[i].getTotalPrice();
        }
        return total*this.discount*0.1D;
    }
    //找钱
    public Double getGiveChange(){
        return this.pay-this.getTotalPrice();
    }
    public String toString(){
        StringBuilder sb =new StringBuilder();
        sb.append("***************消费单**************").append("\n")
                .append("名称 \t单价 \t数量 \t金额\n").append("\n");
        for(int i=0;i<this.goodsArray.length;i++){
            sb.append(this.goodsArray[i].toString());
        }
        sb.append("\n").append("-------------------------------").append("\n")
                .append("折扣：").append(this.discount)
                .append("折").append("\n").append("消费总金额：")
                .append(this.getTotalPrice()).append("\n")
                .append("实际支付金额：").append(this.getGiveChange()).append("\n")
                .append("本次消费积分").append(this.getTotalPrice().intValue());
        return sb.toString();
    }
}
class Goods{
    private String name;
    private Double price;
    private Integer number;
    public Goods(String name,Double price,Integer number){
        this.name=name;
        this.price=price;
        this.number=number;
    }
    public Double getTotalPrice(){
        return this.price*this.number;
    }
    public String toString(){
        return this.name+" \t"+"¥"
                +this.price+" \t"+this.number+" \t"+this.getTotalPrice()+"\t";
    }
}
public class HomeWork {
    public static void main(String[] args) {
        /*Goods goods=new Goods("Apple",8888.8,10);
        System.out.println(goods);*/
        //1.订单
        Order order=new Order();
        //2.商品
        Goods[] goodsArray=new Goods[3];
        order.setGoodsArray(goodsArray);
        Scanner sc=new Scanner(System.in);
        for (int i=0;i<goodsArray.length;i++){
            System.out.println("请输入商品信息格式如下：");
            System.out.println("商品名称 商品价格 商品数量");
            String line =sc.nextLine();
            String[] segments =line.split(" ");
            goodsArray[i]=new Goods(segments[0],
                    Double.parseDouble(segments[1]),
                    Integer.parseInt(segments[2]));
        }
        //3.折扣
        System.out.println("请输入折扣1-9的数字");
        String discountStr=sc.nextLine();
        order.setDiscount(Integer.parseInt(discountStr));
        Double totalPrice =order.getTotalPrice();
        System.out.println("总金额为："+totalPrice);
        System.out.println("请输入支付金额：");
        String payStr=sc.nextLine();
        order.setPay(Double.parseDouble(payStr));
        //4.打印订单
        System.out.println(order);
    }
}
