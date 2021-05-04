console.log("-".repeat(80));
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
    this.min = null;
    this.max = null;
  }

  getMin() {
    return this.min;
  }

  getMax() {
    return this.max;
  }

  // @param [Number] data
  insert(data) {
    const node = new Node(data);
    if (!this.root) {
      this.root = node;
    } else this.insertNode(node, this.root);
    if (data < this.min || !this.min) this.min = data;
    if (data > this.max || !this.max) this.max = data;
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
    this.min = this.findMinNode(this.root).data;
    this.max = this.findMaxNode(this.root).data;
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

  // Helper function
  findMaxNode(node) {
    if (!node) return null;
    if (node.right) return this.findMinNode(node.right);
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
bst.insert(3);
bst.insert(6);
bst.insert(2);
bst.insert(8);
bst.remove(8);
bst.remove(2);
console.log(bst.getMax(), bst.getMin());
