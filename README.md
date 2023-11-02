# Binary Trees

## Introduction

Welcome to the Binary Trees repository. This repository houses C implementations of binary trees, an essential data structure in computer science.

## Getting Started

To utilize the programs within this repository, follow these steps:

1. Clone this repository to your local machine:

   ```bash
   git clone https://github.com/iakev/binary_trees.git
   ```

2. Navigate to the cloned repository:

   ```bash
   cd binary_trees
   ```

3. Compile a specific program using a C compiler (e.g., GCC). Replace `program.c` with the program's name you wish to compile and `output` with your chosen output filename:

   ```bash
   gcc -Wall -Werror -Wextra -pedantic program.c -o output
   ```

4. Execute the compiled program:
   ```bash
   ./output
   ```

## Program Listing

1. **Node Creation and Insertion:**

   - `0-binary_tree_node.c`: Create a new binary tree node.
   - `1-binary_tree_insert_left.c`: Inserts a new node as the left-child.
   - `2-binary_tree_insert_right.c`: Inserts a new node as the right-child.

2. **Tree Operations:**

   - `3-binary_tree_delete.c`: Deletes an entire binary tree.
   - `4-binary_tree_is_leaf.c`: Checks if a node is a leaf.
   - `5-binary_tree_is_root.c`: Checks if a node is the root.

3. **Tree Traversal:**

   - `6-binary_tree_preorder.c`: Pre-order traversal (root-left-right).
   - `7-binary_tree_inorder.c`: In-order traversal (left-root-right).
   - `8-binary_tree_postorder.c`: Post-order traversal (left-right-root).

4. **Tree Measurements:**

   - `9-binary_tree_height.c`: Measures the tree's height.
   - `10-binary_tree_depth.c`: Measures the depth of a node.
   - `11-binary_tree_size.c`: Calculates the number of nodes.
   - `12-binary_tree_leaves.c`: Counts the leaves.
   - `13-binary_tree_nodes.c`: Counts nodes with at least one child.
   - `14-binary_tree_balance.c`: Computes the balance factor.

5. **Tree Properties:**

   - `15-binary_tree_is_full.c`: Checks if the tree is a full binary tree.
   - `16-binary_tree_is_perfect.c`: Checks if the tree is a perfect binary tree.
   - `17-binary_tree_sibling.c`: Finds a node's sibling.
   - `18-binary_tree_uncle.c`: Finds a node's uncle.

6. **Lowest Common Ancestor:**

   - `100-binary_trees_ancestor.c`: Finds the lowest common ancestor.
   - `100-short_binary_trees_ancestor.c`: Optimized version for lowest common ancestor.

7. **Tree Rotations:**

   - `102-binary_tree_is_complete.c`: Checks if the tree is complete.
   - `103-binary_tree_rotate_left.c`: Performs a left-rotation.
   - `104-binary_tree_rotate_right.c`: Performs a right-rotation.

8. **Binary Search Tree (BST) Operations:**

   - `110-binary_tree_is_bst.c`: Checks if the tree is a binary search tree.
   - `112-array_to_bst.c`: Builds a BST from an array.
   - `113-bst_search.c`: Searches for a value in a BST.
   - `114-bst_remove.c`: Removes a node from a BST.

9. **AVL Tree Operations:**
   - `120-binary_tree_is_avl.c`: Checks if the tree is an AVL tree.
   - `121-avl_insert.c`: Inserts a value into an AVL tree.
