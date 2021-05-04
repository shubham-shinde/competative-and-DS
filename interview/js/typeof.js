// Numbers
console.log(typeof 37 === "number");
console.log(typeof 3.14 === "number");
console.log(typeof 42 === "number");
console.log(typeof Math.LN2 === "number");
console.log(typeof Infinity === "number");
console.log(typeof NaN === "number"); // Despite being "Not-A-Number"
console.log(typeof Number("1") === "number"); // Number tries to parse things into numbers
console.log(typeof Number("shoe") === "number"); // including values that cannot be type coerced to a number

console.log(typeof 42n === "bigint");

// Strings
console.log(typeof "" === "string");
console.log(typeof "bla" === "string");
console.log(typeof `template literal` === "string");
console.log(typeof "1" === "string"); // note that a number within a string is still typeof string
console.log(typeof typeof 1 === "string"); // typeof always returns a string
console.log(typeof String(1) === "string"); // String converts anything into a string, safer than toString

// Booleans
console.log(typeof true === "boolean");
console.log(typeof false === "boolean");
console.log(typeof Boolean(1) === "boolean"); // Boolean() will convert values based on if they're truthy or falsy
console.log(typeof !!1 === "boolean"); // two calls of the ! (logical NOT) operator are equivalent to Boolean()

// Symbols
console.log(typeof Symbol() === "symbol");
console.log(typeof Symbol("foo") === "symbol");
console.log(typeof Symbol.iterator === "symbol");

// Undefined
console.log(typeof undefined === "undefined");
console.log(typeof declaredButUndefinedVariable === "undefined");
console.log(typeof undeclaredVariable === "undefined");

// Objects
console.log(typeof { a: 1 } === "object");

// use Array.isArray or Object.prototype.toString.call
// to differentiate regular objects from arrays
console.log(typeof [1, 2, 4] === "object");

console.log(typeof new Date() === "object");
console.log(typeof /regex/ === "object"); // See Regular expressions section for historical results

// The following are confusing, dangerous, and wasteful. Avoid them.
console.log(typeof new Boolean(true) === "object");
console.log(typeof new Number(1) === "object");
console.log(typeof new String("abc") === "object");

// Functions
console.log(typeof function() {} === "function");
console.log(typeof class C {} === "function");
console.log(typeof Math.sin === "function");
