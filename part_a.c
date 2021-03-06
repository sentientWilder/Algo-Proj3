/*	Dan Wilder
 *	
 *	University of Missouri - St. Louis
 *	CS 3130 - Design & Analysis of Algorithms
 *	Galina Piatnitskiaia (instructor)
 *	Project #3
 *	
 *	part_a.c - Program satisfying part A requirements
 */

#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    
    const int arr[] = {30, 10, 45, 38, 20, 50, 25, 33, 8, 12};
    const int SIZE = 10;
    struct node *newNode = NULL, *root = NULL, *deleteNode;
    int i, choice, search;
    
    // Insert array elements into tree
    for (i = 0; i < SIZE; ++i) {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->key = arr[i];
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->p = NULL;
        treeInsert(&root, newNode);
    }
    
    printf("Initial binary search tree was created!\n");
    printf("Elements from array: ");
    printf("<30, 10, 45, 38, 20, 50, 25, 33, 8, 12>\n");
    printf("were inserted in that order.\n\n");
    
    // Menu-Driven
    do {
        printf("MENU SELECTION\n");
        printf("\t0)\tEXIT\n");
        printf("\t1)\tDisplay inorder\n");
        printf("\t2)\tDisplay postorder\n");
        printf("\t3)\tDisplay preorder\n");
        printf("\t4)\tTree search\n");
        printf("\t5)\tTree height\n");
        printf("\t6)\tTree delete\n");
        
        printf("\n\t==> ");
        scanf("%d", &choice);
        
        switch(choice) {
            
            case 0 :
                printf("\nHave a nice day!\n");
                break;

            case 1 :
                printf("\n\nInorder: ");
                inorder(root);
                printf("\n\n"); 
                break; 
                
            case 2 :
                printf("\n\nPostorder: ");
                postorder(root);
                printf("\n\n");
                break; 

            case 3 :
                printf("\n\nPreorder: ");
                preorder(root);
                printf("\n\n");
                break; 
                
            case 4 :
                printf("\n\nSpecify search value\n\t==> ");
                scanf("%d", &search);
                treeSearch(root, search, 1);
                printf("\n\n");
                break;
                
            case 5 :
                printf("\n\nTree height %d\n\n", height(root));
                break;
                
            case 6 :
                printf("\n\nSpecify key value of node to delete\n\t==> ");
                scanf("%d", &search);
                deleteNode = treeSearch(root, search, 0);
                
                if (deleteNode != NULL) {
                    treeDelete(&root, deleteNode);
                    printf("Complete!\n\n");
                }
                
                else 
                    printf("\nNode with that key value not present!\n\n");
                    
                free(deleteNode);
                break;
                
            default :
                printf("\n\nInvalid Choice\n\n");
        }
    } while(choice != 0);
    
    return 0;
}