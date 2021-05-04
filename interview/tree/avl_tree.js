console.log("-".repeat(80));
// this is bst, avl is not done.
// to make it avl tree
// for insersion travel from leaf to root and find inbalance in the height and balance it
// for delete travel from leaf to root and find inbalance in the height and balance it
// balance has four rotations
class Node {
  constructor(date) {
    this.data = date;
    this.left = null;
    this.right = null;
  }
}

class BST {
  constructor() {
    this.root = null;
  }

  // @param [Number] data
  insert(data) {
    const node = new Node(data);
    if (!this.root) {
      this.root = node;
    } else this.insertNode(node, this.root);
  }

  // @param [Node] node
  // @param [Node] parent
  //
  insertNode(node, parent) {
    if (parent.data > node.data) {
      parent.left === null
        ? (parent.left = node)
        : this.insertNode(node, parent.left);
    } else {
      parent.right === null
        ? (parent.right = node)
        : this.insertNode(node, parent.right);
    }
  }

  remove(data) {
    this.root = this.removeNode(this.root, data);
  }

  removeNode(parent, data) {
    // return parent
    if (!parent || !data) return parent;

    if (parent.data < data) {
      // right
      parent.right = this.removeNode(parent.right, data);
      return parent;
    } else if (parent.data > data) {
      // left
      parent.left = this.removeNode(parent.left, data);
      return parent;
    } else {
      // equal
      if (!parent.right && !parent.left) return null; // leaf
      if (parent.right && parent.left) {
        let min = this.findMinNode(parent.right); // find min of right
        parent.data = min.data;
        parent.right = this.removeNode(parent.right, min.data); // delete min
        return parent;
      }
      if (parent.right) return parent.right;
      if (parent.left) return parent.left;
    }
  }

  // Helper function
  findMinNode(node) {
    if (!node) return null;
    if (node.left) return this.findMinNode(node.left);
    else return node;
  }
  // getRootNode()
  // inorder(node)
  // preorder(node)
  // postorder(node)
  //
  //
  search(data) {
    return (this.searchNode(this.root, data) || {}).data || null;
  }
  searchNode(node, data) {
    if (!node) return null;
    if (node.data === data) return node;
    if (node.right && this.searchNode(node.right, data))
      return this.searchNode(node.right, data);
    if (node.left && this.searchNode(node.left, data))
      return this.searchNode(node.left, data);
    return null;
  }
}

const bst = new BST();

bst.insert(5);
bst.insert(7);
bst.insert(9);
bst.insert(3);
bst.insert(2);
bst.remove(5);
console.log(bst);
