/*
 * @lc app=leetcode id=49 lang=java
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
    
    class Tuple {
        public int index;
        public String str;
        Tuple() {
            index = -1;
            str = null;
        }
        public String toString() {
            return index + " " + str;
        }
    }
    public List<List<String>> groupAnagrams(String[] strs) {
        List<Tuple> a = new ArrayList<>(strs.length);
        int i = 0;
        for(String str : strs) {
            Tuple t = new Tuple();
            t.index = i++;
            char[] strArr = str.toCharArray();
            Arrays.sort(strArr);
            t.str = String.valueOf(strArr);
            a.add(t);
        }
        a = a.stream() 
            .sorted(Comparator.comparing(t -> t.str))
            .collect(Collectors.toList());
        //System.out.println(a);
        
        Tuple last = null;
        Map<String, List<String>> mark = new HashMap();
        for(Tuple t : a) {
            List<String> tmp;
            if(mark.containsKey(t.str)) {
                tmp = mark.get(t.str);
            }
            else {
                tmp = new ArrayList<>();
            }
            tmp.add(strs[t.index]);
            mark.put(t.str, tmp);
        }
        List<List<String>> result = new ArrayList<>();
        
        for(List<String> tmp : mark.values()) {
            result.add(tmp);
        }
        return result;
    }
    
    /*
        public List<List<String>> groupAnagrams(String[] strs) {
        if (strs == null || strs.length == 0) return new ArrayList<>();
        Map<String, List<String>> map = new HashMap<>();
        for (String s : strs) {
            char[] ca = new char[26];
            for (char c : s.toCharArray()) ca[c - 'a']++;
            String keyStr = String.valueOf(ca);
            if (!map.containsKey(keyStr)) map.put(keyStr, new ArrayList<>());
            map.get(keyStr).add(s);
        }
        return new ArrayList<>(map.values());
    }
    */
}
// @lc code=end

