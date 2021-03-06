package www.lsl.com.Aug;

import java.io.*;

public class ByteArrayInputStreamTest {
    public static void main(String[] args) throws IOException {
        String str="hello world";
        InputStream in =new ByteArrayInputStream(str.getBytes());
        OutputStream out=new ByteArrayOutputStream();
        int len=0;
        while ((len=in.read())!=-1){
            out.write(Character.toUpperCase(len));//把每个字符变大写
        }
        System.out.println(out);
        in.close();
        out.close();
    }
}
