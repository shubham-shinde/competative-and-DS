console.log("-".repeat(40));

class Node {
  constructor(from, to) {
    this.from = from;
    this.to = to;
    this.open = null;
    this.close = null;
    this.matched = null;
    this.left = null;
    this.right = null;
  }
}

class SegmentTree {
  constructor(list) {
    this.root = null;
    this.list = list;
    this.create();
  }

  createNode(from, to) {
    let node = new Node(from, to);
    if (from === to) {
      node.matched = 0;
      if (this.list[from] === ")") {
        node.close = 1;
        node.open = 0;
      } else {
        node.open = 1;
        node.close = 0;
      }
      return node;
    }
    let mid = Math.floor((from + to) / 2);
    node.right = this.createNode(mid + 1, to);
    node.left = this.createNode(from, mid);
    node.matched = node.right.matched + node.left.matched;
    let min = Math.min(node.left.open, node.right.close);
    node.matched += min;
    node.open = node.left.open - min + node.right.open;
    node.close = node.right.close - min + node.left.close;
    return node;
  }

  create() {
    this.root = this.createNode(0, this.list.length - 1);
  }

  matched_node(parent, from, to) {
    if (parent === null) return 0;
    from = Math.max(from, parent.from);
    to = Math.min(to, parent.to);
    if (parent.from === from && parent.to === to) {
      return [parent.matched, parent.open, parent.close];
    }
    let left_match = null;
    let right_match = null;
    let mid = Math.floor((parent.from + parent.to) / 2);
    if (from <= mid) {
      left_match = this.matched_node(parent.left, from, Math.min(mid, to));
    }
    if (to > mid) {
      right_match = this.matched_node(
        parent.right,
        Math.max(mid + 1, from),
        to
      );
    }
    let matched = 0,
      open = 0,
      close = 0;
    if (right_match) matched += right_match[0];
    if (left_match) matched += left_match[0];
    if (right_match && left_match) {
      let min = Math.min(right_match[2], left_match[1]);
      matched += min;
      right_match[2] -= min;
      left_match[1] -= min;
    }
    if (right_match) open = right_match[1];
    if (left_match) open = left_match[2];
    return [matched, open, close];
  }

  logest_match(from, to) {
    return this.matched_node(this.root, from, to)[0] * 2;
  }
}

tree = new SegmentTree("())(())(())(");
console.log(tree.logest_match(0, 11));
console.log(tree.logest_match(1, 2));
