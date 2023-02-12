package oop.jgarcia.hw6.one;


import java.util.*;


/**
 * Implements a binary search tree with generic data
 * @author Julian Garcia
 * @version HW 6, #1
 */
public class BinarySearchTree<E>{

    /**
     * Nodes of BST
     */
    private class Node {
        private E data;
        private Node left;
        private Node right;

        private Node(E data, Node left, Node right){
            this.data = data;
            this.left = left;
            this.right = right;
        }

    }

    private E data;
    private Node root;
    private int size = 0;
    private Comparator<E> comparator;

    /**
     * Sets up binary search tree, sets root to null and establishes comparator
     */
    public BinarySearchTree(Comparator<E> comparator){
        this.root = null;
        this.size = 0;

        this.comparator = comparator;

    }

    /**
     * Simple getter for size of BST
     * @return size of BST
     */
    public int getSize() {
        return size;
    }

    /**
     * Adds a new node to the BST
     * @return void
     */
    public void add(E data) {
        if (this.root == null) {
           this.root = new Node(data, null, null);
        } else {
            //Locate Parent
            Node parent = null;
            Node current = this.root;
            while (current != null) {
                if (this.comparator.compare(data, current.data) < 0) {
                    parent = current;
                    current = current.left;
                } else if (this.comparator.compare(data, current.data) > 0) {
                    parent = current;
                    current = current.right;
                } else {
                    System.out.println("Duplicate node not inserted");
                    return;
                }
            }
            if (this.comparator.compare(data, parent.data) < 0) {
                parent.left = new Node(data, null, null);
            } else {
                parent.right = new Node(data, null, null);
            }
        }
        this.size = this.size + 1;
        System.out.println("Node Inserted Correctly");
    }

    /**
     * Removes a node from BST
     * @param data data of the node to be deleted
     * @return void
     */
    public void remove(E data) {
        Node parent = null;
        Node current = this.root;
        while (current != null) {
            if (this.comparator.compare(data, current.data) < 0) {
                parent = current;
                current = current.left;
            } else if (this.comparator.compare(data, current.data) > 0) {
                parent = current;
                current = current.right;
            } else {
                break;
            }
        }
        if (current == null) {
            System.out.println("Node not in tree");
            return;
        }
        // Current doesn't have left child
        if (current.left == null) {
            if (parent == null) {
                this.root = current.right;
            }
            else {
                if (comparator.compare(data, parent.data) < 0) {
                    parent.left = current.right;
                } else {
                    parent.right = current.right;
                }
            }
        }
        else {
            // Current node has a left child
            Node parentMaxRight = current;
            Node maxRight = current.left;

            while (maxRight.right != null) {
                parentMaxRight = maxRight;
                maxRight = maxRight.right;
            }
            current.data = maxRight.data;

            if (parentMaxRight.right == maxRight) {
                parentMaxRight.right = maxRight.left;
            } else {
                parentMaxRight.left = maxRight.left;
            }
        }
        this.size = this.size - 1;
        System.out.println("Node successfully deleted");
    }

    /**
     * Finds a node in the BST
     * @param data data of the node to be found
     * @return true or false depending on if node is found
     */
    public boolean find(E data) {
        Node current = this.root;
        while (current != null) {
            if  (this.comparator.compare(data, current.data) < 0) {
                current = current.left;
            } else if (this.comparator.compare(data, current.data) > 0) {
                current = current.right;
            } else {
                System.out.println("Node has been found");
                return true;
            }
        }
        System.out.println("Node has NOT been found");
        return false;
    }

    /**
     * Finds the minimum node of BST
     * @return data of minimun node
     */
    public E findMin() {
        Node parent = null;
        Node current = this.root;
        while (current != null) {
            parent = current;
            current = current.left;
        }
        return parent.data;
    }

    /**
     * Finds largest right node of BST
     * @return data of largest right node
     */
    public E findMax() {
        Node parent = null;
        Node current = this.root;
        while (current != null) {
            parent = current;
            current = current.right;
        }
        return parent.data;
    }

    /**
     * Determines if BST is empty
     * @return true if empty, false if not
     */
    public boolean isEmpty() {
        Node current = this.root;
        if (current == null) {
            return true;
        }
        return false;
    }

    /**
     * Clears BST
     * @return void
     */
    public void clear() {
        root = null;
        size = 0;
    }

    /**
     * Adds nodes using an arraylist
     * @param list ArrayList to be added to BST
     * @return void
     */
    public void addAll(ArrayList<E> list) {
        for (int i = 0; i < list.size(); i++) {
            System.out.println(list.get(i));
            add(list.get(i));
        }
    }

    /**
     * Prints nodes of BST in specified order, calls other methods in order to do so
     * @param travis order to be followed while printing
     * @return void
     */
    public void print(Traversal travis) {
        if (travis == Traversal.INORDER) {
            inorder(this.root);
        } else if (travis == Traversal.POSTORDER) {
            postOrder(this.root);
        } else if (travis == Traversal.PREORDER) {
            preOrder(this.root);
        }
    }

    /**
     * Prints nodes of BST in inorder fashion
     * @param root root of BST
     * @return void
     */
    public void inorder(Node root) {
        if (root == null) {
            return;
        }
        inorder(root.left);
        System.out.println(root.data);
        inorder(root.right);
    }

    /**
     * Prints nodes of BST in Postorder fashion
     * @param root root of BST
     * @return void
     */
    public void postOrder(Node root) {
        if (root == null) {
            return;
        }
        postOrder(root.left);
        postOrder(root.right);
        System.out.println(root.data);
    }

    /**
     * Prints nodes of BST in Preorder fashion
     * @param root root of BST
     * @return void
     */
    public void preOrder(Node root) {
        if (root == null) {
            return;
        }
        System.out.println(root.data);
        preOrder(root.left);
        preOrder(root.right);
    }



}
