class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        HashSet<String> wordSet = new HashSet<> ();

                for (String str : wordList) {
                        wordSet.add (str);
                }

                if (! wordSet.contains (endWord)) {
                        return 0;
                }

                Queue<String> queue = new LinkedList<> ();
                queue.add (beginWord);
                int count = 0;

                while (! queue.isEmpty ()) {
                        count++;
                        int lsize = queue.size ();

                        while (lsize > 0) {
                                String curr = queue.poll ();

                                for (int i = 0; i < curr.length (); i++) {
                                        StringBuilder tmp = new StringBuilder (curr);

                                        for (Character character = 'a'; character <= 'z'; character++) {
                                                tmp.setCharAt (i, character);

                                                if (curr.equals (tmp.toString ())) {
                                                        continue;
                                                }

                                                if (endWord.equals (tmp.toString ())) {
                                                        return count + 1;
                                                }

                                                if (wordSet.contains (tmp.toString ())) {
                                                        queue.add (tmp.toString ());
                                                        wordSet.remove (tmp.toString ());
                                                }
                                        }
                                }

                                lsize--;
                        }
                }

                return 0;
    }
}