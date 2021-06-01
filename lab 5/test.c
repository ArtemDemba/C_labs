#include <string.h>
#include <assert.h>
#include "main.h"
void test()
{
    struct Node* root = NULL;
    assert(push_back(&root, 0) == 0);
    assert(push_back(&root, 1) == 0);
    assert(push_back(&root, 3) == 0);
    assert(push_back(&root, 2) == 0);
    assert(push_front(&root, 5) == 0);
    assert(push_front(&root, 6) == 0);
    assert(push_front(&root, 7) == 0);
    assert(push_front(&root, 8) == 0);
}
#undef main
int main()
{
    test();
    return 0;
}