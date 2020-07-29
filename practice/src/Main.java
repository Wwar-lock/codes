import sample.*;
public class Main implements showFullName{
    @Override
    public void nameDisplay(String s1,String s2) {
        System.out.println(s2);
        System.out.println(s1);
    }

    public static void main(String[] args) {
        Main obj = new Main();
        obj.nameDisplay("Aditya","Sharma");
    }
}
