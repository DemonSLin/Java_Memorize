/**
 * Created with IntelliJ IDEA.
 * Description:
 * User: GAOBO
 * Date: 2019-07-23
 * Time: 19:03
 */
public class TestDemo {
    public static void main(String[] args) {
        TestHeap testHeap = new TestHeap();
        int[] array = {1,2,3,4,5,6,7,8,9};
        testHeap.initHeap(array);
        testHeap.show();
        testHeap.pushHeap(10);
        testHeap.show();
        testHeap.popHeap();
        testHeap.show();
        testHeap.HeapSort();
        testHeap.show();
    }
}
