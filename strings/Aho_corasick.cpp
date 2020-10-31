const int SIZE_OF_ALPHABET = 26;
struct Node {
  vector<Node*> next;
  bool isEnd;
  int index;
  Node *link;
  Node() {
    this->isEnd = false;
    next.resize(SIZE_OF_ALPHABET, nullptr);
    this->link = nullptr;
  }
};
struct AhoCorasick {
  Node *root;
  AhoCorasick() {
    root = new Node();
  }
  void addWord(const string &s, int N) {
    Node *rt = root;
    for (auto &i : s) {
      if (!rt->next[i - 'a']) {
        rt->next[i - 'a'] = new Node();
      }
      rt = rt->next[i - 'a'];
    }
    rt->isEnd = true;
    rt->index = N;
  }
  void GetFailureLinks() {
    Node *rt = root;
    rt->link = nullptr;
    queue<Node*> q;
    q.push(rt);
    while (!q.empty()) {
      Node *tp = q.front();
      q.pop();
      for (int i = 0; i < SIZE_OF_ALPHABET; i++) {
        if (tp->next[i]) {
          Node *lnk = tp->link;
          while (lnk != nullptr and !lnk->next[i]) {
            lnk = lnk->link;
          }
          if (lnk != nullptr) {
            tp->next[i]->link = lnk->next[i];
          } else {
            tp->next[i]->link = root;
          }
          q.push(tp->next[i]);
        }
      }
    }
    root->link = root;
  }
  vector<int> query(const string &s) {
    vector<int> ans;
    Node *rt = root;
    for (int i = 0; i < (int)s.size();) {
      if (!rt->next[s[i] - 'a']) {
        rt = rt->link;
        if (!rt->next[s[i] - 'a']) {
          i++; continue;
        }
      } else {
        rt = rt->next[s[i] - 'a'];
        i++;
      }
      if (rt->isEnd) {
        ans.push_back(rt->index);
      }
    }
    return ans;
  }
};
