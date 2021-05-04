console.log("-".repeat(40));
EventEmitter = require("events").EventEmitter;
process.on("exit", () => console.log("Exit"));
process.on("beforeExit", (data) => console.log("Before Exit", data));
process.on("uncaughtException", () => {
  console.log("Exception");
  process.exit();
});

console.log(process.nextTick((a) => console.log("tick", a)));

console.log(process.eventNames());
throw new Error("Test Error");
