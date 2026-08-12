class WordDictionary {

    class Node {
        Node[] child = new Node[26];
        boolean end;
    }

    Node root = new Node();

    public WordDictionary() {
    }

    public void addWord(String word) {
        Node cur = root;

        for (int i = 0; i < word.length(); i++) {
            int x = word.charAt(i) - 'a';

            if (cur.child[x] == null)
                cur.child[x] = new Node();

            cur = cur.child[x];
        }

        cur.end = true;
    }

    public boolean search(String word) {
        return find(word, 0, root);
    }

    boolean find(String word, int i, Node cur) {
        if (i == word.length())
            return cur.end;

        char c = word.charAt(i);

        if (c == '.') {
            for (int j = 0; j < 26; j++) {
                if (cur.child[j] != null && find(word, i + 1, cur.child[j]))
                    return true;
            }
            return false;
        }

        int x = c - 'a';

        if (cur.child[x] == null)
            return false;

        return find(word, i + 1, cur.child[x]);
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */