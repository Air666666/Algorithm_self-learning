public class TranslatorRegression {
 static int x=0;
 static int take(){return x++;}
 static int pack(int a,int b){return a*10+b;}
 public static void main(String[] args){
  int a=3;int b=5;
  System.out.println((++a));
  System.out.println((b--));
  System.out.println(-(-a));
  System.out.println(~(~b));
  System.out.println(pack(take(),take()));
  System.out.println(take()-take());
  System.out.println(pack((++a),(++a)));
  System.out.println(((a++)+(a++)));
  System.out.println(Integer.MIN_VALUE / -1);
  System.out.println(Integer.MIN_VALUE % -1);
  System.out.println((1<<33));
  System.out.println((-1 >>> 1));
  String s=new String("test");String t=new String("test");
  System.out.println(s==t);System.out.println(s.equals(t));
 }
}
