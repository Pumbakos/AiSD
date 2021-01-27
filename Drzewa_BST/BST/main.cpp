#include <cstdio>
#include <iostream>

struct node
{
    int data;
    node *left;
    node *right;
};

bool search(node *tree, int x)
{
    if (tree != NULL)
    {
        if (tree->data != x)
        {
            if (x >= tree->data)
            {
                search(tree->right, x);
            }
            else
            {
                search(tree->left, x);
            }
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}

/*
NOTE: Zadanie 4
a) 2, 252, 401, 398, 330, 344, 397, 363.
b) 924, 220, 911, 244, 898, 258, 362, 363.
c) 925, 202, 911, 240, 912, 245, 363. REVIEW -> Nie może zostać sprawdzone w procedurze SZUKAJ
d) 2, 399, 387, 219, 266, 382, 381, 278, 363.
e) 935, 278, 347, 621, 299, 392, 358, 363. REVIEW -> Nie może zostać sprawdzone w procedurze SZUKAJ
*/

/*
NOTE: Zadanie 5
REVIEW: a)
1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
           \
            7

REVIEW: b)
                __4__
               /     \
              2       6
             / \     / \
            1   3   5   7
REVIEW: c)
                1
                 \
                  6
                 / \
                2   7
                 \
                  4
                 / \
                3   5

*/

/*
NOTE: Zadanie 6
REVIEW: a)
2
 \
  3
   \
    4
     \
      5
       \
        6
         \
          7

REVIEW: b)
                __5__
               /     \
              2       6
             / \     /
            1   3   7
REVIEW: c)
                   2
                  / \ 
                 6   7
                  \
                   4
                  / \
                 3   5

*/

int main()
{
    return EXIT_SUCCESS;
}
