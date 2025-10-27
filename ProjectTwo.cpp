// ProjectTwo.cpp — ABCU Advising Assistance (BST), Sample-Output aligned
// Build: g++ -std=c++17 -O2 ProjectTwo.cpp -o ProjectTwo

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

// ------------ Data model ------------
struct Course {
    string number;
    string title;
    vector<string> prereqs;
};

// ------------ BST ------------
struct Node {
    string key; // UPPERCASE(course.number)
    Course value;
    Node* left;
    Node* right;
    Node(const string& k, const Course& v) : key(k), value(v), left(nullptr), right(nullptr) {}
};

static Node* bstInsert(Node* t, const string& key, const Course& v) {
    if (!t) return new Node(key, v);
    if (key < t->key)  t->left  = bstInsert(t->left, key, v);
    else if (key > t->key) t->right = bstInsert(t->right, key, v);
    else t->value = v; // overwrite if duplicate (shouldn't happen; we check before insert)
    return t;
}
static Node* bstFind(Node* t, const string& key) {
    while (t) {
        if (key == t->key) return t;
        t = (key < t->key) ? t->left : t->right;
    }
    return nullptr;
}
static void bstInOrder(Node* t, vector<const Course*>& out) {
    if (!t) return;
    bstInOrder(t->left, out);
    out.push_back(&t->value);
    bstInOrder(t->right, out);
}
static void bstDestroy(Node* t) {
    if (!t) return;
    bstDestroy(t->left); bstDestroy(t->right); delete t;
}

// ------------ String utils ------------
static inline string trim(const string& s) {
    size_t a = s.find_first_not_of(" \t\r\n");
    if (a == string::npos) return "";
    size_t b = s.find_last_not_of(" \t\r\n");
    return s.substr(a, b - a + 1);
}
static inline string toUpper(string s) {
    for (char& ch : s) ch = (char)toupper((unsigned char)ch);
    return s;
}
static vector<string> splitCSV(const string& line) {
    vector<string> toks; string tok; stringstream ss(line);
    while (getline(ss, tok, ',')) toks.push_back(trim(tok));
    return toks;
}
static void stripUTF8BOM(string& s) {
    if (s.size() >= 3 && (unsigned char)s[0]==0xEF && (unsigned char)s[1]==0xBB && (unsigned char)s[2]==0xBF)
        s.erase(0,3);
}

// ------------ Printing ------------
static void printCourseLine(const Course& c) {
    cout << c.number << ", " << c.title << '\n';
}

// Numbers-only prereq line to match Sample Output
static void printCourseWithPrereqs(Node* /*root*/, const Course& c) {
    cout << c.number << ", " << c.title << '\n';
    if (c.prereqs.empty()) { cout << "Prerequisites: None\n"; return; }
    cout << "Prerequisites: ";
    for (size_t i = 0; i < c.prereqs.size(); ++i) {
        cout << toUpper(c.prereqs[i]);
        if (i + 1 < c.prereqs.size()) cout << ", ";
    }
    cout << '\n';
}

// ------------ File loading ------------
static bool loadFromFile(const string& filename, Node*& root) {
    ifstream fin(filename);
    if (!fin.is_open()) { cerr << "Error: could not open file '" << filename << "'.\n"; return false; }

    bstDestroy(root); root = nullptr;

    string line; size_t lineNo = 0;
    unordered_set<string> seen; seen.reserve(256);

    while (getline(fin, line)) {
        ++lineNo; stripUTF8BOM(line); line = trim(line);
        if (line.empty()) continue;

        vector<string> t = splitCSV(line);
        if (t.size() < 2) { cerr << "Format error (line " << lineNo << "): expected course number and title.\n"; return false; }
        string num = trim(t[0]), title = trim(t[1]);
        if (num.empty() || title.empty()) { cerr << "Format error (line " << lineNo << "): empty course number or title.\n"; return false; }

        string key = toUpper(num);
        if (seen.count(key)) { cerr << "Format error (line " << lineNo << "): duplicate course '" << num << "'.\n"; return false; }
        seen.insert(key);

        Course c; c.number = num; c.title = title;
        for (size_t i = 2; i < t.size(); ++i) if (!t[i].empty()) c.prereqs.push_back(t[i]);

        root = bstInsert(root, key, c);
    }

    // Optional warnings for missing prereqs (not printed in sample output)
    // vector<const Course*> all; bstInOrder(root, all);
    // for (const Course* cp : all)
    //     for (const string& p : cp->prereqs)
    //         if (!bstFind(root, toUpper(p)))
    //             cerr << "Warning: prerequisite '" << p << "' referenced by " << cp->number << " not found in file.\n";

    return true;
}

// ------------ Actions ------------
static void printAll(Node* root) {
    vector<const Course*> list; bstInOrder(root, list);
    cout << "Here is a sample schedule:\n\n";
    for (const Course* c : list) printCourseLine(*c);
    cout << '\n';
}
static void printOne(Node* root) {
    cout << "What course do you want to know about? ";
    cout << flush;                      // ensure prompt shows before input
    string q; getline(cin, q); q = trim(q);
    if (q.empty()) { cout << "Invalid input.\n\n"; return; }
    if (Node* n = bstFind(root, toUpper(q))) printCourseWithPrereqs(root, n->value);
    else cout << "Course not found.\n";
    cout << '\n';
}

// ------------ Menu ------------
static void printMenu() {
    cout << "    1. Load Data Structure.\n";
    cout << "    2. Print Course List.\n";
    cout << "    3. Print Course.\n";
    cout << "    9. Exit\n\n";
    cout << flush;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(&cout); // tie ensures prompts flush before getline()

    Node* root = nullptr;
    bool loaded = false;

    cout << "Welcome to the course planner.\n\n";
    printMenu();

    while (true) {
        cout << "What would you like to do? ";
        cout << flush;                  // flush before getline() on Windows
        string opt; if (!getline(cin, opt)) break;
        opt = trim(opt);
        cout << '\n';

        if (opt == "9") {
            cout << "Thank you for using the course planner!\n";
            break;
        }
        else if (opt == "1") {
            cout << "Enter course data filename: ";
            cout << flush;
            string fname; if (!getline(cin, fname)) { cout << "Invalid input.\n\n"; printMenu(); continue; }
            fname = trim(fname);
            if (fname.empty()) { cout << "Filename cannot be empty.\n\n"; printMenu(); continue; }
            loaded = loadFromFile(fname, root);
            cout << '\n';
            printMenu();
        }
        else if (opt == "2") {
            if (!loaded) { printMenu(); continue; } // sample shows no warning, just reprints menu
            printAll(root);
            printMenu();
        }
        else if (opt == "3") {
            if (!loaded) { printMenu(); continue; }
            printOne(root);
            printMenu();
        }
        else {
            cout << opt << " is not a valid option.\n\n";
            printMenu();
        }
    }

    bstDestroy(root);
    return 0;
}
