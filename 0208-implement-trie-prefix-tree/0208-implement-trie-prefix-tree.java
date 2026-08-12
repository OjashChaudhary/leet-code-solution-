class Trie {

    class Node {
        Node[] child = new Node[26];
        boolean end;
    }

    Node root = new Node();

    public Trie() {
    }

    public void insert(String word) {
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
        Node cur = find(word);
        return cur != null && cur.end;
    }

    public boolean startsWith(String prefix) {
        return find(prefix) != null;
    }

    Node find(String s) {
        Node cur = root;

        for (int i = 0; i < s.length(); i++) {
            int x = s.charAt(i) - 'a';

            if (cur.child[x] == null)
                return null;

            cur = cur.child[x];
        }

        return cur;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */