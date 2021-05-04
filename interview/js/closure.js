var teacher = "Shubham";

function myTeacher() {
  console.log(teacher); // Preserving access to variable
}

teacher = "Shinde";

myTeacher(); // this should print Shinde

for (var i = 1; i <= 3; i++) {
  setTimeout(function() {
    console.log(i);
  }, i * 1000);
}

new Promise((resolve) =>
  setTimeout(() => {
    console.log("g");
    resolve(20);
  }, 2000)
).then(console.log);
