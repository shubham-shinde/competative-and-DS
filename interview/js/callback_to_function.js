const f = (firstName, callback) => {
  setTimeout(() => {
    if (!firstName) return callback(new Error("firstName is required"));
    const fullName = `${firstName} Turing`;
    return callback(fullName);
  }, 2000);
};

// f("Alan", console.log);
// f(null, console.log);
//
// const pro_f = async (firstName) => {
//   await new Promise((resolve) => setTimeout(resolve, 2000));
//   if (!firstName) throw new Error("firstName is required");
//   const fullName = `${firstName} Turing`;
//   return fullName;
// };

// pro_f("Alan").then(console.log);
// pro_f(null)
//   .then(console.log)
//   .catch(console.log);
//
const pro_f = (firstName) => {
  return new Promise((resolve) => {
    setTimeout(() => {
      if (!firstName) return resolve(new Error("firstName is required"));
      const fullName = `${firstName} Turing`;
      return resolve(fullName);
    }, 2000);
  });
};

pro_f("Alan").then(console.log);
pro_f(null)
  .then(console.log)
  .catch(console.log);
