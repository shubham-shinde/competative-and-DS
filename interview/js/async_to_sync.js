console.log("-".repeat(40));
promise = new Promise((resolve) => {
  setTimeout(() => resolve("promise resolved"), 2000);
});

result = promise.Result;
console.log(result);

console.log("hello world");
