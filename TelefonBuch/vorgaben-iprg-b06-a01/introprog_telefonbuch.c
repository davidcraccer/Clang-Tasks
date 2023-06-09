#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "introprog_telefonbuch.h"

/*
 * Fügt einen Knoten mit der Telefonnummer phone und dem Namen name
 * in den Binären Suchbaum bst ein.  Für den Suchbaum soll die
 * Eigenschaft gelten, dass alle linken Kinder einen Wert kleiner
 * gleich (<=) und alle rechten Kinder einen Wert größer (>) haben.
 */

void bst_insert_node(bstree *bst, unsigned long phone, char *name)
{
    if (bst == NULL || find_node(bst, phone))
    {
        // If bst is NULL, return immediately
        return;
    }
    
    bst_node *anode = malloc(sizeof(bst_node));
    anode->phone = phone;
    anode->name = malloc((strlen(name)+1)*sizeof(char));
    strncpy(anode->name, name, strlen(name));
    anode->name[strlen(name)] = '\0';

    anode->left = NULL;
    anode->right = NULL;

    if (bst->root == NULL)
    {
        // If the tree is empty, set the root to the new node
        anode->parent =NULL;
        bst->root = anode;
    }
    else{

    bst_node *y = NULL;
    bst_node *x = bst->root;
    while (x != NULL)
    {
        
        y = x;
        if (phone <= x->phone)
        {
            x = x->left;
        }
        else
        {
            x = x->right;
        }
    }

    if(phone<=y->phone){
        anode -> parent=y;
        y->left=anode;
    }
    else{
        anode->parent=y;
        y->right=anode;
    }
    
    }
}
/*
 * Diese Funktion liefert einen Zeiger auf einen Knoten im Baum mit
 * dem Wert phone zurück, falls dieser existiert.  Ansonsten wird
 * NULL zurückgegeben.
 */
bst_node *find_node(bstree *bst, unsigned long phone)
{
    if (phone > 999999999 || phone < 1)
    {
        return NULL;
    }
    // Check if the tree is empty
    if (bst->root == NULL)
    {
        return NULL;
    }

    bst_node *current = bst->root;

    while (current)
    {
        if (current->phone == phone)
        {
            return current;
        }

        if (phone <= current->phone)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    return NULL;
}
/* Gibt den Unterbaum von node in "in-order" Reihenfolge aus */
void bst_in_order_walk_node(bst_node *node)
{
    if(node) 
	{
		bst_in_order_walk_node(node -> left);
		print_node(node);
		bst_in_order_walk_node(node -> right);
	}

}

/*
 * Gibt den gesamten Baum bst in "in-order" Reihenfolge aus.  Die
 * Ausgabe dieser Funktion muss aufsteigend soriert sein.
 */
void bst_in_order_walk(bstree *bst)
{
    if (bst != NULL)
    {
        bst_in_order_walk_node(bst->root);
    }
}

/*
 * Löscht den Teilbaum unterhalb des Knotens node rekursiv durch
 * "post-order" Traversierung, d.h. zurerst wird der linke und dann
 * der rechte Teilbaum gelöscht.  Anschließend wird der übergebene
 * Knoten gelöscht.
 */
void bst_free_subtree(bst_node *node)
{

    if (node == NULL)
    {
        return;
    }
    else if(node){

    bst_free_subtree(node->left);
    bst_free_subtree(node->right);
    free(node->name);
    free(node);
    }
}
/*
 * Löscht den gesamten Baum bst und gibt den entsprechenden
 * Speicher frei.
 */
void bst_free_tree(bstree *bst)
{
    if (bst != NULL && bst->root != NULL)
    {
        bst_free_subtree(bst->root);
        bst->root = NULL;
    }
}
