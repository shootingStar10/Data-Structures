class Solution {
    public int numUniqueEmails(String[] emails) {
        HashSet<String> hashSet = new HashSet<> ();

        for(int i = 0; i < emails.length; i++) {
                StringBuilder str = new StringBuilder (emails[i]);
                StringBuilder tmpEmail = new StringBuilder ();
                StringBuilder domainName = new StringBuilder ();
                boolean found = false;

                for(int j = 0; j < str.length (); j++) {
                        Character c = str.charAt (j);
                        if(c.equals ('@')) {
                                found = false;
                                tmpEmail.append (str.substring (j));
                                break;
                        } else if(c.equals ('.') || found) {
                                continue;
                        } else if(c.equals ('+')) {
                                found = true;
                        } else {
                                tmpEmail.append (c);
                        }
                }

                hashSet.add (tmpEmail.toString ());
        }

        return hashSet.size ();
    }
}