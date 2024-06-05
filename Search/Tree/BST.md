# BST Binary search tree

**condizione: deve essere costruito come un albero, si intende che la**  
**"Foglia sinistra è sempre più piccola della foglia destra.**

>[!NOTE]
>La strutturazione dell'albero può essere complessa, però la ricerca come si vede è molto semplice.
>Finchè non trova il NULL o l'id girovagando tra le "Foglie".

```c++ 

typedef class Tree
{
    int id;
    struct Tree* left;
    struct Tree* right;
} Tree;

```

```c++

Tree* search(Tree* root, int key)
{
    if (root == NULL || root->id == key)
		return root; // Trovato o albero vuoto
    if (key < root->id)
		return search(root->left, key); // Cerca a sinistra
    return search(root->right, key); // Cerca a destra
}

```