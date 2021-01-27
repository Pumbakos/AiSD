#include <iostream>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

void create(node *tree, int num)
{
    if (num > 0)
    {
        node *left_node = new node{num - 1, NULL, NULL};
        node *right_node = new node{num + 2, NULL, NULL};
        tree->left = left_node;
        tree->right = right_node;
        create(tree->left, num - 2);
        create(tree->right, num - 2);
    }
}

/**
 * ANCHOR: Zadanie 1
 */

bool search(node *tree, int x)
{
    if (tree == NULL)
        return false;
    else
    {
        if (tree->data == x)
        {
            return true;
        }

        else if (search(tree->left, x) == true)
        {
            return true;
        }

        else if (search(tree->right, x) == true)
        {
            return true;
        }
    }
    return false;
}

/**
 * ANCHOR: Zadanie 2
 */

int node_count(node *tree)
{
    int counter = 0;
    if (tree != NULL)
    {
        counter++;
        counter += node_count(tree->left) + node_count(tree->right);
    }
    return counter;
}

int leaves_count(node *tree)
{
    if (tree == NULL)
    {
        return 0;
    }

    if (tree->left == NULL && tree->right == NULL)
    {
        return 1;
    }

    return leaves_count(tree->left) + leaves_count(tree->right);
}

int right_children_count(node *tree)
{
    int counter = 0;
    if (tree == NULL)
    {
        return counter;
    }

    if (tree->right != NULL)
    {
        counter++;
    }
    counter += right_children_count(tree->left) + right_children_count(tree->right);
    return counter;
}

int tree_height(node *tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    else if (tree != NULL && tree->left == NULL && tree->right == NULL)
    {
        return 0;
    }
    int left_height = tree_height(tree->left);
    int right_height = tree_height(tree->right);
    if (left_height > right_height)
    {
        return left_height + 1;
    }
    else
    {
        return right_height + 1;
    }
}

/**
 * ANCHOR: Zadanie 3
 */

void createBST(node *tree, int num)
{
    if (num > 0)
    {
        node *left_node = new node{(tree->data) - 1, NULL, NULL};
        node *right_node = new node{(tree->data) + 1, NULL, NULL};
        tree->left = left_node;
        tree->right = right_node;
        createBST(tree->left, num - 2);
        createBST(tree->right, num - 2);
    }
}

bool is_balanced(node *tree)
{
    if (tree == NULL)
    {
        return true;
    }
    int left = 0;
    int right = 0;
    left = tree_height(tree->left);
    right = tree_height(tree->right);
    int r = right - left;
    if ((r == 0 || r == 1 || r == -1) && is_balanced(tree->right) && is_balanced(tree->left))
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * ANCHOR: Zadanie 4
 */

bool is_BST(node *tree)
{
    if (tree == NULL)
    {
        return true;
    }
    if (tree->left != NULL && (tree->left->data > tree->data))
    {
        return false;
    }
    if (tree->right != NULL && (tree->right->data < tree->data))
    {
        return false;
    }
    if (is_BST(tree->left) && is_BST(tree->right))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool is_leaf(node *tree)
{
    if (tree != NULL && tree->left == NULL && tree->right == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * ANCHOR: Zadanie 5
 */

void delete_leaves(node *tree)
{
    if (tree != NULL)
    {
        if (is_leaf(tree->left))
        {
            delete tree->left;
            tree->left = NULL;
        }
        else
            delete_leaves(tree->left);
        if (is_leaf(tree->right))
        {
            delete tree->right;
            tree->right = NULL;
        }
        else
            delete_leaves(tree->right);
    }
}

/**
 * ANCHOR: Zadanie 6
 */

node *create_6()
{
    node *tree = new node{
        10,
        new node{
            5,
            new node{
                4,
                new node{0, NULL, NULL},
                NULL},
            new node{
                6,
                NULL,
                new node{
                    7,
                    NULL,
                    new node{9, NULL, NULL}}}},
        new node{
            20,
            new node{
                15,
                new node{13, NULL, NULL},
                NULL},
            new node{30, NULL, NULL}}};
    return tree;
}

void preorder(node *p)
{
    if (p != NULL)
    {
        cout << p->data << ", ";
        preorder(p->left);
        preorder(p->right);
    }
}

void inorder(node *p)
{
    if (p != NULL)
    {
        inorder(p->left);
        cout << p->data << ", ";
        inorder(p->right);
    }
}

void postorder(node *p)
{
    if (p != NULL)
    {
        postorder(p->left);
        postorder(p->right);
        cout << p->data << ", ";
    }
}

void preorder_a(node *p)
{
    if (p != NULL)
    {
        if (p->left != 0 && p->data - p->left->data < 2)
        {
            p->left->data += 2;
        }
        cout << p->data << ", ";
        preorder_a(p->left);
        preorder_a(p->right);
    }
}

void inorder_a(node *p)
{
    if (p != NULL)
    {
        if (p->left != 0 && p->data - p->left->data < 2)
        {
            p->left->data += 2;
        }
        inorder_a(p->left);
        cout << p->data << ", ";
        inorder_a(p->right);
    }
}

void postorder_a(node *p)
{
    if (p != NULL)
    {
        if (p->left != 0 && p->data - p->left->data < 2)
        {
            p->left->data += 2;
        }
        postorder_a(p->left);
        postorder_a(p->right);
        cout << p->data << ", ";
    }
}

void preorder_b(node *p)
{
    if (p != NULL)
    {
        if (p->left == 0)
        {
            p->right = 0;
        }
        cout << p->data << ", ";
        preorder_b(p->left);
        preorder_b(p->right);
    }
}

void inorder_b(node *p)
{
    if (p != NULL)
    {
        if (p->left == 0)
        {
            p->right = 0;
        }
        inorder_b(p->left);
        cout << p->data << ", ";
        inorder_b(p->right);
    }
}

void postorder_b(node *p)
{
    if (p != NULL)
    {
        if (p->left == 0)
        {
            p->right = 0;
        }
        postorder_b(p->left);
        postorder_b(p->right);
        cout << p->data << ", ";
    }
}

/**
 * ANCHOR: Zadanie 7
 */

node *create_7()
{
    node *tree = new node{
        4,
        new node{
            6,
            new node{4, NULL, NULL},
            new node{4, NULL, NULL}},
        new node{
            7,
            new node{7, NULL, NULL},
            new node{2, NULL, NULL}}};
    return tree;
}

/**
 * ANCHOR: Zadanie 8
 */

void mirror_tree(node *tree)
{
    if (tree != NULL)
    {
        mirror_tree(tree->left);
        mirror_tree(tree->right);
        if (tree->left != NULL && tree->right != NULL)
        {
            node *wsk = tree->left;
            tree->left = tree->right;
            tree->right = wsk;
        }
    }
}

/**
 * ANCHOR: Zadanie 9
 */

void print_tree(node *tree, int depth = 0, char prefix = ' ')
{
    if (tree != NULL)
    {
        for (int i = 0; i < depth; i++)
        {
            cout << prefix;
        }
        cout << tree->data << endl;
        print_tree(tree->left, depth + 1, prefix);
        print_tree(tree->right, depth + 1, prefix);
    }
}

/**
 * ANCHOR: Zadanie 10
 */

struct node_calc
{
    char op;
    int numer;
    node_calc *left;
    node_calc *right;
};

int eval(node_calc *tree)
{
    if (tree != NULL)
    {
        if (tree->left == NULL && tree->right == NULL)
        {
            return tree->numer;
        }
        else
        {
            int a = eval(tree->left);
            int b = eval(tree->right);
            if (tree->op == '+')
            {
                return a + b;
            }
            if (tree->op == '-')
            {
                return a - b;
            }
            if (tree->op == '*')
            {
                return a * b;
            }
            if (tree->op == '/' && b != 0)
            {
                return a / b;
            }
            else
            {
                cout << "Proba dzielenia przez zero!";
            }
        }
    }
}

node_calc *create_10()
{
    node_calc *calc = new node_calc{
        '*',
        NULL,
        new node_calc{
            '+',
            NULL,
            new node_calc{NULL, 7, NULL, NULL},
            new node_calc{NULL, 8, NULL, NULL}},
        new node_calc{
            '-',
            NULL,
            new node_calc{NULL, 3, NULL, NULL},
            new node_calc{NULL, 2, NULL, NULL}}};
    return calc;
}

int main()
{
    /**
     * NOTE: Wykonanie Zadania 1
     */

    cout << "\t\t\t\tZadanie 1" << endl;
    cout << "Wypelniam drzewo:" << endl;
    node *tree = new node{5, NULL, NULL};
    create(tree, 4);
    print_tree(tree);
    cout << "Sprawdzam, czy \'1\' znajduje sie w drzewie:" << endl;
    cout << search(tree, 1);

    /**
     * NOTE: Wykonanie Zadania 2
     */

    cout << "\n\n\t\t\t\tZadanie 2" << endl;
    cout << "Sprawdzam liczbe wierzcholkow: " << endl;
    cout << node_count(tree) << endl;

    cout << "Sprawdzam liczbe lisci: " << endl;
    cout << leaves_count(tree) << endl;

    cout << "Sprawdzam liczbe prawych potomkow: " << endl;
    cout << right_children_count(tree) << endl;

    cout << "Sprawdzam wysokosc drzewa: " << endl;
    cout << tree_height(tree);

    /**
     * NOTE: Wykonanie Zadania 3
     */

    cout << "\n\n\t\t\t\tZadanie 3" << endl;
    cout << "Sprawdzam czy drzewo jest zbalansowane: " << endl;
    cout << is_balanced(tree);

    /**
     * NOTE: Wykonanie Zadania 4
     */

    cout << "\n\n\t\t\t\tZadanie 4" << endl;
    cout << "Sprawdzam czy drzewo jest drzewem BST: " << endl;
    cout << is_BST(tree) << endl;

    cout << "Tworze nowe drzewo, ktore jest BST: " << endl;
    node *bst_tree = new node{5, NULL, NULL};

    createBST(bst_tree, 4);
    print_tree(bst_tree);
    cout << "Sprawdzam, czy ono jest BST:" << endl;
    cout << is_BST(bst_tree);

    /**
     * NOTE: Wykonanie Zadania 6
     */

    cout << "\n\n\t\t\t\tZadanie 6" << endl;
    node *tree_6 = create_6();

    cout << "Drzewo wypisane preorder:\n";
    preorder(tree_6);
    cout << endl;

    cout << "\nDrzewo wypisane inorder:\n";
    inorder(tree_6);
    cout << endl;

    cout << "\nDrzewo wypisane postorder:\n";
    postorder(tree_6);

    cout << endl
         << endl
         << "\na) Po zastosowaniu dzialania, procedury wydrukuja:\n";
    cout << "Drzewo wypisane preorder:\n";
    preorder_a(tree_6);
    cout << endl;

    tree_6 = create_6();
    cout << "\nDrzewo wypisane inorder:\n";
    inorder_a(tree_6);
    cout << endl;

    tree_6 = create_6();
    cout << "\nDrzewo wypisane postorder:\n";
    postorder_a(tree_6);
    cout << endl;

    tree_6 = create_6();
    cout << endl
         << endl
         << "\nb) Po zastosowaniu dzialania, procedury wydrukuja:\n";
    cout << "Drzewo wypisane preorder:\n";
    preorder_b(tree_6);
    cout << endl;

    tree_6 = create_6();
    cout << "\nDrzewo wypisane inorder:\n";
    inorder_b(tree_6);
    cout << endl;

    tree_6 = create_6();
    cout << "\nDrzewo wypisane postorder:\n";
    postorder_b(tree_6);

    /**
     * NOTE: Wykonanie Zadania 7
     */

    cout << "\n\n\t\t\t\tZadanie 7" << endl;
    node *tree_7 = create_7();

    cout << "Drzewo wypisane preorder:" << endl;
    preorder(tree_7);
    cout << endl;
    cout << "\nDrzewo wypisane inorder:" << endl;
    inorder(tree_7);

    /**
     * NOTE: Wykonanie Zadania 8
     */

    cout << "\n\n\t\t\t\tZadanie 8" << endl;
    cout << "Drzewo przed odbiciem:" << endl;
    print_tree(tree_7);
    cout << endl;

    mirror_tree(tree_7);
    cout << "Drzewo po odbiciu:" << endl;
    print_tree(tree_7);
    cout << endl;

    /**
     * NOTE: Wykonanie Zadania 9
     */

    cout << "\n\n\t\t\t\tZadanie 9" << endl;
    tree_6 = create_6();
    print_tree(tree_6);

    /**
     * NOTE: Wykonanie Zadania 10
     */

    cout << "\n\n\t\t\t\tZadanie 10" << endl;
    node_calc *calc = create_10();
    cout << eval(calc) << endl;

    return EXIT_SUCCESS;
}
