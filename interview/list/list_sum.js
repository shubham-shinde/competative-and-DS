console.log("-".repeat(40));
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
      process.stdout.write(node.data.toString());
      process.stdout.write(" -> ");
      node = node.next;
    }
    process.stdout.write("\n");
  }

  reverse() {
    let reverse_list = new List();
    reverse_list.last = this.assign_reverse(this.head, reverse_list);
    return reverse_list;
  }

  // @return Element
  assign_reverse(ele, list) {
    if (ele.next === null) {
      list.head = new Element(ele.data);
      return list.head;
    } else {
      let last_ele = this.assign_reverse(ele.next, list);
      last_ele.next = new Element(ele.data);
      return last_ele.next;
    }
  }

  add_list(list) {
    let t1 = list.reverse().head;
    let t2 = this.reverse().head;
    let rem = null;
    let sum_list = null;
    let t = null;
    while (t1 !== null || t2 !== null || rem !== null) {
      let ele = new Element(
        ((t1 || {}).data || 0) + ((t2 || {}).data || 0) + (rem || 0)
      );
      if (ele.data > 9) {
        ele.data = ele.data - 10;
        rem = 1;
      } else rem = null;

      if (t === null) {
        sum_list = new List();
        sum_list.head = ele;
        t = ele;
      } else {
        t.next = ele;
        t = t.next;
      }

      t1 = (t1 || {}).next || null;
      t2 = (t2 || {}).next || null;
    }
    return sum_list.reverse();
  }
}

list1 = new List();
list1.insert(9);
list1.insert(5);
list1.insert(7);
list1.insert(0);
list1.print();

list2 = new List();
list2.insert(2);
list2.insert(9);
list2.insert(7);
list2.insert(0);
list2.insert(0);
list2.print();
let list3 = list2.add_list(list1);
list3.print();
