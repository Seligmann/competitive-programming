import java.io.*;
import java.util.*;
public class paintings {
    //recursive list
    static ArrayList<String> list;
    //map of hideous pairs
    static HashMap<String, List<String>> map;
    //best painting
    static ArrayList<String> ret;
    public static void main(String[] args) throws IOException {
        BufferedReader scan = new BufferedReader(new InputStreamReader(System.in));
        int cases = Integer.parseInt(scan.readLine());
        while (cases > 0) {
            //refresh all three global variables
            list = new ArrayList<>();
            map = new HashMap<>();
            ret = new ArrayList<>();
            
            //read in all colors, setting up ArrayLists in hideous map
            int n = Integer.parseInt(scan.readLine());
            String[] temp = scan.readLine().split(" ");
            for(String s : temp) {
                list.add(s);
                map.put(s, new ArrayList<>());
            }
            
            //set up hideous map
            n = Integer.parseInt(scan.readLine());
            while(n > 0) {
                temp = scan.readLine().split(" ");
                map.get(temp[0]).add(temp[1]);
                map.get(temp[1]).add(temp[0]);
                n--;
            }
            
            //recurse
            n = recurse(new ArrayList<String>());
            //print the total number of valid paintings
            System.out.println(n);
            //print the best painting
            for(String s : ret)
                System.out.print(s+ " ");
            System.out.println();
            cases--;
        }
    }
    private static int recurse(ArrayList<String> cur) {
        //System.out.println(cur);
        //if list is empty (so all colors have been used), a valid painting has been found. return 1 which will be added to the sum
        //if ret(the best painting list) has not had anything added yet, add to it as the best painting is found first
        if(list.size() == 0) {
            if(ret.size() == 0)
                ret.addAll(cur);
            return 1;
        }
        //add up counts of valid paintings from this step of recursion
        int ret = 0;
        //loop through all colors for this slot
        for(int i = 0; i < list.size(); i++) {
            //if cur.size is 0, any color added is fine and won't make the painting hideous
            //if cur.size > 0, recurse on any color that doesn't make the painting hideous
            if(cur.size() == 0 || !map.get(cur.get(cur.size() - 1)).contains(list.get(i))) {
                //remove the color from list and append it to cur
                cur.add(list.remove(i));
                //recurse on cur as it is with the new color
                ret += recurse(cur);
                //remove the added color and put it back on the list so both can be used for future recursive calls
                list.add(i, cur.remove(cur.size() - 1));
            }
        }
        return ret;
    }
}