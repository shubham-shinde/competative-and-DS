console.log("-".repeat(40));

class BIT {
  constructor(arr) {
    this.bit = new Array(arr.length).fill(0);
    for (let i = 1; i <= arr.length; i++) this.update(i, arr[i - 1]);
  }

  update(index, value) {
    while (index <= this.bit.length) {
      this.bit[index - 1] += value;
      index += this.lsb(index);
    }
  }

  sum_range(start, end) {
    let min = start > 1 ? this.sum_from_big(start - 1) : 0;
    return this.sum_from_big(end) - min;
  }

  sum_from_big(index) {
    let sum = 0;
    index = index > this.bit.length ? this.bit.length : index;
    while (index > 0) {
      sum += this.bit[index - 1];
      index -= this.lsb(index);
    }
    return sum;
  }

  lsb(number) {
    return number & -number;
  }
}

const arr = [3, 4, -2, 7, 3, 11, 5, -8, -9, 2, 4, -8];
let bit = new BIT(arr);
console.log(bit.sum_range(-1, 20));
