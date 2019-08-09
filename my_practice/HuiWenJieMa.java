package www.lsl.com.Aug;

    import java.util.*;
    public class HuiWenJieMa{
        public static void main(String[] args) {
            Scanner scan = new Scanner(System.in);
            while (scan.hasNext()) {
                String str = scan.next();
                int n = scan.nextInt();
                System.out.println(sovle(str,n,scan));
            }
            scan.close();
        }
        public static String sovle(String str,int n,Scanner scan) {
            for (int i = 0; i < n; i++) {
                int p = scan.nextInt();
                int len = scan.nextInt();
                String first = str.substring(0,p+len);
                String mid = str.substring(p,p+len);
                String end = str.substring(p+len,str.length());
                StringBuilder res = new StringBuilder();
                res.append(first);
                StringBuilder sb = new StringBuilder(mid);
                res.append(sb.reverse());
                res.append(end);
                str = res.toString();
            }
            return str;
        }
    }


