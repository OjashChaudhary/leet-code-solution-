class Solution {
    class Node {
        Node[] child = new Node[26];
        String word;
    }

    Node root = new Node();

    public List<String> findWords(char[][] board, String[] words) {
        List<String> ans = new ArrayList<>();

        for (String word : words) {
            Node cur = root;
            for (char c : word.toCharArray()) {
                int i = c - 'a';
                if (cur.child[i] == null)
                    cur.child[i] = new Node();
                cur = cur.child[i];
            }
            cur.word = word;
        }

        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                dfs(board, i, j, root, ans);
            }
        }

        return ans;
    }

    void dfs(char[][] board, int r, int c, Node node, List<String> ans) {
        if (r < 0 || c < 0 || r >= board.length || c >= board[0].length)
            return;

        char ch = board[r][c];
        if (ch == '#')
            return;

        Node next = node.child[ch - 'a'];
        if (next == null)
            return;

        if (next.word != null) {
            ans.add(next.word);
            next.word = null;
        }

        board[r][c] = '#';

        dfs(board, r + 1, c, next, ans);
        dfs(board, r - 1, c, next, ans);
        dfs(board, r, c + 1, next, ans);
        dfs(board, r, c - 1, next, ans);

        board[r][c] = ch;
    }
}