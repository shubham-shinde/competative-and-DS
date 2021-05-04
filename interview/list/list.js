class Element {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

class List {
  constructor() {
    this.head = null;
    this.last = null;
  }

  insert(data) {
    let element = new Element(data);
    if (!this.last) {
      this.head = element;
      this.last = element;
    } else this.last.next = element;
    this.last = element;
  }

  print() {
    let node = this.head;
    while (node) {
      console.log(node.data);
      node = node.next;
    }
  }
}

list = new List();
list.insert(2);
list.insert(5);
list.insert(7);
list.print();
