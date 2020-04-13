# Programming Assignment 3: Self-Balancing Binary Search Trees (BSTs)
In this Programming Assignment, you will be assessing your understanding of three types of self-balancing Binary Search Trees (BSTs): Randomized Search Trees (RSTs), AVL Trees, and Red-Black Trees.

## Representing Graphs as Edge Lists
For multiple parts of this assignment, you will need to provide examples of trees as the solution. One way of representing any arbitrary [graph](https://en.wikipedia.org/wiki/Graph_(abstract_data_type)), including a tree, is as an [edge list](https://en.wikipedia.org/wiki/Edge_list). In this assignment, you will represent edge lists as plain-text files where each line of the file represents an edge between nodes ``u`` and ``v`` in the format ``u -> v``.

For example, we can represent the following BST:

<img src="https://g.gravizo.com/svg?digraph%20G%20%7B%0A%20%2042%20-%3E%2010%3B%0A%20%2042%20-%3E%2050%3B%0A%20%2010%20-%3E%205%3B%0A%20%2010%20-%3E%2020%3B%0A%20%2050%20-%3E%2045%3B%0A%20%2050%20-%3E%2060%3B%0A%7D">

In the following plain-text edge list:

```
42 -> 10
42 -> 50
10 -> 5
10 -> 20
50 -> 45
50 -> 60
```

Note that, in this assignment, we don't care about the order in which you list the edges: any arbitrary order is the same. For example, the following edge list is completely equivalent to the previous:

```
10 -> 5
10 -> 20
42 -> 10
42 -> 50
50 -> 45
50 -> 60
```

## Part 1: AVL Rotations (25 points)
In order to rebalance the tree after an insertion, self-balancing BSTs can make use of [AVL Rotations](https://www.youtube.com/watch?v=xzmLuS0ZJmA&list=PLM_KIlU0WoXmkV4QB1Dg8PtJaHTdWHwRS&index=34), which allow us to restructure the tree without breaking the BST properties.

### Task 1a: Create ``1a.txt`` (5 points)
Imagine we have the following BST:

<img src="https://g.gravizo.com/svg?digraph%20G%20%7B%0A0%20%5Bfontcolor%3D%22transparent%22%20color%3D%22transparent%22%5D%3B%0A15%20%5Bfontcolor%3D%22transparent%22%20color%3D%22transparent%22%5D%3B%0A10%20-%3E%200%20%5Bcolor%3D%22transparent%22%5D%3B%0A10%20-%3E%2020%3B%0A20%20-%3E%2015%20%5Bcolor%3D%22transparent%22%5D%3B%0A20%20-%3E%2030%3B%0A%7D">

Its edge list is the following:

```
10 -> 20
20 -> 30
```

Create a file called ``1a.txt`` (case-sensitive) in the root directory of this repository (i.e., in the same folder as [``README.md``](README.md)) containing the edge list of the tree resulting from doing a **left AVL rotation** on nodes 10 and 20.

### Task 1b: Create ``1b.txt`` (5 points)
Imagine we have the following BST:

<img src="https://g.gravizo.com/svg?digraph%20G%20%7B%0A30%20-%3E%2020%3B%0A30%20-%3E%2035%3B%0A20%20-%3E%2010%3B%0A20%20-%3E%2025%3B%0A%7D">

Its edge list is the following:

```
30 -> 20
30 -> 35
20 -> 10
20 -> 25
```

Create a file called ``1b.txt``  (case-sensitive) in the root directory of this repository (i.e., in the same folder as [``README.md``](README.md)) containing the edge list of the tree resulting from doing a **right AVL rotation** on nodes 30 and 20.

### Task 1c: Create ``1c.txt`` (5 points)
Imagine we have the following BST:

<img src="https://g.gravizo.com/svg?digraph%20G%20%7B%0A30%20-%3E%2020%3B%0A30%20-%3E%2035%3B%0A20%20-%3E%2010%3B%0A20%20-%3E%2025%3B%0A%7D">

Its edge list is the following:

```
30 -> 20
30 -> 35
20 -> 10
20 -> 25
```

Create a file called ``1c.txt``  (case-sensitive) in the root directory of this repository (i.e., in the same folder as [``README.md``](README.md)) containing the edge list of the tree resulting from doing a **left AVL rotation** on nodes 20 and 25.

### Task 1d: Create ``1d.txt`` (5 points)
Imagine we have the following BST:

<img src="https://g.gravizo.com/svg?digraph%20G%20%7B%0A30%20-%3E%2020%3B%0A30%20-%3E%2040%3B%0A20%20-%3E%2010%3B%0A20%20-%3E%2025%3B%0A40%20-%3E%2035%3B%0A40%20-%3E%2045%0A%7D">

Its edge list is the following:

```
30 -> 20
30 -> 40
20 -> 10
20 -> 25
40 -> 35
40 -> 45
```

Create a file called ``1d.txt``  (case-sensitive) in the root directory of this repository (i.e., in the same folder as [``README.md``](README.md)) containing the edge list of the tree resulting from doing a **left AVL rotation** on nodes 40 and 45.

### Task 1e: Create ``1e.txt`` (5 points)
Imagine we have the following BST:

<img src="https://g.gravizo.com/svg?digraph%20G%20%7B%0A30%20-%3E%2020%3B%0A30%20-%3E%2040%3B%0A20%20-%3E%2010%3B%0A20%20-%3E%2025%3B%0A40%20-%3E%2035%3B%0A40%20-%3E%2045%0A%7D">

Its edge list is the following:

```
30 -> 20
30 -> 40
20 -> 10
20 -> 25
40 -> 35
40 -> 45
```

Create a file called ``1e.txt``  (case-sensitive) in the root directory of this repository (i.e., in the same folder as [``README.md``](README.md)) containing the edge list of the tree resulting from doing a **left AVL rotation** on nodes 30 and 40.

## Part 2: Treaps and Randomized Search Trees (RSTs) (25 points)
We first introduced the [Treap](https://en.wikipedia.org/wiki/Treap), which is a mixture of a [Binary Search Tree (BST)](https://en.wikipedia.org/wiki/Binary_search_tree) and a [Heap](https://en.wikipedia.org/wiki/Heap_(data_structure)). Specifically, a Treap contains ``(key,priority)`` tuples, and it maintains the BST properties with respect to its keys as well as the Heap property with respect to its priorities. We then introduced the [Randomized Search Tree (RST)](https://en.wikipedia.org/wiki/Random_binary_tree#Treaps_and_randomized_binary_search_trees), which is a Treap that is given the keys to insert, but that randomly generates the priority of each key.

### Task 2a: Create ``2a.txt`` (5 points)
Imagine we have the following RST, where nodes are ``(key,priority)`` tuples:

<img src="https://g.gravizo.com/svg?digraph%20G%20%7B%0A%22A%5Cn10%22%3B%0A%22F%5Cn20%22%20%20%5Bfontcolor%3D%22transparent%22%20color%3D%22transparent%22%5D%3B%0A%22L%5Cn20%22%20%5Bfontcolor%3D%22transparent%22%20color%3D%22transparent%22%5D%3B%0A%22I%5Cn42%22%20-%3E%20%22E%5Cn21%22%3B%0A%22E%5Cn21%22%20-%3E%20%22A%5Cn10%22%3B%0A%22E%5Cn21%22%20-%3E%20%22F%5Cn20%22%20%5Bcolor%3D%22transparent%22%5D%3B%0A%22I%5Cn42%22%20-%3E%20%22M%5Cn40%22%3B%0A%22M%5Cn40%22%20-%3E%20%22L%5Cn20%22%20%5Bcolor%3D%22transparent%22%5D%3B%0A%22M%5Cn40%22%20-%3E%20%22N%5Cn30%22%3B%0A%7D">

Its edge list is the following:

```
(I,42) -> (E,21)
(I,42) -> (M,40)
(E,21) -> (A,10)
(M,40) -> (N,30)
```

Create a file called ``2a.txt`` (case-sensitive) in the root directory of this repository (i.e., in the same folder as [``README.md``](README.md)) containing the edge list of the RST resulting from inserting ``(G,11)``.

### Task 2b: Create ``2b.txt`` (5 points)
Imagine we have the following RST, where nodes are ``(key,priority)`` tuples:

<img src="https://g.gravizo.com/svg?digraph%20G%20%7B%0A%22A%5Cn10%22%3B%0A%22F%5Cn20%22%20%20%5Bfontcolor%3D%22transparent%22%20color%3D%22transparent%22%5D%3B%0A%22L%5Cn20%22%20%5Bfontcolor%3D%22transparent%22%20color%3D%22transparent%22%5D%3B%0A%22I%5Cn42%22%20-%3E%20%22E%5Cn21%22%3B%0A%22E%5Cn21%22%20-%3E%20%22A%5Cn10%22%3B%0A%22E%5Cn21%22%20-%3E%20%22F%5Cn20%22%20%5Bcolor%3D%22transparent%22%5D%3B%0A%22I%5Cn42%22%20-%3E%20%22M%5Cn40%22%3B%0A%22M%5Cn40%22%20-%3E%20%22L%5Cn20%22%20%5Bcolor%3D%22transparent%22%5D%3B%0A%22M%5Cn40%22%20-%3E%20%22N%5Cn30%22%3B%0A%7D">

Its edge list is the following:

```
(I,42) -> (E,21)
(I,42) -> (M,40)
(E,21) -> (A,10)
(M,40) -> (N,30)
```

Create a file called ``2b.txt`` (case-sensitive) in the root directory of this repository (i.e., in the same folder as [``README.md``](README.md)) containing the edge list of the RST resulting from inserting ``(K,41)``.

### Task 2c: Create ``2c.txt`` (5 points)
Imagine we have the following RST, where nodes are ``(key,priority)`` tuples:

<img src="https://g.gravizo.com/svg?digraph%20G%20%7B%0A%22A%5Cn10%22%3B%0A%22F%5Cn20%22%20%20%5Bfontcolor%3D%22transparent%22%20color%3D%22transparent%22%5D%3B%0A%22L%5Cn20%22%20%5Bfontcolor%3D%22transparent%22%20color%3D%22transparent%22%5D%3B%0A%22I%5Cn42%22%20-%3E%20%22E%5Cn21%22%3B%0A%22E%5Cn21%22%20-%3E%20%22A%5Cn10%22%3B%0A%22E%5Cn21%22%20-%3E%20%22F%5Cn20%22%20%5Bcolor%3D%22transparent%22%5D%3B%0A%22I%5Cn42%22%20-%3E%20%22M%5Cn40%22%3B%0A%22M%5Cn40%22%20-%3E%20%22L%5Cn20%22%20%5Bcolor%3D%22transparent%22%5D%3B%0A%22M%5Cn40%22%20-%3E%20%22N%5Cn30%22%3B%0A%7D">

Its edge list is the following:

```
(I,42) -> (E,21)
(I,42) -> (M,40)
(E,21) -> (A,10)
(M,40) -> (N,30)
```

Create a file called ``2c.txt`` (case-sensitive) in the root directory of this repository (i.e., in the same folder as [``README.md``](README.md)) containing the edge list of the RST resulting from inserting ``(X,41)``.

### Task 2d: Create ``2d.txt`` (5 points)
Imagine we have the following RST, where nodes are ``(key,priority)`` tuples:

<img src="https://g.gravizo.com/svg?digraph%20G%20%7B%0A%22C%5Cn10%22%3B%0A%22F%5Cn20%22%20%20%5Bfontcolor%3D%22transparent%22%20color%3D%22transparent%22%5D%3B%0A%22I%5Cn42%22%20-%3E%20%22E%5Cn21%22%3B%0A%22E%5Cn21%22%20-%3E%20%22C%5Cn10%22%3B%0A%22E%5Cn21%22%20-%3E%20%22F%5Cn20%22%20%5Bcolor%3D%22transparent%22%5D%3B%0A%22I%5Cn42%22%20-%3E%20%22M%5Cn40%22%3B%0A%22M%5Cn40%22%20-%3E%20%22L%5Cn20%22%3B%0A%22M%5Cn40%22%20-%3E%20%22N%5Cn30%22%3B%0A%7D">

Its edge list is the following:

```
(I,42) -> (E,21)
(I,42) -> (M,40)
(E,21) -> (C,10)
(M,40) -> (L,20)
(M,40) -> (N,30)
```

Create a file called ``2d.txt`` (case-sensitive) in the root directory of this repository (i.e., in the same folder as [``README.md``](README.md)) containing a single ``(key,priority)`` tuple that, when inserted into this RST, will make the RST **perfectly balanced** and **will not cause any AVL rotations** during the insertion.

### Task 2e: Create ``2e.txt`` (5 points)
Imagine we have the following RST, where nodes are ``(key,priority)`` tuples:

<img src="https://g.gravizo.com/svg?digraph%20G%20%7B%0A%22C%5Cn10%22%3B%0A%22F%5Cn20%22%20%20%5Bfontcolor%3D%22transparent%22%20color%3D%22transparent%22%5D%3B%0A%22I%5Cn42%22%20-%3E%20%22E%5Cn21%22%3B%0A%22E%5Cn21%22%20-%3E%20%22C%5Cn10%22%3B%0A%22E%5Cn21%22%20-%3E%20%22F%5Cn20%22%20%5Bcolor%3D%22transparent%22%5D%3B%0A%22I%5Cn42%22%20-%3E%20%22M%5Cn40%22%3B%0A%22M%5Cn40%22%20-%3E%20%22L%5Cn20%22%3B%0A%22M%5Cn40%22%20-%3E%20%22N%5Cn30%22%3B%0A%7D">

Its edge list is the following:

```
(I,42) -> (E,21)
(I,42) -> (M,40)
(E,21) -> (C,10)
(M,40) -> (L,20)
(M,40) -> (N,30)
```

Create a file called ``2e.txt`` (case-sensitive) in the root directory of this repository (i.e., in the same folder as [``README.md``](README.md)) containing a single ``(key,priority)`` tuple that, when inserted into this RST, will make the RST **perfectly balanced** and will cause **exactly 2 AVL rotations** during the insertion.

## Part 3: AVL Trees (25 points)
We then introduced the [AVL Tree](https://en.wikipedia.org/wiki/AVL_tree), which is another self-balancing BST but with strict bounds on the "balance factor" (right height minus left height) of every node.

### Task: Edit [``BinaryTree.cpp``](BinaryTree.cpp) (25 points)
In this repository, there is a file called [``BinaryTree.cpp``](BinaryTree.cpp) that contains a basic implementation of a binary tree. Function headers (with usage details) are included in [``BinaryTree.h``](BinaryTree.h), and you need to fill in the ``balanceFactors()`` function of the ``BinaryTree`` class. We will not be checking for memory leaks, as we will be creating the dynamic objects, not you.

We have provided a tester program, [``BinaryTreeTest``](BinaryTreeTest.cpp), that will help you test your code. You can compile it as follows:

```bash
g++ -Wall -pedantic -g -O0 -std=c++11 -o BinaryTreeTest BinaryTreeTest.cpp BinaryTree.cpp
```

When run from the command line, it will print every node's balance factor to standard output, and it will print the tree (in the [Newick format](https://en.wikipedia.org/wiki/Newick_format)) to standard error. You can run the tester program and direct the balance factors to a file called ``balance_factors.tsv`` and the tree to a file called ``tree.nwk`` as follows:

```
$ g++ -Wall -pedantic -g -O0 -std=c++11 -o BinaryTreeTest BinaryTreeTest.cpp BinaryTree.cpp
$ ./BinaryTreeTest > balance_factors.tsv 2> tree.nwk
```

You can then open ``balance_factors.tsv`` in any text editor or spreadsheet viewer, and you can open ``tree.nwk`` in a tree viewing tool like [phylotree](http://phylotree.hyphy.org/).

## Part 4: Red-Black Trees (25 points)
The last self-balancing BST we discussed is the [Red-Black Tree](https://en.wikipedia.org/wiki/Red%E2%80%93black_tree). The Red-Black Tree is less strict with regard to balance than is the AVL Tree, but the Red-Black Tree is still guaranteed to be O(log *n*) in height.

### Task 4a: Create ``4a.txt`` (5 points)
Imagine we have the following Red-Black Tree:

<img src="https://g.gravizo.com/svg?digraph%20G%20%7B%0A10%20%5Bfontcolor%3D%22red%22%20color%3D%22red%22%5D%0A20%20%5Bfontcolor%3D%22red%22%20color%3D%22red%22%5D%0A30%20-%3E%2015%0A30%20-%3E%2070%0A15%20-%3E%2010%0A15%20-%3E%2020%0A%7D">

Its edge list is the following:

```
30 -> 15
30 -> 70
15 -> 10
15 -> 20
```

Create a file called ``4a.txt`` (case-sensitive) in the root directory of this repository (i.e., in the same folder as [``README.md``](README.md)) containing a single integer that, when inserted into this Red-Black Tree, will result in exactly **1 red node** after the insertion is complete.

### Task 4b: Create ``4b.txt`` (5 points)
Imagine we have the following Red-Black Tree:

<img src="https://g.gravizo.com/svg?digraph%20G%20%7B%0A10%20%5Bfontcolor%3D%22red%22%20color%3D%22red%22%5D%0A20%20%5Bfontcolor%3D%22red%22%20color%3D%22red%22%5D%0A30%20-%3E%2015%0A30%20-%3E%2070%0A15%20-%3E%2010%0A15%20-%3E%2020%0A%7D">

Its edge list is the following:

```
30 -> 15
30 -> 70
15 -> 10
15 -> 20
```

Create a file called ``4b.txt`` (case-sensitive) in the root directory of this repository (i.e., in the same folder as [``README.md``](README.md)) containing a single integer that, when inserted into this Red-Black Tree, will result in exactly **3 red nodes** after the insertion is complete.

### Task 4c: Create ``4c.txt`` (5 points)
Imagine we have the following Red-Black Tree:

<img src="https://g.gravizo.com/svg?digraph%20G%20%7B%0A15%0A70%20%5Bfontcolor%3D%22red%22%20color%3D%22red%22%5D%0A75%20%5Bfontcolor%3D%22transparent%22%20color%3D%22transparent%22%5D%3B%0A90%20%5Bfontcolor%3D%22red%22%20color%3D%22red%22%5D%0A30%20-%3E%2015%0A30%20-%3E%2070%0A70%20-%3E%2060%0A70%20-%3E%2080%0A80%20-%3E%2075%20%5Bcolor%3D%22transparent%22%5D%0A80%20-%3E%2090%0A%7D">

Its edge list is the following:

```
30 -> 15
30 -> 70
70 -> 60
70 -> 80
80 -> 90
```

Create a file called ``4c.txt`` (case-sensitive) in the root directory of this repository (i.e., in the same folder as [``README.md``](README.md)) containing a single integer that, when inserted into this Red-Black Tree, **will not cause any AVL rotations** during the insertion.

### Task 4d: Create ``4d.txt`` (5 points)
Imagine we have the following Red-Black Tree:

<img src="https://g.gravizo.com/svg?digraph%20G%20%7B%0A15%0A70%20%5Bfontcolor%3D%22red%22%20color%3D%22red%22%5D%0A75%20%5Bfontcolor%3D%22transparent%22%20color%3D%22transparent%22%5D%3B%0A90%20%5Bfontcolor%3D%22red%22%20color%3D%22red%22%5D%0A30%20-%3E%2015%0A30%20-%3E%2070%0A70%20-%3E%2060%0A70%20-%3E%2080%0A80%20-%3E%2075%20%5Bcolor%3D%22transparent%22%5D%0A80%20-%3E%2090%0A%7D">

Its edge list is the following:

```
30 -> 15
30 -> 70
70 -> 60
70 -> 80
80 -> 90
```

Create a file called ``4d.txt`` (case-sensitive) in the root directory of this repository (i.e., in the same folder as [``README.md``](README.md)) containing a single integer that, when inserted into this Red-Black Tree, will cause a **single rotation** during the insertion.

### Task 4e: Create ``4e.txt`` (5 points)
Imagine we have the following Red-Black Tree:

<img src="https://g.gravizo.com/svg?digraph%20G%20%7B%0A15%0A70%20%5Bfontcolor%3D%22red%22%20color%3D%22red%22%5D%0A75%20%5Bfontcolor%3D%22transparent%22%20color%3D%22transparent%22%5D%3B%0A90%20%5Bfontcolor%3D%22red%22%20color%3D%22red%22%5D%0A30%20-%3E%2015%0A30%20-%3E%2070%0A70%20-%3E%2060%0A70%20-%3E%2080%0A80%20-%3E%2075%20%5Bcolor%3D%22transparent%22%5D%0A80%20-%3E%2090%0A%7D">

Its edge list is the following:

```
30 -> 15
30 -> 70
70 -> 60
70 -> 80
80 -> 90
```

Create a file called ``4e.txt`` (case-sensitive) in the root directory of this repository (i.e., in the same folder as [``README.md``](README.md)) containing a single integer that, when inserted into this Red-Black Tree, will cause a **double rotation** during the insertion.

## Academic Integrity
This Programming Assignment (PA) must be completed 100% independently! You may only discuss the PA with the Tutors, TAs, and Instructors. You are free to use resources from the internet, but you are not allowed to blatantly copy-and-paste code. If you ever find yourself highlighting a code snippet, copying, and pasting into your PA, you are likely violating the Academic Integrity Policy. If you have any concerns or doubts regarding what you are about to do, *please* be sure to post on Piazza first to ask us if it is okay.

## Grading (100 points total)
* **Part 1: AVL Rotations**
    * 5 points for a correct ``1a.txt`` (0 points for incorrect)
    * 5 points for a correct ``1b.txt`` (0 points for incorrect)
    * 5 points for a correct ``1c.txt`` (0 points for incorrect)
    * 5 points for a correct ``1d.txt`` (0 points for incorrect)
    * 5 points for a correct ``1e.txt`` (0 points for incorrect)
* **Part 2: Treaps and Randomized Search Trees (RSTs)**
    * 5 points for a correct ``2a.txt`` (0 points for incorrect)
    * 5 points for a correct ``2b.txt`` (0 points for incorrect)
    * 5 points for a correct ``2c.txt`` (0 points for incorrect)
    * 5 points for a correct ``2d.txt`` (0 points for incorrect)
    * 5 points for a correct ``2e.txt`` (0 points for incorrect)
* **Part 3: AVL Trees**
    * 25 points for a completely correct solution
    * Partial credit for the proportion of nodes that were correct
* **Part 4: Red-Black Trees**
    * 5 points for a correct ``4a.txt`` (0 points for incorrect)
    * 5 points for a correct ``4b.txt`` (0 points for incorrect)
    * 5 points for a correct ``4c.txt`` (0 points for incorrect)
    * 5 points for a correct ``4d.txt`` (0 points for incorrect)
    * 5 points for a correct ``4e.txt`` (0 points for incorrect)
