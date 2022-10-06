#include <iostream>
using namespace std;

struct node
{
    int key;
    struct node *left;
    struct node *right;
    struct node *parent;
};

struct node *newnode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = temp->parent = NULL;
    return temp;
}
struct node *insert(struct node *node, int key)
{
    if (node == NULL)
        return newnode(key);
    else
    {
        struct node *temp;
        if (key < node->key)
        {
            temp = insert(node->left, key);
            node->left = temp;
            temp->parent = node;
        }

        else
        {
            temp = insert(node->right, key);
            node->right = temp;
            temp->parent = node;
        }
        return node;
    }
}
struct node *search(struct node *node, int key)
{
    struct node *current = node;
    if (current == NULL || current->key == key)
        return current;
    else if (key < current->key)
        return search(current->left, key);
    else
        return search(current->right, key);
}
struct node *find_min(struct node *node)
{
    struct node *current = node;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}
struct node *find_max(struct node *node)
{
    struct node *current = node;
    while (current->right != NULL)
        current = current->right;
    return current;
}
void inorder(struct node *node)
{
    if (node != NULL)
    {
        inorder(node->left);
        cout << node->key << " ";
        inorder(node->right);
    }
    else
        return;
}
struct node *successor(struct node *node, int key)
{
    struct node *item = search(node, key);
    if (item->right != NULL)
    {
        return find_min(item->right);
    }
    else
    {
        struct node *p = item->parent;
        while (p != NULL && item == p->right)
        {
            item = p;
            p = p->parent;
        }
        return p;
    }
}
struct node *predecessor(struct node *node, int key)
{
    struct node *item = search(node, key);
    if (item->left != NULL)
        return find_max(item->left);
    else
    {
        struct node *p = item->parent;
        while (p != NULL && item == p->left)
        {
            item = p;
            p = p->parent;
        }
        return p;
    }
}
struct node *del(struct node *node, int key)
{
    struct node *ptr = NULL;
    ptr = search(node, key);
    if(ptr==NULL)
        return node;
    if (ptr->left == NULL && ptr->right == NULL)
    {
        if (ptr->parent != NULL)
        {
            if (ptr->parent->left == ptr)
            {
                ptr->parent->left = NULL;
                ptr = NULL;
            }
            else
            {
                ptr->parent->right = NULL;
                ptr = NULL;
            }
        }
        else
        {
            node = NULL;
        }
        free(ptr);
        return node;
    }
    else if (ptr->left == NULL && ptr->right != NULL)
    {
        if (ptr->parent != NULL)
        {
            if (ptr->parent->key > key)
            {
                ptr->parent->left = ptr->right;
                ptr->right->parent = ptr->parent;
            }
            else
            {
                ptr->parent->right = ptr->right;
                ptr->right->parent = ptr->parent;
            }
        }
        else
        {
            node=ptr->right;
            ptr->right->parent=NULL;
        }
        free(ptr);
        return node;
    }
    else if(ptr->left!=NULL && ptr->right==NULL)
    {
        if(ptr->parent!=NULL)
        {
            if(ptr->parent->key>key)
            {
                ptr->parent->left=ptr->left;
                ptr->left->parent=ptr->parent;
            }
            else
            {
                ptr->parent->right=ptr->left;
                ptr->left->parent=ptr->parent;
            }
        }
        else
        {
            node=ptr->left;
            ptr->left->parent=NULL;
        }
        free(ptr);
        return node;
    }
    else
    {
        struct node *temp = successor(ptr, key);
        int temp_data = temp->key;
        del(node, temp->key);
        ptr->key = temp_data;
        free(temp);
        return node;
    }
}
int main()
{
    struct node *root = NULL,*temp=NULL;
    int choice,key;
    cout<<"1.Insertion"<<endl<<"2.Deletion"<<endl<<"3.Inorder Traversal"<<endl<<"4. Predecessor"<<endl<<"5.Successor"<<endl<<"6.Search"<<endl<<"7.Maximum"<<endl<<"8.Minimum"<<endl<<"9.Exit"<<endl;
    do
    {
        cout<<"Enter your choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"Enter the key to be inserted: ";
            cin>>key;
            root=insert(root,key);
            break;
        case 2:
            cout<<"Enter the key to be deleted: ";
            cin>>key;
            root=del(root,key);
            break;
        case 3:
            inorder(root);
            cout<<endl;
            break;
        case 4:
            cout<<"Which element's predecessor do you want to find: ";
            cin>>key;
            temp=predecessor(root,key);
            cout<<"Predecessor: "<<temp->key<<endl;
            break;
        case 5:
            cout<<"Which element's successor do you want to find: ";
            cin>>key;
            temp=successor(root,key);
            cout<<"Successor: "<<temp->key<<endl;
            break;
        case 6:
            cout<<"Which element you want to be searched: ";
            cin>>key;
            temp=search(root,key);
            cout<<"Searched Element: "<<temp->key<<endl;
            break;
        case 7:
            temp=find_max(root);
            cout<<"Maximum node: "<<temp->key<<endl;
            break;
        case 8:
            temp=find_min(root);
            cout<<"Minimum node: "<<temp->key<<endl;
            break;
        default:
            break;
        }
    } while (choice!=9);
    
    return 0;
}