var teacher = "Shubham";

function otherClass() {
  var teacher = "Shinde";
  function ask(question) {
    console.log(teacher, question);
  }
  ask("Why");
}

console.log(teacher);
otherClass();
console.log(teacher);
ask("?????"); // this should throw ref error as globle scope don't have ask ref
